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
            tracep->chgIData(oldp+0,(vlTOPp->riscv__DOT__if_id_instr),32);
            tracep->chgIData(oldp+1,(vlTOPp->riscv__DOT__IF_unit__DOT__curr_count),32);
            tracep->chgIData(oldp+2,(((IData)(4U) + vlTOPp->riscv__DOT__IF_unit__DOT__curr_count)),32);
            tracep->chgCData(oldp+3,(vlTOPp->riscv__DOT__id_ex_rd),5);
            tracep->chgIData(oldp+4,(vlTOPp->riscv__DOT__id_ex_pc),32);
            tracep->chgIData(oldp+5,(vlTOPp->riscv__DOT__id_ex_reg_a),32);
            tracep->chgIData(oldp+6,(vlTOPp->riscv__DOT__id_ex_reg_b),32);
            tracep->chgIData(oldp+7,(vlTOPp->riscv__DOT__id_ex_imm),32);
            tracep->chgBit(oldp+8,(vlTOPp->riscv__DOT__id_ex_regwrite_d));
            tracep->chgCData(oldp+9,(vlTOPp->riscv__DOT__id_ex_result_src_d),2);
            tracep->chgBit(oldp+10,(vlTOPp->riscv__DOT__id_ex_memwrite_d));
            tracep->chgBit(oldp+11,(vlTOPp->riscv__DOT__id_ex_jump_d));
            tracep->chgBit(oldp+12,(vlTOPp->riscv__DOT__id_ex_branch_d));
            tracep->chgCData(oldp+13,(vlTOPp->riscv__DOT__id_ex_alu_control_d),4);
            tracep->chgBit(oldp+14,(vlTOPp->riscv__DOT__id_ex_alu_src_d));
            tracep->chgIData(oldp+15,(vlTOPp->riscv__DOT__id_ex_pc_plus_4),32);
            tracep->chgIData(oldp+16,(((IData)(vlTOPp->riscv__DOT__pc_src)
                                        ? 0xaU : ((IData)(4U) 
                                                  + vlTOPp->riscv__DOT__IF_unit__DOT__curr_count))),32);
            tracep->chgIData(oldp+17,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[0]),32);
            tracep->chgIData(oldp+18,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[1]),32);
            tracep->chgIData(oldp+19,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[2]),32);
            tracep->chgIData(oldp+20,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[3]),32);
            tracep->chgIData(oldp+21,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[4]),32);
            tracep->chgIData(oldp+22,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[5]),32);
            tracep->chgIData(oldp+23,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[6]),32);
            tracep->chgIData(oldp+24,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[7]),32);
            tracep->chgIData(oldp+25,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[8]),32);
            tracep->chgIData(oldp+26,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[9]),32);
            tracep->chgIData(oldp+27,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[10]),32);
            tracep->chgIData(oldp+28,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[11]),32);
            tracep->chgIData(oldp+29,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[12]),32);
            tracep->chgIData(oldp+30,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[13]),32);
            tracep->chgIData(oldp+31,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[14]),32);
            tracep->chgIData(oldp+32,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[15]),32);
            tracep->chgIData(oldp+33,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[16]),32);
            tracep->chgIData(oldp+34,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[17]),32);
            tracep->chgIData(oldp+35,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[18]),32);
            tracep->chgIData(oldp+36,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[19]),32);
            tracep->chgIData(oldp+37,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[20]),32);
            tracep->chgIData(oldp+38,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[21]),32);
            tracep->chgIData(oldp+39,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[22]),32);
            tracep->chgIData(oldp+40,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[23]),32);
            tracep->chgIData(oldp+41,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[24]),32);
            tracep->chgIData(oldp+42,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[25]),32);
            tracep->chgIData(oldp+43,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[26]),32);
            tracep->chgIData(oldp+44,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[27]),32);
            tracep->chgIData(oldp+45,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[28]),32);
            tracep->chgIData(oldp+46,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[29]),32);
            tracep->chgIData(oldp+47,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[30]),32);
            tracep->chgIData(oldp+48,(vlTOPp->riscv__DOT__ID_unit__DOT__reg_array[31]),32);
            tracep->chgCData(oldp+49,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                                >> 0xfU))),5);
            tracep->chgCData(oldp+50,((0x1fU & (vlTOPp->riscv__DOT__if_id_instr 
                                                >> 0x14U))),5);
            tracep->chgCData(oldp+51,((0x7fU & vlTOPp->riscv__DOT__if_id_instr)),7);
            tracep->chgCData(oldp+52,((7U & (vlTOPp->riscv__DOT__if_id_instr 
                                             >> 0xcU))),3);
            tracep->chgBit(oldp+53,((1U & (vlTOPp->riscv__DOT__if_id_instr 
                                           >> 0x1eU))));
            tracep->chgIData(oldp+54,(vlTOPp->riscv__DOT__ID_unit__DOT__immediate_temp),32);
            tracep->chgBit(oldp+55,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 6U))));
            tracep->chgBit(oldp+56,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 4U))));
            tracep->chgBit(oldp+57,((1U & (IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals))));
            tracep->chgBit(oldp+58,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 1U))));
            tracep->chgBit(oldp+59,((1U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                           >> 5U))));
            tracep->chgCData(oldp+60,(((0x40U & vlTOPp->riscv__DOT__if_id_instr)
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
            tracep->chgCData(oldp+61,((3U & ((IData)(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals) 
                                             >> 2U))),2);
            tracep->chgIData(oldp+62,(vlTOPp->riscv__DOT__ID_unit__DOT__i),32);
            tracep->chgCData(oldp+63,(vlTOPp->riscv__DOT__ID_unit__DOT__control_signal_unit__DOT__control_signals),7);
        }
        tracep->chgBit(oldp+64,(vlTOPp->clk));
        tracep->chgBit(oldp+65,(vlTOPp->reset));
        tracep->chgIData(oldp+66,(vlTOPp->instr_out),32);
        tracep->chgIData(oldp+67,(vlTOPp->pc_out),32);
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
    }
}
