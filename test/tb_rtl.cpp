#include <iostream>
#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtest.h"

const vluint64_t MAX_SIM_TIME = 1000;

void dut_reset(Vtest* dut, VerilatedVcdC* trace, vluint64_t& sim_time) {
    dut->reset = 1;
    trace->dump(sim_time++);
    dut->reset = 0;
    trace->dump(sim_time++);
}

void test_vsew_32(Vtest *dut, VerilatedVcdC* m_trace, vluint64_t& sim_time){
    // Set input values
    dut->vsew = 0b010; // Example value for vsew
    dut->funct6 = 0b000000; // Example value for funct6

    uint32_t operand_a_arr[8] = {
        0x01010101, 0x01010101, 0x02020202, 0x02020202,
        0x03030303, 0x03030303, 0x04040404, 0x40404040
    };
    uint32_t operand_b_arr[8] = {
        0x10101010, 0x10101010, 0x20202020, 0x20202020,
        0x30303030, 0x30303030, 0x40404040, 0x04040404
    };

    for (int i = 0; i < 8; ++i) {
        dut->operand_a[i] = operand_a_arr[i];
        dut->operand_b[i] = operand_b_arr[i];
    }

    // Apply new instruction
    dut->new_instr = 1;
    m_trace->dump(sim_time++);
    dut->new_instr = 0;

    // Run simulation
    while (sim_time < MAX_SIM_TIME) {
        dut->clk = !dut->clk;  // Toggle clock
        dut->eval();           // Evaluate DUT
        m_trace->dump(sim_time); // Dump trace data
        sim_time++;

        if (dut->vec_op_done == 1) {
            std::cout << "Operation Done!" << std::endl;

            // Print the output value
            std::cout << "Input operand_a: ";
            for (int i = 0; i < 8; ++i) {
                std::cout << std::hex << dut->operand_a[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "Input operand_b: ";
            for (int i = 0; i < 8; ++i) {
                std::cout << std::hex << dut->operand_b[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "vec_exec_out: ";
            for (int i = 0; i < 8; ++i) {
                std::cout << std::hex << dut->vec_exec_out[i] << " ";
            }
            std::cout << std::endl;
            break;
        }
    }

    // Clean up
    m_trace->close();
    delete dut;
    delete m_trace;

    std::cout << "Simulation finished" << std::endl;
}

void test_vsew_16(Vtest *dut, VerilatedVcdC* m_trace, vluint64_t& sim_time) {
    // Set input values
    dut->vsew = 0b001; // Example value for vsew (16-bit)
    dut->funct6 = 0b000000; // Example value for funct6

    uint16_t operand_a_arr[16] = {
        0x0101, 0x0101, 0x0202, 0x0202,
        0x0303, 0x0303, 0x0404, 0x0404,
        0x0505, 0x0505, 0x0606, 0x0606,
        0x0707, 0x0707, 0x0808, 0x0808
    };
    uint16_t operand_b_arr[16] = {
        0x1010, 0x1010, 0x2020, 0x2020,
        0x3030, 0x3030, 0x4040, 0x4040,
        0x5050, 0x5050, 0x6060, 0x6060,
        0x7070, 0x7070, 0x8080, 0x8080
    };

    // Set the input operands
    for (int i = 0; i < 8; ++i) {
        // Combine two 16-bit values into a 32-bit value for the DUT
        dut->operand_a[i] = (operand_a_arr[2 * i + 1] << 16) | operand_a_arr[2 * i];
        dut->operand_b[i] = (operand_b_arr[2 * i + 1] << 16) | operand_b_arr[2 * i];
    }

    // Apply new instruction
    dut->new_instr = 1;
    m_trace->dump(sim_time++);
    dut->new_instr = 0;

    // Run simulation
    while (sim_time < MAX_SIM_TIME) {
        dut->clk = !dut->clk;  // Toggle clock
        dut->eval();           // Evaluate DUT
        m_trace->dump(sim_time); // Dump trace data
        sim_time++;

        if (dut->vec_op_done == 1) {
            std::cout << "Operation Done!" << std::endl;

            // Print the output value
            std::cout << "Input operand_a: ";
            for (int i = 0; i < 8; ++i) {
                std::cout << std::hex << dut->operand_a[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "Input operand_b: ";
            for (int i = 0; i < 8; ++i) {
                std::cout << std::hex << dut->operand_b[i] << " ";
            }
            std::cout << std::endl;

            std::cout << "vec_exec_out: ";
            for (int i = 0; i < 16; ++i) {
                // Combine two 16-bit values into a 32-bit value for output
                uint32_t combined_output = (dut->vec_exec_out[i / 2] >> (16 * (i % 2))) & 0xFFFF;
                std::cout << std::hex << combined_output << " ";
            }
            std::cout << std::endl;
            break;
        }
    }

    // Clean up
    m_trace->close();
    delete dut;
    delete m_trace;

    std::cout << "Simulation finished" << std::endl;
}
int main(int argc, char** argv) {
    std::cout << "tb_rtl.cpp" << std::endl;

    Verilated::commandArgs(argc, argv);

    // Initialize Vtest module
    Vtest* dut = new Vtest;

    // Enable VCD tracing
    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 99); // Add all signals with verbosity level 99
    m_trace->open("waveform_rtl_test.vcd");

    // Add signals to trace manually

    // Initialize simulation time
    vluint64_t sim_time = 0;

    // Reset the DUT
    dut_reset(dut, m_trace, sim_time);

    // test_vsew_32(dut, m_trace, sim_time);
    test_vsew_16(dut, m_trace, sim_time);

    return 0;
}
