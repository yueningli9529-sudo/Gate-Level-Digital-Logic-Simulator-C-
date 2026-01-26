#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP
#include "Gate.hpp"
#include "Wire.hpp"
#include <vector>
#include <memory>
#include <utility>

class Circuit
{
public:
    Circuit();
    Wire *add_wire(Signal i = Signal::ud);
    // Returns true iff any gate update changes the circuit state this step.
    bool step();
    void run_until_stable();
    template <class GateType, class... Args>
    void emplace_gate(Args &&...args)
    {
        gates.push_back(std::unique_ptr<Gate>(
            new GateType(std::forward<Args>(args)...)));
    }

private:
    std::vector<std::unique_ptr<Gate>> gates;
    std::vector<std::unique_ptr<Wire>> wires;
    // Wire 由 Circuit 拥有，返回的 Wire* 在 Circuit 生命周期内有效。
    // Gate 不拥有 Wire，只是引用它们。
};
#endif