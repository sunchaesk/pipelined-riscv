// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vriscv__Syms.h"


void Vriscv::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vriscv::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[1U])) {
            tracep->chgIData(oldp+0,(vlTOPp->riscv__DOT__id_ex_reg_a),32);
            tracep->chgIData(oldp+1,(vlTOPp->riscv__DOT__id_ex_reg_b),32);
            tracep->chgBit(oldp+2,(vlTOPp->riscv__DOT__id_ex_memwrite_d));
            tracep->chgBit(oldp+3,(vlTOPp->riscv__DOT__id_ex_jump_d));
            tracep->chgBit(oldp+4,(vlTOPp->riscv__DOT__id_ex_branch_d));
            tracep->chgCData(oldp+5,(vlTOPp->riscv__DOT__id_ex_alu_control_d),4);
            tracep->chgCData(oldp+6,(vlTOPp->riscv__DOT__id_ex_branch_control_d),3);
            tracep->chgBit(oldp+7,(vlTOPp->riscv__DOT__id_ex_alu_src_d));
            tracep->chgCData(oldp+8,(vlTOPp->riscv__DOT__id_ex_rs1_d_reg),5);
            tracep->chgCData(oldp+9,(vlTOPp->riscv__DOT__id_ex_rs2_d_reg),5);
            tracep->chgIData(oldp+10,(vlTOPp->riscv__DOT__ex_mem_writedata_e),32);
            tracep->chgBit(oldp+11,(vlTOPp->riscv__DOT__ex_mem_memwrite_e));
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[2U])) {
            tracep->chgIData(oldp+12,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0]),32);
            tracep->chgIData(oldp+13,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[1]),32);
            tracep->chgIData(oldp+14,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[2]),32);
            tracep->chgIData(oldp+15,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[3]),32);
            tracep->chgIData(oldp+16,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[4]),32);
            tracep->chgIData(oldp+17,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[5]),32);
            tracep->chgIData(oldp+18,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[6]),32);
            tracep->chgIData(oldp+19,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[7]),32);
            tracep->chgIData(oldp+20,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[8]),32);
            tracep->chgIData(oldp+21,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[9]),32);
            tracep->chgIData(oldp+22,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[10]),32);
            tracep->chgIData(oldp+23,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[11]),32);
            tracep->chgIData(oldp+24,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[12]),32);
            tracep->chgIData(oldp+25,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[13]),32);
            tracep->chgIData(oldp+26,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[14]),32);
            tracep->chgIData(oldp+27,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[15]),32);
            tracep->chgIData(oldp+28,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[16]),32);
            tracep->chgIData(oldp+29,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[17]),32);
            tracep->chgIData(oldp+30,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[18]),32);
            tracep->chgIData(oldp+31,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[19]),32);
            tracep->chgIData(oldp+32,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[20]),32);
            tracep->chgIData(oldp+33,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[21]),32);
            tracep->chgIData(oldp+34,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[22]),32);
            tracep->chgIData(oldp+35,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[23]),32);
            tracep->chgIData(oldp+36,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[24]),32);
            tracep->chgIData(oldp+37,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[25]),32);
            tracep->chgIData(oldp+38,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[26]),32);
            tracep->chgIData(oldp+39,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[27]),32);
            tracep->chgIData(oldp+40,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[28]),32);
            tracep->chgIData(oldp+41,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[29]),32);
            tracep->chgIData(oldp+42,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[30]),32);
            tracep->chgIData(oldp+43,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[31]),32);
            tracep->chgIData(oldp+44,(vlTOPp->riscv__DOT__ID_unit__DOT__i),32);
        }
        if (VL_UNLIKELY(vlTOPp->__Vm_traceActivity[3U])) {
            tracep->chgIData(oldp+45,(vlTOPp->riscv__DOT__if_id_instr),32);
            tracep->chgIData(oldp+46,(vlTOPp->riscv__DOT__if_id_pc),32);
            tracep->chgIData(oldp+47,(vlTOPp->riscv__DOT__if_id_pc_plus_4),32);
            tracep->chgCData(oldp+48,(vlTOPp->riscv__DOT__id_ex_rd),5);
            tracep->chgIData(oldp+49,(vlTOPp->riscv__DOT__id_ex_pc),32);
            tracep->chgIData(oldp+50,(vlTOPp->riscv__DOT__id_ex_imm),32);
            tracep->chgBit(oldp+51,(vlTOPp->riscv__DOT__id_ex_regwrite_d));
            tracep->chgCData(oldp+52,(vlTOPp->riscv__DOT__id_ex_result_src_d),2);
            tracep->chgIData(oldp+53,(vlTOPp->riscv__DOT__id_ex_pc_plus_4),32);
            tracep->chgCData(oldp+54,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+55,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                                >> 0x14U))),5);
            tracep->chgBit(oldp+56,(vlTOPp->riscv__DOT__ex_mem_zero_flag_e));
            tracep->chgIData(oldp+57,((vlTOPp->riscv__DOT__id_ex_pc 
                                       + vlTOPp->riscv__DOT__id_ex_imm)),32);
            tracep->chgIData(oldp+58,(vlTOPp->riscv__DOT__ex_mem_alu_result_e),32);
            tracep->chgIData(oldp+59,(vlTOPp->riscv__DOT__ex_mem_pc_plus_4_e),32);
            tracep->chgCData(oldp+60,(vlTOPp->riscv__DOT__ex_mem_rd_e),5);
            tracep->chgBit(oldp+61,(vlTOPp->riscv__DOT__ex_mem_regwrite_e));
            tracep->chgCData(oldp+62,(vlTOPp->riscv__DOT__ex_mem_result_src_e),2);
            tracep->chgBit(oldp+63,(vlTOPp->riscv__DOT__ex_mem_pc_src_e));
            tracep->chgIData(oldp+64,(vlTOPp->riscv__DOT__mem_wb_readdata_w),32);
            tracep->chgBit(oldp+65,(vlTOPp->riscv__DOT__mem_wb_regwrite_w));
            tracep->chgCData(oldp+66,(vlTOPp->riscv__DOT__mem_wb_result_src_w),2);
            tracep->chgIData(oldp+67,(vlTOPp->riscv__DOT__mem_wb_alu_result_w),32);
            tracep->chgIData(oldp+68,(vlTOPp->riscv__DOT__mem_wb_pc_plus_4_w),32);
            tracep->chgCData(oldp+69,(vlTOPp->riscv__DOT__mem_wb_rd_w),5);
            tracep->chgBit(oldp+70,(vlTOPp->riscv__DOT__wb_regwrite));
            tracep->chgCData(oldp+71,(vlTOPp->riscv__DOT__wb_rd),5);
            tracep->chgIData(oldp+72,(vlTOPp->riscv__DOT__wb_result),32);
            tracep->chgBit(oldp+73,(vlTOPp->riscv__DOT__hazard_unit__DOT__lw_stall));
            tracep->chgBit(oldp+74,(vlTOPp->riscv__DOT__flush_d));
            tracep->chgBit(oldp+75,(vlTOPp->riscv__DOT__flush_e));
            tracep->chgCData(oldp+76,(vlTOPp->riscv__DOT__forward_operand_a_e),2);
            tracep->chgCData(oldp+77,(vlTOPp->riscv__DOT__forward_operand_b_e),2);
            tracep->chgIData(oldp+78,(vlTOPp->riscv__DOT__IF_unit__DOT__next_pc),32);
            tracep->chgCData(oldp+79,((0x7fU & vlTOPp->riscv__DOT__if_id_instr)),7);
            tracep->chgCData(oldp+80,((7U & (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 0xcU))),3);
            tracep->chgBit(oldp+81,((1U & (vlTOPp->riscv__DOT__if_id_instr 
                                           >> 0x1eU))));
            tracep->chgIData(oldp+82,(vlTOPp->riscv__DOT__ID_unit__DOT__immediate_temp),32);
            tracep->chgBit(oldp+83,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 6U))));
            tracep->chgBit(oldp+84,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 4U))));
            tracep->chgBit(oldp+85,((1U & (IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals))));
            tracep->chgBit(oldp+86,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 1U))));
            tracep->chgBit(oldp+87,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 5U))));
            tracep->chgCData(oldp+88,(((0x40U & vlTOPp->riscv__DOT__if_id_instr)
                                        ? 0U : ((0x20U 
                                                 & vlTOPp->riscv__DOT__if_id_instr)
                                                 ? 
                                                ((0x10U 
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
                                                 : 
                                                ((0x10U 
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
            tracep->chgCData(oldp+89,((3U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                             >> 2U))),2);
            tracep->chgCData(oldp+90,(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals),7);
            tracep->chgIData(oldp+91,(vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a),32);
            tracep->chgIData(oldp+92,(vlTOPp->riscv__DOT__EX_unit__DOT__operand_b),32);
            tracep->chgIData(oldp+93,(vlTOPp->riscv__DOT__EX_unit__DOT__alu_result_temp),32);
            tracep->chgIData(oldp+94,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[0]),32);
            tracep->chgIData(oldp+95,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[1]),32);
            tracep->chgIData(oldp+96,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[2]),32);
            tracep->chgIData(oldp+97,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[3]),32);
            tracep->chgIData(oldp+98,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[4]),32);
            tracep->chgIData(oldp+99,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[5]),32);
            tracep->chgIData(oldp+100,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[6]),32);
            tracep->chgIData(oldp+101,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[7]),32);
            tracep->chgIData(oldp+102,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[8]),32);
            tracep->chgIData(oldp+103,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[9]),32);
            tracep->chgIData(oldp+104,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[10]),32);
            tracep->chgIData(oldp+105,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[11]),32);
            tracep->chgIData(oldp+106,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[12]),32);
            tracep->chgIData(oldp+107,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[13]),32);
            tracep->chgIData(oldp+108,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[14]),32);
            tracep->chgIData(oldp+109,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[15]),32);
            tracep->chgIData(oldp+110,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[16]),32);
            tracep->chgIData(oldp+111,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[17]),32);
            tracep->chgIData(oldp+112,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[18]),32);
            tracep->chgIData(oldp+113,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[19]),32);
            tracep->chgIData(oldp+114,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[20]),32);
            tracep->chgIData(oldp+115,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[21]),32);
            tracep->chgIData(oldp+116,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[22]),32);
            tracep->chgIData(oldp+117,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[23]),32);
            tracep->chgIData(oldp+118,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[24]),32);
            tracep->chgIData(oldp+119,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[25]),32);
            tracep->chgIData(oldp+120,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[26]),32);
            tracep->chgIData(oldp+121,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[27]),32);
            tracep->chgIData(oldp+122,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[28]),32);
            tracep->chgIData(oldp+123,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[29]),32);
            tracep->chgIData(oldp+124,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[30]),32);
            tracep->chgIData(oldp+125,(vlTOPp->riscv__DOT__MEM_unit__DOT__mem_array[31]),32);
            tracep->chgBit(oldp+126,((1U & (IData)(vlTOPp->riscv__DOT__id_ex_result_src_d))));
        }
        tracep->chgBit(oldp+127,(vlTOPp->clk));
        tracep->chgBit(oldp+128,(vlTOPp->reset));
        tracep->chgBit(oldp+129,(((4U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                   ? ((2U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                       ? ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                           ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                              >= vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                           : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                              < vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))
                                       : ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                           ? VL_GTES_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                           : VL_LTS_III(1,32,32, vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a, vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)))
                                   : ((~ ((IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d) 
                                          >> 1U)) & 
                                      ((1U & (IData)(vlTOPp->riscv__DOT__id_ex_branch_control_d))
                                        ? (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                           != vlTOPp->riscv__DOT__EX_unit__DOT__operand_b)
                                        : (vlTOPp->riscv__DOT__EX_unit__DOT__hazard_a 
                                           == vlTOPp->riscv__DOT__EX_unit__DOT__operand_b))))));
        tracep->chgIData(oldp+130,(((0U == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                     ? vlTOPp->riscv__DOT__id_ex_reg_b
                                     : ((1U == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                         ? vlTOPp->riscv__DOT__mem_wb_alu_result_w
                                         : ((2U == (IData)(vlTOPp->riscv__DOT__forward_operand_b_e))
                                             ? vlTOPp->riscv__DOT__ex_mem_alu_result_e
                                             : 0U)))),32);
    }
}

void Vriscv::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vriscv__Syms* __restrict vlSymsp = static_cast<Vriscv__Syms*>(userp);
    Vriscv* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
        vlTOPp->__Vm_traceActivity[1U] = 0U;
        vlTOPp->__Vm_traceActivity[2U] = 0U;
        vlTOPp->__Vm_traceActivity[3U] = 0U;
    }
}
