#include "Circuit.hpp"
#include <iostream>

Circuit::Circuit()
{
    gates.reserve(10);
    wires.reserve(20);
}

Wire *Circuit::add_wire(Signal i)
{
    wires.push_back(std::unique_ptr<Wire>(new Wire(i)));
    return wires.back().get();
}

bool Circuit::step()
{
    bool changed = false;
    for (const std::unique_ptr<Gate> &i : gates) // 一定要引用啊
    {
        changed |= i->update();
    }
    return changed;
}

void Circuit::run_until_stable()
{
    int count = 0;
    int max = 1000;
    while (step() && count < max)
    {
        count++;
    }
    if (count == max)
    {
        std::cerr << "Warning: circuit did not stabilize after "
                  << max << " iterations\n";
    }
}
