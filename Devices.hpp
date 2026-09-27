#ifndef DEVICES_HPP
#define DEVICES_HPP

#include <string>
#include <chrono>
#include <random>
#include <format>
#include "Values.hpp"


namespace Devices {

    template <typename T>
    class Measurement {
    private:
        T value;
        T error;
        std::chrono::system_clock::time_point time;

    public:
        Measurement(std::chrono::system_clock::time_point t, T val, T err) 
            : value(val), error(err), time(t) {}

        T GetValue() const { return value; }
        T GetError() const { return error; }
        std::chrono::system_clock::time_point GetTime() const { return time; }
    };

    class Ammeter {
    private:
        double min_range;
        double max_range;
        double accuracy;
        std::string identifier;

    public:
        Ammeter(double min_r, double max_r, double acc, std::string id);
        Measurement<Values::Ampere> Measure() const;
    };

    class Voltmeter {
    private:
        double min_range;
        double max_range;
        double accuracy;
        std::string identifier;

    public:
        Voltmeter(double min_r, double max_r, double acc, std::string id);
        Measurement<Values::Volt> Measure() const;
    };

    class Multimeter {
    private:
        double min_range;
        double max_range;
        double accuracy;
        std::string identifier;

    public:
        Multimeter(double min_r, double max_r, double acc, std::string id);

        template <typename T>
        Measurement<T> Measure() const {
            auto now = std::chrono::system_clock::now();

            static std::random_device rd;
            static std::mt19937 gen(rd());
            std::uniform_real_distribution<double> dist(min_range, max_range);
            double random_val = dist(gen);

            double abs_error = max_range * (accuracy / 100.0);

            return Measurement<T>(now, T(random_val), T(abs_error));
        }
    };

}


template <typename T>
struct std::formatter<Devices::Measurement<T>> {
    constexpr auto parse(std::format_parse_context& ctx) {
        return ctx.begin();
    }

    template <typename FormatContext>
    auto format(const Devices::Measurement<T>& m, FormatContext& ctx) const {
        auto time_sec = std::chrono::floor<std::chrono::seconds>(m.GetTime());

        return std::format_to(
            ctx.out(),
            "[{:%Y-%m-%d %H:%M:%S}] Value: {} +/- {}",
            time_sec,
            m.GetValue().GetValue(),
            m.GetError().GetValue()
        );
    }
};


#endif