
#include <string>
#include <iostream>
#include <fstream>

// #include <verilated.h>
// #include <verilated_vcd_c.h>
// #include "Vtest.h"
// #include "Vtest__Syms.h"

#include "data_hazard_gen.hpp"

#define MAX_SIM_TIME 300

vluint64_t sim_time = 0;

// void dut_reset (Vtest * dut, VerilatedVcdC *m_trace, vluint64_t &sim_time){
//     dut->reset = 1;
//     dut->clk = 1;
//     dut->eval();
//     m_trace->dump(sim_time);
//     sim_time++;
//     dut->clk = 0;
//     dut->eval();
//     m_trace->dump(sim_time);
//     sim_time++;
//     dut->reset = 0;
// }

int main() {
    std::unordered_set<uint8_t> allowedRegisters = {
    0,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    31
};
    std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps = {
    RTypeInstr::RTypeOps::ADD,
    RTypeInstr::RTypeOps::SUB,
    // RTypeInstr::RTypeOps::XOR,
    // RTypeInstr::RTypeOps::OR,
    // RTypeInstr::RTypeOps::AND
};
    std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps = {
    ITypeInstr::ITypeOps::ADDI,
    // ITypeInstr::ITypeOps::XORI,
    // ITypeInstr::ITypeOps::ANDI,
    // ITypeInstr::ITypeOps::SLLI,
    // ITypeInstr::ITypeOps::SRLI,
};

    DataHazardRiscvSequencer sequencer(allowedRegisters, allowedRTypeOps, allowedITypeOps);

    // sequencer.propagateInstructions(10);

    RiscvInTx tt = sequencer.generateDataHazardRandomInstructions(10);

    for (const auto& instr : tt.instructions) {
        std::cout << "Test 0x " << instr->toString() << std::endl;
    }
    // Generate a specified number of random instructions
    // size_t instructionCount = 10;
    // auto save = sequencer.generateDataHazardRandomInstructions(instructionCount);

    // // Print the generated random instructions

    return 0;
}
// int main(int argc, char **argv, char **env) {
//     std::cout << "tb_rtl.cpp" << std::endl;

//     // Initialize Verilator's command line arguments
//     Verilated::commandArgs(argc, argv);

//     // Create an instance of the DUT
//     Vtest *dut = new Vtest;

//     // Enable VCD tracing
//     Verilated::traceEverOn(true);
//     VerilatedVcdC *m_trace = new VerilatedVcdC;
//     dut->trace(m_trace, 5);
//     m_trace->open("waveform_rtl_test.vcd");

//     // Initial reset
//     dut->reset = 1;
//     dut->clk = 0;
//     dut->eval();
//     m_trace->dump(sim_time);

//     // De-assert reset after a few cycles
//     for (int i = 0; i < 5; i++) {
//         sim_time++;
//         dut->clk = !dut->clk;
//         dut->eval();
//         m_trace->dump(sim_time);
//     }
//     dut->reset = 0;

//     // Simulation loop
//     while (sim_time < MAX_SIM_TIME) {
//         // Toggle clock
//         dut->clk = !dut->clk;
//         sim_time++;

//         // Apply test vectors
//         if (sim_time == 10) {
//             dut->in_a = 0x3f800000; // 1.0 in IEEE 754
//             dut->in_b = 0x40000000; // 2.0 in IEEE 754
//         } else if (sim_time == 20) {
//             dut->in_a = 0x40400000; // 3.0 in IEEE 754
//             dut->in_b = 0x40800000; // 4.0 in IEEE 754
//         }
//         // Additional test cases can be added here

//         // Evaluate DUT
//         dut->eval();
//         m_trace->dump(sim_time);

//         // Print output for debugging
//         std::cout << "Time: " << sim_time
//                   << " | in_a: " << std::hex << dut->in_a
//                   << " | in_b: " << std::hex << dut->in_b
//                   << " | out: " << std::hex << dut->out
//                   << std::dec << std::endl;
//     }

//     // Final evaluation to catch any last changes
//     dut->eval();
//     m_trace->dump(sim_time);

//     // Cleanup
//     m_trace->close();
//     delete dut;
//     delete m_trace;

//     std::cout << "Simulation finished" << std::endl;
//     return 0;
// }
