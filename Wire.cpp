#include "Wire.hpp"

Wire::Wire(Signal p) : signal(p)
{
}

Signal Wire::get() const
{
    return signal;
}

bool Wire::set(Signal s)
{
    if (signal != s)
    {
        signal = s;
        return true;
    }
    return false;
}
