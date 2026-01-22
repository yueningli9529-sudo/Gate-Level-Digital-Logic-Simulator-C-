# Gate-Level Digital Logic Simulator (C++)

A simple gate-level digital logic circuit simulator written in C++.
Supports three-valued signals: `OFF`, `ON`, `UD` (unknown).

## Features
- Basic gates: AND / OR / NOT / XOR (WIP)
- Wire-based signal connections (WIP)
- Signal propagation (WIP)

## Build & Run
```bash
g++ -std=c++17 -Iinclude src/*.cpp -o sim
./sim
