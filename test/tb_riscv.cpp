#include <stdlib.h>
#include <iostream>
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

void dut_riscv_load_instruction(Vriscv *dut) {
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0xAAAAAAAA;
    // dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x005303b3; // add x7, x6, x5
    dut->riscv__DOT__IF_unit__DOT__instr_mem[0] = 0x405303b3; // sub x7, x6, x5
}

void dut_riscv_load_register_file(Vriscv *dut) {
    for (int i = 0; i < 32; i++){
        dut->riscv__DOT__ID_unit__DOT__reg_array[i] = i + 1;
    }
}


void d_dut_riscv_print_loaded_instructions(Vriscv *dut, vluint64_t &sim_time) {
    std::cout << "=== PRINTING LOADED INSTRUCTIONS ===" << std::endl;
    for (int i = 0; i < 256; ++i) {
        uint32_t instr_mem_value = dut->riscv__DOT__IF_unit__DOT__instr_mem[i];
        if (instr_mem_value != 0) {
            std::cout << "instr_mem[" << i << "]: 0x"
                      << std::hex << instr_mem_value << std::endl;
        }
    }
    std::cout << "=== DONE PRINTING LOADED INSTRUCTIONS ===" << std::endl;
}

// run the reset, load instruction, load register file
void dut_test_init (Vriscv *dut, VerilatedVcdC *m_trace, vluint64_t &sim_time){
    dut_riscv_load_instruction(dut);
    d_dut_riscv_print_loaded_instructions(dut, sim_time);
    dut_reset(dut, m_trace, sim_time);
    dut_riscv_load_register_file(dut); // load reg after reset because reset deletes reg
}

int main(int argc, char** argv, char** env) {
    std::cout << "Starting simulation\n";

    // Instantiate the DUT
    Vriscv *dut = new Vriscv;

    // Enable tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    // Reset the DUT
    dut_test_init(dut, m_trace, sim_time);

    // Simulation loop
    while (sim_time < MAX_SIM_TIME) {
        // Toggle clock
        dut->clk ^= 1;

        // Evaluate DUT
        dut->eval();
        m_trace->dump(sim_time);

        sim_time++;
    }

    // Close VCD trace file
    m_trace->close();

    // Clean up
    delete dut;
    exit(EXIT_SUCCESS);
}
