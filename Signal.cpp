#include <iostream>
#include "Signal.hpp"
std::ostream &operator<<(std::ostream &out, const Signal &s)
{
    if (s == Signal::off)
    {
        out << "off";
    }
    else if (s == Signal::on)
    {
        out << "on";
    }
    else
    {
        out << "ud";
    }
    return out;
}