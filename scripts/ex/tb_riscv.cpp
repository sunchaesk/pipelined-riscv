#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vriscv.h"
#include "Vriscv__Syms.h"

#define MAX_SIM_TIME 20

vluint64_t sim_time = 0;

void dut_reset(Vriscv *dut, VerilatedVcdC *m_trace, vluint64_t &sim_time) {
    // Reset the DUT
    dut->reset = 1;
    dut->clk = 1;
    dut->eval();
    m_trace->dump(sim_time);
    sim_time++;
    dut->clk = 0;
    dut->eval();
    m_trace->dump(sim_time);
    sim_time++;
    dut->reset = 0;
}

void dut_riscv_load_instruction(Vriscv *dut, const char* instrFile) {

    std::ifstream instructionFile(instrFile); // open read file

    std::string instruction;
    int i = 0;

    while (std::getline(instrFile, instruction)) {
        // Skip empty lines
        if (instruction.empty()) {
            continue;
        }

        try {
            int out = std::stoi(instruction, nullptr, 16);
            dut->riscv__DOT__IF_unit__DOT__instr_mem[i] = out;
            i++;
        } catch (const std::invalid_argument& e) {
            // not hex so probably empty line
            break;
        }
    }
}

oid dut_riscv_load_memory(Vriscv *dut, char* memFile) {
    std::ifstream memoryFile(memFile); // open read file

    std::string memory;
    int i = 524288; // hex 0x00080000, as specified in the linker.ld

    while (std::getline(memoryFile, memory)) {
        // Skip empty lines
        if (instruction.empty()) {
            continue;
        }

        try {
            int out = std::stoi(memory, nullptr, 16);
            dut->riscv__DOT__MEM_unit__DOT__mem_array[i] = out;
            i++;
        } catch (const std::invalid_argument& e) {
            // not hex so probinstructionably empty line
            break;
        }
    }
}

void d_dut_riscv_print_loaded_instructions(Vriscv *dut, vluint64_t &sim_time) {
    std::cout << "=== PRINTING LOADED INSTRUCTIONS ===" << std::endl;
    for (int i = 0; i < 32; ++i) {
        uint32_t instr_mem_value = dut->riscv__DOT__IF_unit__DOT__instr_mem[i];
        if (instr_mem_value != 0) {
            std::cout << "instr_mem[" << i << "]: 0x"
                      << std::hex << instr_mem_value << std::endl;
        }
    }
    std::cout << "=== DONE PRINTING LOADED INSTRUCTIONS ===" << std::endl;
}

void d_dut_riscv_print_memory(Vriscv *dut, vluint64_t &sim_time) {
    std::cout << "=== PRINTING MEMORY CONTENT ===" << std::endl;
    for (int i = 0; i < 32; i++){
        uint32_t instr_mem_value = dut->riscv__DOT__MEM_unit__DOT__mem_array[i];
        if (instr_mem_value != 0) {
            std::cout << "instr_mem[" << i << "]: 0x"
                      << std::hex << instr_mem_value << std::endl;
        }
    }
    std::cout << "=== DONE PRINTING MEMORY CONTENT === " << std::endl;
}

// run the reset, load instruction, load register file
void dut_test_init (Vriscv *dut, VerilatedVcdC *m_trace, vluint64_t &sim_time, const char* instrFile, const char* memFile){
    dut_riscv_load_instruction(dut, instrFile);
    dut_riscv_load_memory(dut, memFile);
    d_dut_riscv_print_loaded_instructions(dut, sim_time);
    dut_reset(dut, m_trace, sim_time);
    dut_riscv_load_register_file(dut); // load reg after reset because reset deletes reg
}

int main(int argc, char** argv, char** env) {
    std::cout << "Starting simulation\n";

    // load instruction file and memory file names from options
    std::string instrFile = argv[1];
    std::string memFile = argv[2];

    // Instantiate the DUT
    Vriscv *dut = new Vriscv;

    // Enable tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // Reset the DUT
    dut_test_init(dut, m_trace, sim_time, instrFile, memFile);

    // Simulation loop
    while (sim_time < MAX_SIM_TIME) {
        // Toggle clock
        dut->clk ^= 1;

        // Evaluate DUT
        dut->eval();
        m_trace->dump(sim_time);

        sim_time++;
    }

    // cleanup debug stuff
    d_dut_riscv_print_memory(dut, sim_time);

    // Close VCD trace file
    m_trace->close();

    // Clean up
    delete dut;
    exit(EXIT_SUCCESS);
}
