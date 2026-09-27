#include "Devices.hpp"
#include <stdexcept>

namespace Devices {

    Ammeter::Ammeter(double min_r, double max_r, double acc, std::string id) {
        if (min_r >= max_r) {
            throw std::invalid_argument("Min_range cannot be lower or equal to max_range!");
        }
        if (acc <= 0) {
            throw std::invalid_argument("Accuracy cannot be lower or equal to zero!");
        }
        min_range = min_r;
        max_range = max_r;
        accuracy = acc;
        identifier = std::move(id);
    }

    Measurement<Values::Ampere> Ammeter::Measure() const {
        auto now = std::chrono::system_clock::now();

        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(min_range, max_range);
        double random_val = dist(gen);

        double abs_error = max_range * (accuracy / 100.0);

        return Measurement<Values::Ampere>(now, Values::Ampere(random_val), Values::Ampere(abs_error));
    }



    Voltmeter::Voltmeter(double min_r, double max_r, double acc, std::string id) {
        if (min_r >= max_r) {
            throw std::invalid_argument("Min_range cannot be lower or equal to max_range!");
        }
        if (acc <= 0) {
            throw std::invalid_argument("Accuracy cannot be lower or equal to zero!");
        }

        min_range = min_r;
        max_range = max_r;
        accuracy = acc;
        identifier = std::move(id);
    }

    Measurement<Values::Volt> Voltmeter::Measure() const {
        auto now = std::chrono::system_clock::now();

        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dist(min_range, max_range);
        double random_val = dist(gen);

        double abs_error = max_range * (accuracy / 100.0);

        return Measurement<Values::Volt>(now, Values::Volt(random_val), Values::Volt(abs_error));
    }



    Multimeter::Multimeter(double min_r, double max_r, double acc, std::string id) {
        if (min_r >= max_r) {
            throw std::invalid_argument("Min_range cannot be lower or equal to max_range!");
        }
        if (acc <= 0) {
            throw std::invalid_argument("Accuracy cannot be lower or equal to zero!");
        }

        min_range = min_r;
        max_range = max_r;
        accuracy = acc;
        identifier = std::move(id);
    }

}