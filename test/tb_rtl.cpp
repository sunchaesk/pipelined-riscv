
#include <string>
#include <iostream>
#include <fstream>

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vtest.h"
#include "Vtest__Syms.h"

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

int main(int argc, char ** argv, char ** env){
    std::cout << "tb_rtl.cpp" << std::endl;

    Vtest * dut = new Vtest;
    Verilated::traceEverOn(true);
    VerilatedVcdC *m_trace = new VerilatedVcdC;

    // dut->trace(m_trace, 5);
    m_trace->open("waveform_rtl_test.vcd");

    while (sim_time < MAX_SIM_TIME) {
        dut->in_a = 100;
        dut->in_b = 50;


        dut->eval();
        m_trace->dump(sim_time);
        std::cout << "out " << dut->out << std::endl;
        sim_time++;

        std::cout << "HERE?" << std::endl;
        return 0;
    }

}
