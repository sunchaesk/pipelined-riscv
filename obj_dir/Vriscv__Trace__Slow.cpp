// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv__Syms.h"


//======================

void Vriscv::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vriscv::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vriscv::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vriscv::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vriscv::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+65,"clk", false,-1);
        tracep->declBit(c+66,"reset", false,-1);
        tracep->declBus(c+67,"instr_out", false,-1, 31,0);
        tracep->declBus(c+68,"pc_out", false,-1, 31,0);
        tracep->declBit(c+65,"riscv clk", false,-1);
        tracep->declBit(c+66,"riscv reset", false,-1);
        tracep->declBus(c+67,"riscv instr_out", false,-1, 31,0);
        tracep->declBus(c+68,"riscv pc_out", false,-1, 31,0);
        tracep->declBit(c+69,"riscv pc_src", false,-1);
        tracep->declBus(c+1,"riscv if_id_instr", false,-1, 31,0);
        tracep->declBus(c+2,"riscv if_id_pc", false,-1, 31,0);
        tracep->declBus(c+3,"riscv if_id_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+4,"riscv id_ex_rd", false,-1, 4,0);
        tracep->declBus(c+5,"riscv id_ex_pc", false,-1, 31,0);
        tracep->declBus(c+6,"riscv id_ex_reg_a", false,-1, 31,0);
        tracep->declBus(c+7,"riscv id_ex_reg_b", false,-1, 31,0);
        tracep->declBus(c+8,"riscv id_ex_imm", false,-1, 31,0);
        tracep->declBit(c+9,"riscv id_ex_regwrite_d", false,-1);
        tracep->declBus(c+10,"riscv id_ex_result_src_d", false,-1, 1,0);
        tracep->declBit(c+11,"riscv id_ex_memwrite_d", false,-1);
        tracep->declBit(c+12,"riscv id_ex_jump_d", false,-1);
        tracep->declBit(c+13,"riscv id_ex_branch_d", false,-1);
        tracep->declBus(c+14,"riscv id_ex_alu_control_d", false,-1, 3,0);
        tracep->declBit(c+15,"riscv id_ex_alu_src_d", false,-1);
        tracep->declBus(c+16,"riscv id_ex_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+70,"riscv ex_mem_alu_result", false,-1, 31,0);
        tracep->declBus(c+71,"riscv ex_mem_reg_b", false,-1, 31,0);
        tracep->declBus(c+72,"riscv ex_mem_instr", false,-1, 31,0);
        tracep->declBus(c+73,"riscv mem_wb_alu_result", false,-1, 31,0);
        tracep->declBus(c+74,"riscv mem_wb_instr", false,-1, 31,0);
        tracep->declBus(c+75,"riscv mem_wb_data", false,-1, 31,0);
        tracep->declBus(c+76,"riscv alu_result", false,-1, 31,0);
        tracep->declBit(c+77,"riscv zero_flag", false,-1);
        tracep->declBit(c+65,"riscv IF_unit clk", false,-1);
        tracep->declBit(c+66,"riscv IF_unit reset", false,-1);
        tracep->declBit(c+69,"riscv IF_unit pc_src", false,-1);
        tracep->declBus(c+78,"riscv IF_unit pc_branch_dest", false,-1, 31,0);
        tracep->declBus(c+2,"riscv IF_unit pc", false,-1, 31,0);
        tracep->declBus(c+3,"riscv IF_unit pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+1,"riscv IF_unit instruction", false,-1, 31,0);
        tracep->declBus(c+17,"riscv IF_unit next_count", false,-1, 31,0);
        tracep->declBus(c+2,"riscv IF_unit curr_count", false,-1, 31,0);
        tracep->declBit(c+65,"riscv ID_unit clk", false,-1);
        tracep->declBit(c+66,"riscv ID_unit reset", false,-1);
        tracep->declBit(c+79,"riscv ID_unit writeback_control", false,-1);
        tracep->declBus(c+1,"riscv ID_unit instruction", false,-1, 31,0);
        tracep->declBus(c+2,"riscv ID_unit pc", false,-1, 31,0);
        tracep->declBus(c+3,"riscv ID_unit pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+80,"riscv ID_unit writeback_data", false,-1, 31,0);
        tracep->declBus(c+8,"riscv ID_unit immediate", false,-1, 31,0);
        tracep->declBus(c+6,"riscv ID_unit rs1_data", false,-1, 31,0);
        tracep->declBus(c+7,"riscv ID_unit rs2_data", false,-1, 31,0);
        tracep->declBus(c+4,"riscv ID_unit rd_out", false,-1, 4,0);
        tracep->declBit(c+9,"riscv ID_unit regwrite_d", false,-1);
        tracep->declBus(c+10,"riscv ID_unit result_src_d", false,-1, 1,0);
        tracep->declBit(c+11,"riscv ID_unit memwrite_d", false,-1);
        tracep->declBit(c+12,"riscv ID_unit jump_d", false,-1);
        tracep->declBit(c+13,"riscv ID_unit branch_d", false,-1);
        tracep->declBus(c+14,"riscv ID_unit alu_control_d", false,-1, 3,0);
        tracep->declBit(c+15,"riscv ID_unit alu_src_d", false,-1);
        tracep->declBus(c+16,"riscv ID_unit id_ex_pc_plus_4", false,-1, 31,0);
        tracep->declBus(c+5,"riscv ID_unit id_ex_pc", false,-1, 31,0);
        {int i; for (i=0; i<32; i++) {
                tracep->declBus(c+18+i*1,"riscv ID_unit reg_array", true,(i+0), 31,0);}}
        tracep->declBus(c+50,"riscv ID_unit rs1", false,-1, 4,0);
        tracep->declBus(c+51,"riscv ID_unit rs2", false,-1, 4,0);
        tracep->declBus(c+52,"riscv ID_unit opcode", false,-1, 6,0);
        tracep->declBus(c+53,"riscv ID_unit funct3", false,-1, 2,0);
        tracep->declBit(c+54,"riscv ID_unit funct7b5", false,-1);
        tracep->declBus(c+55,"riscv ID_unit immediate_temp", false,-1, 31,0);
        tracep->declBit(c+56,"riscv ID_unit regwrite_d_temp", false,-1);
        tracep->declBit(c+57,"riscv ID_unit memwrite_d_temp", false,-1);
        tracep->declBit(c+58,"riscv ID_unit jump_d_temp", false,-1);
        tracep->declBit(c+59,"riscv ID_unit branch_d_temp", false,-1);
        tracep->declBit(c+60,"riscv ID_unit alu_src_d_temp", false,-1);
        tracep->declBus(c+61,"riscv ID_unit alu_control_d_temp", false,-1, 3,0);
        tracep->declBus(c+62,"riscv ID_unit result_src_d_temp", false,-1, 1,0);
        tracep->declBus(c+63,"riscv ID_unit i", false,-1, 31,0);
        tracep->declBus(c+1,"riscv ID_unit immediate_generation_unit instruction", false,-1, 31,0);
        tracep->declBus(c+52,"riscv ID_unit immediate_generation_unit opcode", false,-1, 6,0);
        tracep->declBus(c+55,"riscv ID_unit immediate_generation_unit immediate_out", false,-1, 31,0);
        tracep->declBus(c+81,"riscv ID_unit immediate_generation_unit OP_LW", false,-1, 6,0);
        tracep->declBus(c+82,"riscv ID_unit immediate_generation_unit OP_SW", false,-1, 6,0);
        tracep->declBus(c+83,"riscv ID_unit immediate_generation_unit OP_R", false,-1, 6,0);
        tracep->declBus(c+84,"riscv ID_unit immediate_generation_unit OP_B", false,-1, 6,0);
        tracep->declBus(c+85,"riscv ID_unit immediate_generation_unit OP_I", false,-1, 6,0);
        tracep->declBus(c+86,"riscv ID_unit immediate_generation_unit OP_J", false,-1, 6,0);
        tracep->declBus(c+52,"riscv ID_unit control_signal_unit opcode", false,-1, 6,0);
        tracep->declBus(c+53,"riscv ID_unit control_signal_unit funct3", false,-1, 2,0);
        tracep->declBit(c+54,"riscv ID_unit control_signal_unit funct7b5", false,-1);
        tracep->declBit(c+56,"riscv ID_unit control_signal_unit regwrite_d", false,-1);
        tracep->declBit(c+57,"riscv ID_unit control_signal_unit memwrite_d", false,-1);
        tracep->declBit(c+58,"riscv ID_unit control_signal_unit jump_d", false,-1);
        tracep->declBit(c+59,"riscv ID_unit control_signal_unit branch_d", false,-1);
        tracep->declBit(c+60,"riscv ID_unit control_signal_unit alu_src_d", false,-1);
        tracep->declBus(c+62,"riscv ID_unit control_signal_unit result_src_d", false,-1, 1,0);
        tracep->declBus(c+61,"riscv ID_unit control_signal_unit alu_control_d", false,-1, 3,0);
        tracep->declBus(c+81,"riscv ID_unit control_signal_unit OP_LW", false,-1, 6,0);
        tracep->declBus(c+82,"riscv ID_unit control_signal_unit OP_SW", false,-1, 6,0);
        tracep->declBus(c+83,"riscv ID_unit control_signal_unit OP_R", false,-1, 6,0);
        tracep->declBus(c+84,"riscv ID_unit control_signal_unit OP_B", false,-1, 6,0);
        tracep->declBus(c+85,"riscv ID_unit control_signal_unit OP_I", false,-1, 6,0);
        tracep->declBus(c+86,"riscv ID_unit control_signal_unit OP_J", false,-1, 6,0);
        tracep->declBus(c+64,"riscv ID_unit control_signal_unit control_signals", false,-1, 6,0);
        tracep->declBus(c+62,"riscv ID_unit control_signal_unit result_src", false,-1, 1,0);
        tracep->declBit(c+56,"riscv ID_unit control_signal_unit regwrite", false,-1);
        tracep->declBit(c+57,"riscv ID_unit control_signal_unit memwrite", false,-1);
        tracep->declBit(c+58,"riscv ID_unit control_signal_unit jump", false,-1);
        tracep->declBit(c+59,"riscv ID_unit control_signal_unit branch", false,-1);
        tracep->declBit(c+60,"riscv ID_unit control_signal_unit alu_src", false,-1);
        tracep->declBit(c+54,"riscv ID_unit control_signal_unit ALU_decode_unit funct7b5", false,-1);
        tracep->declBus(c+53,"riscv ID_unit control_signal_unit ALU_decode_unit funct3", false,-1, 2,0);
        tracep->declBus(c+52,"riscv ID_unit control_signal_unit ALU_decode_unit opcode", false,-1, 6,0);
        tracep->declBus(c+61,"riscv ID_unit control_signal_unit ALU_decode_unit alu_control", false,-1, 3,0);
        tracep->declBus(c+81,"riscv ID_unit control_signal_unit ALU_decode_unit OP_LW", false,-1, 6,0);
        tracep->declBus(c+82,"riscv ID_unit control_signal_unit ALU_decode_unit OP_SW", false,-1, 6,0);
        tracep->declBus(c+83,"riscv ID_unit control_signal_unit ALU_decode_unit OP_R", false,-1, 6,0);
        tracep->declBus(c+84,"riscv ID_unit control_signal_unit ALU_decode_unit OP_B", false,-1, 6,0);
        tracep->declBus(c+85,"riscv ID_unit control_signal_unit ALU_decode_unit OP_I", false,-1, 6,0);
        tracep->declBus(c+86,"riscv ID_unit control_signal_unit ALU_decode_unit OP_J", false,-1, 6,0);
    }
}

void Vriscv::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vriscv::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vriscv::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullIData(oldp+1,(vlTOPp->riscv__DOT__if_id_instr),32);
        tracep->fullIData(oldp+2,(vlTOPp->riscv__DOT__IF_unit__DOT__curr_count),32);
        tracep->fullIData(oldp+3,(((IData)(4U) + vlTOPp->riscv__DOT__IF_unit__DOT__curr_count)),32);
        tracep->fullCData(oldp+4,(vlTOPp->riscv__DOT__id_ex_rd),5);
        tracep->fullIData(oldp+5,(vlTOPp->riscv__DOT__id_ex_pc),32);
        tracep->fullIData(oldp+6,(vlTOPp->riscv__DOT__id_ex_reg_a),32);
        tracep->fullIData(oldp+7,(vlTOPp->riscv__DOT__id_ex_reg_b),32);
        tracep->fullIData(oldp+8,(vlTOPp->riscv__DOT__id_ex_imm),32);
        tracep->fullBit(oldp+9,(vlTOPp->riscv__DOT__id_ex_regwrite_d));
        tracep->fullCData(oldp+10,(vlTOPp->riscv__DOT__id_ex_result_src_d),2);
        tracep->fullBit(oldp+11,(vlTOPp->riscv__DOT__id_ex_memwrite_d));
        tracep->fullBit(oldp+12,(vlTOPp->riscv__DOT__id_ex_jump_d));
        tracep->fullBit(oldp+13,(vlTOPp->riscv__DOT__id_ex_branch_d));
        tracep->fullCData(oldp+14,(vlTOPp->riscv__DOT__id_ex_alu_control_d),4);
        tracep->fullBit(oldp+15,(vlTOPp->riscv__DOT__id_ex_alu_src_d));
        tracep->fullIData(oldp+16,(vlTOPp->riscv__DOT__id_ex_pc_plus_4),32);
        tracep->fullIData(oldp+17,(((IData)(vlTOPp->riscv__DOT__pc_src)
                                     ? 0xaU : ((IData)(4U) 
                                               + vlTOPp->riscv__DOT__IF_unit__DOT__curr_count))),32);
        tracep->fullIData(oldp+18,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0]),32);
        tracep->fullIData(oldp+19,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[1]),32);
        tracep->fullIData(oldp+20,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[2]),32);
        tracep->fullIData(oldp+21,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[3]),32);
        tracep->fullIData(oldp+22,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[4]),32);
        tracep->fullIData(oldp+23,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[5]),32);
        tracep->fullIData(oldp+24,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[6]),32);
        tracep->fullIData(oldp+25,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[7]),32);
        tracep->fullIData(oldp+26,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[8]),32);
        tracep->fullIData(oldp+27,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[9]),32);
        tracep->fullIData(oldp+28,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[10]),32);
        tracep->fullIData(oldp+29,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[11]),32);
        tracep->fullIData(oldp+30,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[12]),32);
        tracep->fullIData(oldp+31,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[13]),32);
        tracep->fullIData(oldp+32,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[14]),32);
        tracep->fullIData(oldp+33,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[15]),32);
        tracep->fullIData(oldp+34,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[16]),32);
        tracep->fullIData(oldp+35,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[17]),32);
        tracep->fullIData(oldp+36,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[18]),32);
        tracep->fullIData(oldp+37,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[19]),32);
        tracep->fullIData(oldp+38,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[20]),32);
        tracep->fullIData(oldp+39,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[21]),32);
        tracep->fullIData(oldp+40,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[22]),32);
        tracep->fullIData(oldp+41,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[23]),32);
        tracep->fullIData(oldp+42,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[24]),32);
        tracep->fullIData(oldp+43,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[25]),32);
        tracep->fullIData(oldp+44,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[26]),32);
        tracep->fullIData(oldp+45,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[27]),32);
        tracep->fullIData(oldp+46,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[28]),32);
        tracep->fullIData(oldp+47,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[29]),32);
        tracep->fullIData(oldp+48,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[30]),32);
        tracep->fullIData(oldp+49,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[31]),32);
        tracep->fullCData(oldp+50,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 0xfU))),5);
        tracep->fullCData(oldp+51,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 0x14U))),5);
        tracep->fullCData(oldp+52,((0x7fU & vlTOPp->riscv__DOT__if_id_instr)),7);
        tracep->fullCData(oldp+53,((7U & (vlTOPp->riscv__DOT__if_id_instr 
                                          >> 0xcU))),3);
        tracep->fullBit(oldp+54,((1U & (vlTOPp->riscv__DOT__if_id_instr 
                                        >> 0x1eU))));
        tracep->fullIData(oldp+55,(vlTOPp->riscv__DOT__ID_unit__DOT__immediate_temp),32);
        tracep->fullBit(oldp+56,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 6U))));
        tracep->fullBit(oldp+57,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 4U))));
        tracep->fullBit(oldp+58,((1U & (IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals))));
        tracep->fullBit(oldp+59,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 1U))));
        tracep->fullBit(oldp+60,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                        >> 5U))));
        tracep->fullCData(oldp+61,(((0x40U & vlTOPp->riscv__DOT__if_id_instr)
                                     ? 0U : ((0x20U 
                                              & vlTOPp->riscv__DOT__if_id_instr)
                                              ? ((0x10U 
                                                  & vlTOPp->riscv__DOT__if_id_instr)
                                                  ? 
                                                 ((8U 
                                                   & vlTOPp->riscv__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->riscv__DOT__if_id_instr)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->riscv__DOT__if_id_instr)
                                                      ? 
                                                     ((8U 
                                                       & (vlTOPp->riscv__DOT__if_id_instr 
                                                          >> 0x1bU)) 
                                                      | (7U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            >> 0xcU)))
                                                      : 0U)
                                                     : 0U)))
                                                  : 0U)
                                              : ((0x10U 
                                                  & vlTOPp->riscv__DOT__if_id_instr)
                                                  ? 
                                                 ((8U 
                                                   & vlTOPp->riscv__DOT__if_id_instr)
                                                   ? 0U
                                                   : 
                                                  ((4U 
                                                    & vlTOPp->riscv__DOT__if_id_instr)
                                                    ? 0U
                                                    : 
                                                   ((2U 
                                                     & vlTOPp->riscv__DOT__if_id_instr)
                                                     ? 
                                                    ((1U 
                                                      & vlTOPp->riscv__DOT__if_id_instr)
                                                      ? 
                                                     ((8U 
                                                       & (vlTOPp->riscv__DOT__if_id_instr 
                                                          >> 0x1bU)) 
                                                      | (7U 
                                                         & (vlTOPp->riscv__DOT__if_id_instr 
                                                            >> 0xcU)))
                                                      : 0U)
                                                     : 0U)))
                                                  : 0U)))),4);
        tracep->fullCData(oldp+62,((3U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                          >> 2U))),2);
        tracep->fullIData(oldp+63,(vlTOPp->riscv__DOT__ID_unit__DOT__i),32);
        tracep->fullCData(oldp+64,(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals),7);
        tracep->fullBit(oldp+65,(vlTOPp->clk));
        tracep->fullBit(oldp+66,(vlTOPp->reset));
        tracep->fullIData(oldp+67,(vlTOPp->instr_out),32);
        tracep->fullIData(oldp+68,(vlTOPp->pc_out),32);
        tracep->fullBit(oldp+69,(vlTOPp->riscv__DOT__pc_src));
        tracep->fullIData(oldp+70,(vlTOPp->riscv__DOT__ex_mem_alu_result),32);
        tracep->fullIData(oldp+71,(vlTOPp->riscv__DOT__ex_mem_reg_b),32);
        tracep->fullIData(oldp+72,(vlTOPp->riscv__DOT__ex_mem_instr),32);
        tracep->fullIData(oldp+73,(vlTOPp->riscv__DOT__mem_wb_alu_result),32);
        tracep->fullIData(oldp+74,(vlTOPp->riscv__DOT__mem_wb_instr),32);
        tracep->fullIData(oldp+75,(vlTOPp->riscv__DOT__mem_wb_data),32);
        tracep->fullIData(oldp+76,(vlTOPp->riscv__DOT__alu_result),32);
        tracep->fullBit(oldp+77,(vlTOPp->riscv__DOT__zero_flag));
        tracep->fullIData(oldp+78,(0xaU),32);
        tracep->fullBit(oldp+79,(0U));
        tracep->fullIData(oldp+80,(0U),32);
        tracep->fullCData(oldp+81,(3U),7);
        tracep->fullCData(oldp+82,(0x23U),7);
        tracep->fullCData(oldp+83,(0x33U),7);
        tracep->fullCData(oldp+84,(0x63U),7);
        tracep->fullCData(oldp+85,(0x13U),7);
        tracep->fullCData(oldp+86,(0x6fU),7);
    }
}
