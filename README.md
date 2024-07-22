# RISCV Processor
RISCV processor with incremental features added from the base 5 stage pipeline model with hazard unit.

## Setup
* verilator
* riscv-gnu-toolchain
* GTKwave
* RARS (https://github.com/TheThirdOne/rars)
* java (for running RARS)
* perl 5

## finished features
- 5 stage pipeline
- hazard unit (RAW, lw, branch)
- connect with RARS simulator
- UVM standard implementation from scratch in C++
- pipeline to compile using GCC toolchain to run on CPU

## features TODO
- branch prediction unit
- vector processing unit (RISCV V - instr extension)
- superscalar
- out-of-order execution 

## extra stuff
- run on Coremark benchmark
- Formal verification 
