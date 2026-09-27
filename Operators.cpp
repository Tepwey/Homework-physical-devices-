#include "Operators.hpp"

namespace Values {

    Volt operator*(const Ampere& a, const Ohm& ohm) {
        return Volt(a.GetValue() * ohm.GetValue());
    }
    Volt operator*(const Ohm& ohm, const Ampere& a) {
        return Volt(ohm.GetValue() * a.GetValue());
    }


    Ohm operator/(const Volt& v, const Ampere& a) {
        return Ohm(v.GetValue() / a.GetValue());
    }


    Ampere operator/(const Volt& v, const Ohm& ohm) {
        return Ampere(v.GetValue() / ohm.GetValue());
    }


    Watt operator*(const Volt& v, const Ampere& a) {
        return Watt(v.GetValue() * a.GetValue());
    }
    Watt operator*(const Ampere& a, const Volt& v) {
        return Watt(a.GetValue() * v.GetValue());
    }
    Watt operator/(const Joule& j, const Second& s) {
        return Watt(j.GetValue() / s.GetValue());
    }


    Joule operator*(const Watt& w, const Second& s) {
        return Joule(w.GetValue() * s.GetValue());
    }


    Second operator/(const Joule& j, const Watt& w) {
        return Second(j.GetValue() / w.GetValue());
    }



    Ampere operator"" _mA(long double val) { return Ampere(val / 1000.0); }
    Ampere operator"" _mA(unsigned long long val) { return Ampere(val / 1000.0); }

    Volt operator"" _V(long double val) { return Volt(val); }
    Volt operator"" _V(unsigned long long val) { return Volt(val); }

    Ohm operator"" _Ohm(long double val) { return Ohm(val); }
    Ohm operator"" _Ohm(unsigned long long val) { return Ohm(val); }

    Joule operator"" _J(long double val) { return Joule(val); }
    Joule operator"" _J(unsigned long long val) { return Joule(val); }

    Watt operator"" _W(long double val) { return Watt(val); }
    Watt operator"" _W(unsigned long long val) { return Watt(val); }

    Second operator"" _s(long double val) { return Second(val); }
    Second operator"" _s(unsigned long long val) { return Second(val); }

}