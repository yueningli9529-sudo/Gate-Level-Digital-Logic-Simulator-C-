# 🧠 Digital Circuit Simulation System (C++)

A lightweight digital circuit simulator written in modern C++, designed with clear interfaces and strong separation of concerns.

The system models digital circuits using wires and logic gates, and supports iterative simulation until the circuit reaches a stable state.

---

## ✨ Features

- Modular gate design  
  New gate types (AND, OR, NOT, etc.) can be added without modifying existing core code
- Clear interface contracts  
  Gate, Wire, and Circuit are cleanly separated
- Safe memory management  
  Uses std::unique_ptr and RAII
- Stable-state simulation  
  Automatically iterates until the circuit stabilizes
- Minimal dependencies  
  No external libraries required

---

## 🧩 Architecture Overview

The system follows a clear layered structure: **Signal → Wire → Gate → Circuit**.

Signal represents logic states (`on`, `off`, `ud`).  
Wire stores and propagates signals.  
Gate defines logic behavior through a single update interface.  
Circuit owns all wires and gates and repeatedly updates them until the system stabilizes.

Each layer depends only on the layer below it, enabling low coupling and easy extensibility.

---

## 🔌 Adding a New Gate

To add a new gate type, only two files are needed:

```
XXX_Gate.hpp
XXX_Gate.cpp
```

Steps:
1. Inherit from `Gate`
2. Implement the `update()` method
3. Use `Wire::get()` and `Wire::set()` to read/write signals

No changes to `Circuit`, `Wire`, or existing gates are required.

---

## ▶️ Example Usage

```cpp
#include "Circuit.hpp"
#include "AND_Gate.hpp"
#include <iostream>

int main()
{
    Circuit circuit;

    Wire* a = circuit.add_wire(Signal::on);
    Wire* b = circuit.add_wire(Signal::on);
    Wire* out = circuit.add_wire(Signal::ud);

    circuit.emplace_gate<AND_Gate>(a, b, out);

    circuit.run_until_stable();
    std::cout << out->get() << std::endl; // on
}
```

## 🛠 Build & Run

All source files are located in the same directory.
```
g++ -std=c++17 -Wall -Wextra -pedantic \
    main.cpp Signal.cpp Wire.cpp AND_Gate.cpp Circuit.cpp \
    -o circuit
```

Run:
```
./circuit
```

---


## 📁 File Structure
```
.
├── AND_Gate.hpp
├── AND_Gate.cpp
├── Circuit.hpp
├── Circuit.cpp
├── Gate.hpp
├── Signal.hpp
├── Signal.cpp
├── Wire.hpp
├── Wire.cpp
└── main.cpp
```

---

## 🎯 Design Goals

- Emphasize interface-driven design
- Minimize coupling between components
- Make extension easier than modification
- Keep the system small, readable, and testable

---

## 🚀 Future Work

- Additional gate types (OR, NOT, XOR)
- Clocked or synchronous simulation
- Signal tracing or debugging output
- Unit tests

---

## 🧑‍💻 Author

Built as a C++ systems design exercise focusing on interfaces, ownership, and simulation logic.
