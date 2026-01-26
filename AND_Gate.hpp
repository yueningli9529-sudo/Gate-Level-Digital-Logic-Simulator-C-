#ifndef AND_GATE_HPP
#define AND_GATE_HPP
#include "Gate.hpp"
#include "Wire.hpp"

class AND_Gate : public Gate
{
public:
    // Precondition: signal_1, signal_2, signal_3 are non-null.
    // Gate does not own wires; it only references them.
    AND_Gate(const Wire *signal_1, const Wire *signal_2, Wire *signal_3);
    bool update() override;

private:
    const Wire *input_1; // input port (read-only)
    const Wire *input_2; // input port (read-only)
    Wire *output;        // output port (write access)
};
#endif