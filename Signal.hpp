#ifndef SIGNAL_HPP
#define SIGNAL_HPP
#include <iosfwd>
enum class Signal
{
    off,
    on,
    ud
};
std::ostream &operator<<(std::ostream &out, const Signal &s);
#endif