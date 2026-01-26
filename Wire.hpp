#ifndef WIRE_HPP
#define WIRE_HPP
#include "Signal.hpp"

class Wire
{
public:
    Wire(Signal s = Signal::ud);
    Signal get() const;
    bool set(Signal s);

private:
    Signal signal;
};
#endif