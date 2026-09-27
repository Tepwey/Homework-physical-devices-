#ifndef OPERATORS_HPP
#define OPERATORS_HPP
#include "Values.hpp"

namespace Values {


    Volt operator*(const Ampere& a, const Ohm& ohm);
    Volt operator*(const Ohm& ohm, const Ampere& a);

    Ohm operator/(const Volt& v, const Ampere& a);

    Ampere operator/(const Volt& v, const Ohm& ohm);

    Watt operator*(const Volt& v, const Ampere& a);
    Watt operator*(const Ampere& a, const Volt& v);
    Watt operator/(const Joule& j, const Second& s);

    Joule operator*(const Watt& w, const Second& s);

    Second operator/(const Joule& j, const Watt& w);



    Ampere operator"" _mA(long double val);
    Ampere operator"" _mA(unsigned long long val);

    Volt operator"" _V(long double val);
    Volt operator"" _V(unsigned long long val);

    Ohm operator"" _Ohm(long double val);
    Ohm operator"" _Ohm(unsigned long long val);

    Joule operator"" _J(long double val);
    Joule operator"" _J(unsigned long long val);

    Watt operator"" _W(long double val);
    Watt operator"" _W(unsigned long long val);

    Second operator"" _s(long double val);
    Second operator"" _s(unsigned long long val);

}

#endif