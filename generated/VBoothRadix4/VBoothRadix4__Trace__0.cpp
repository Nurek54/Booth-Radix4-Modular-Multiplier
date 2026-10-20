// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VBoothRadix4__Syms.h"


void VBoothRadix4___024root__trace_chg_0_sub_0(VBoothRadix4___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VBoothRadix4___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root__trace_chg_0\n"); );
    // Init
    VBoothRadix4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VBoothRadix4___024root*>(voidSelf);
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VBoothRadix4___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VBoothRadix4___024root__trace_chg_0_sub_0(VBoothRadix4___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSelf->BoothRadix4__DOT__state_next),2);
        bufp->chgCData(oldp+1,(vlSelf->BoothRadix4__DOT__q_next),5);
        bufp->chgQData(oldp+2,(vlSelf->BoothRadix4__DOT__prod_next),38);
        bufp->chgIData(oldp+4,(vlSelf->BoothRadix4__DOT__mcand_next),18);
        bufp->chgBit(oldp+5,(vlSelf->BoothRadix4__DOT__q_add));
        bufp->chgBit(oldp+6,(vlSelf->BoothRadix4__DOT__q_reset));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgCData(oldp+7,(vlSelf->BoothRadix4__DOT__state_reg),2);
        bufp->chgCData(oldp+8,(vlSelf->BoothRadix4__DOT__q_reg),5);
        bufp->chgQData(oldp+9,(vlSelf->BoothRadix4__DOT__prod_reg),38);
        bufp->chgBit(oldp+11,(vlSelf->BoothRadix4__DOT__result_reg));
        bufp->chgIData(oldp+12,(vlSelf->BoothRadix4__DOT__mcand_reg),18);
    }
    bufp->chgQData(oldp+13,(vlSelf->product),36);
    bufp->chgBit(oldp+15,(vlSelf->done));
    bufp->chgIData(oldp+16,(vlSelf->mplier),18);
    bufp->chgIData(oldp+17,(vlSelf->mcand),18);
    bufp->chgBit(oldp+18,(vlSelf->n_reset));
    bufp->chgBit(oldp+19,(vlSelf->start));
    bufp->chgBit(oldp+20,(vlSelf->clk));
}

void VBoothRadix4___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root__trace_cleanup\n"); );
    // Init
    VBoothRadix4___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VBoothRadix4___024root*>(voidSelf);
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
}
