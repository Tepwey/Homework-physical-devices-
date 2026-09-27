#ifndef VALUES_HPP
#define VALUES_HPP
#include <stdexcept>

namespace Values {

    class Ampere {
    private:
        double value;
    public:
        Ampere();
        explicit Ampere(double a);
        double GetValue() const;
        void SetValue(double val);
    };

    class Volt {
    private:
        double value;
    public:
        Volt();
        explicit Volt(double v);
        double GetValue() const;
        void SetValue(double val);
    };

    class Ohm {
    private:
        double value;
    public:
        Ohm();
        explicit Ohm(double ohm);
        double GetValue() const;
        void SetValue(double val);
    };

    class Joule {
    private:
        double value;
    public:
        Joule();
        explicit Joule(double j);
        double GetValue() const;
        void SetValue(double val);
    };

    class Watt {
    private:
        double value;
    public:
        Watt();
        explicit Watt(double w);
        double GetValue() const;
        void SetValue(double val);
    };

    class Second {
    private:
        double value;
    public:
        Second();
        explicit Second(double s);
        double GetValue() const;
        void SetValue(double val);
    };

}

#endif