#include "Circuit.hpp"
#include "AND_Gate.hpp"
#include <iostream>
int main()
{
    Circuit circuit;

    Wire *wire_1 = circuit.add_wire(Signal::on);
    Wire *wire_2 = circuit.add_wire(Signal::on);
    Wire *wire_3 = circuit.add_wire(Signal::ud);

    circuit.emplace_gate<AND_Gate>(wire_1, wire_2, wire_3);

    circuit.run_until_stable();
    std::cout << wire_3->get() << std::endl;
}

/*
g++ -std=c++17 -Wall -Wextra -pedantic \
    main.cpp \
    Signal.cpp \
    Wire.cpp \
    AND_Gate.cpp \
    Circuit.cpp \
    -o circuit
*/
// ./circuit