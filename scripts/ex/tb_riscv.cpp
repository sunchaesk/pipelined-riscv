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

void dut_riscv_load_instruction(Vriscv *dut, char* instrFile) {

    ifstream instructionFile(instrFile);
    string instruction;
    int i = 0;
    while (getline(instructionFile, instruction)) {
        dut->riscv__DOT__IF_unit__DOT__instr_mem[i] = std::stoi(hexString, nullptr, 16);
        i++;
    }

    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00730393; // addi x7, x6, 7
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x005303b3; // add x7, x6, x5
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x405303b3; // sub x7, x6, x5
    //
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00002383; // lw x7, 0(x0)
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00402383; // lw x7, 4(x0)

    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00702023; // sw x7, 0(x0)

    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00702023; // sw x7, 0(x0)

    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x000003ef; // jal x7, 32
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x010003ef; // jal x7, 16
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[1] = 0x003102b3; // add x5, x2, x3
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[2] = 0x00a20293; // addi x5, x4,10
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[3] = 0x00b20293; // addi x5, x4,11
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[4] = 0x02000093; // addi x1, x0, 32
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[5] = 0x03000093; // addi x1, x0, 32
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[6] = 0x04000093; // addi x1, x0, 32
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[7] = 0x05000093; // addi x1, x0, 32

    ///// testing branch instr
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00310863; // beq x2, x3, 16
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[1] = 0x003102b3; // add x5, x2, x3
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[2] = 0x00a20293; // addi x5, x4,10
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[3] = 0x00b20293; // addi x5, x4,11
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[4] = 0x02000093; // addi x1, x0, 32

    // forwarding test
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x002102b3; // add x5, x2, x2
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[1] = 0x00000533; // add x10, x0, x0
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[1] = 0x00428333; // add x6, x5, x4
    // expected output: x5=8, x6=8+6=14(E) / 7 + 6 = 13 (D)

    // lw test (stalling test)
    dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x00002283; // lw x5, 0(x0)
    dut->riscv__DOT__IF_unit__DOT__instr_mem[1] = 0x00028333; // add x6, x5, x0

    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x008003ef; // beq x7, x0, 8

}

void dut_riscv_load_register_file(Vriscv *dut) {
    // initial initialization
    for (int i = 0; i < 32; i++){
        dut->riscv__DOT__ID_unit__DOT__reg_array[i] = i + 2;
    }

    dut->riscv__DOT__ID_unit__DOT__reg_array[0] = 4; //zero register
}

<<<<<<< HEAD:testing pipeline/tb_riscv.cpp
void dut_riscv_load_memory(Vriscv *dut, char* memFile) {
    ifstream instructionFile(memFile);
    string instruction;
    int i = 0;
    while (getline(instructionFile, instruction)) {
        dut->riscv__DOT__MEM_unit__DOT__mem_array[i] = std::stoi(hexString, nullptr, 16);
        i++;
    }
=======
void dut_riscv_load_memory(Vriscv *dut) {
    dut->riscv__DOT__MEM_unit__DOT__mem_array[0] = 0x00000004;
    dut->riscv__DOT__MEM_unit__DOT__mem_array[1] = 0x0000000C;

>>>>>>> ccc39e71fc36d41644034a4de248e2c501d4166a:test/tb_riscv.cpp
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
void dut_test_init (Vriscv *dut, VerilatedVcdC *m_trace, vluint64_t &sim_time, char* instrFile, char* memFile){
    dut_riscv_load_instruction(dut, instrFile);
    dut_riscv_load_memory(dut memFile);
    d_dut_riscv_print_loaded_instructions(dut, sim_time);
    dut_reset(dut, m_trace, sim_time);
    dut_riscv_load_register_file(dut); // load reg after reset because reset deletes reg
}

int main(int argc, char** argv, char** env) {
    std::cout << "Starting simulation\n";

    // load instruction file and memory file names from options
    std:string instrFile = argv[0];
    std:string memFile = argv[1];

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
