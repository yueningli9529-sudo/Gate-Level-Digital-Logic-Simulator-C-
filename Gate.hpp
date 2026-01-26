#ifndef GATE_HPP
#define GATE_HPP

class Gate
{
public:
    // Returns true iff this call changes any output wire value.
    virtual bool update() = 0;
    virtual ~Gate() = default;
};
#endif