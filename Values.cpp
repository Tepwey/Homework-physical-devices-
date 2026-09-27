#include "Values.hpp"

namespace Values {


    Ampere::Ampere() : value(0.0) {}
    Ampere::Ampere(double a) : value(a) {
        if (a < 0) throw std::invalid_argument("Ampere couldn`t be lower than 0!");
    }
    double Ampere::GetValue() const { return value; }
    void Ampere::SetValue(double val) {
        if (val < 0) throw std::invalid_argument("Ampere couldn`t be lower than 0!");
        value = val;
    }


    Volt::Volt() : value(0.0) {}
    Volt::Volt(double v) : value(v) {
        if (v < 0) throw std::invalid_argument("Volt couldn`t be lower than 0!");
    }
    double Volt::GetValue() const { return value; }
    void Volt::SetValue(double val) {
        if (val < 0) throw std::invalid_argument("Volt couldn`t be lower than 0!");
        value = val;
    }


    Ohm::Ohm() : value(0.0) {}
    Ohm::Ohm(double ohm) : value(ohm) {
        if (ohm < 0) throw std::invalid_argument("Ohm couldn`t be lower than 0!");
    }
    double Ohm::GetValue() const { return value; }
    void Ohm::SetValue(double val) {
        if (val < 0) throw std::invalid_argument("Ohm couldn`t be lower than 0!");
        value = val;
    }


    Joule::Joule() : value(0.0) {}
    Joule::Joule(double j) : value(j) {
        if (j < 0) throw std::invalid_argument("Joule couldn`t be lower than 0!");
    }
    double Joule::GetValue() const { return value; }
    void Joule::SetValue(double val) {
        if (val < 0) throw std::invalid_argument("Joule couldn`t be lower than 0!");
        value = val;
    }


    Watt::Watt() : value(0.0) {}
    Watt::Watt(double w) : value(w) {
        if (w < 0) throw std::invalid_argument("Watt couldn`t be lower than 0!");
    }
    double Watt::GetValue() const { return value; }
    void Watt::SetValue(double val) {
        if (val < 0) throw std::invalid_argument("Watt couldn`t be lower than 0!");
        value = val;
    }


    Second::Second() : value(0.0) {}
    Second::Second(double s) : value(s) {
        if (s < 0) throw std::invalid_argument("Second couldn`t be lower than 0!");
    }
    double Second::GetValue() const { return value; }
    void Second::SetValue(double val) {
        if (val < 0) throw std::invalid_argument("Second couldn`t be lower than 0!");
        value = val;
    }

    
}