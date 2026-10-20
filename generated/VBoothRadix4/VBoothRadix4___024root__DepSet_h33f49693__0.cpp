// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBoothRadix4.h for the primary calling header

#include "VBoothRadix4__pch.h"
#include "VBoothRadix4__Syms.h"
#include "VBoothRadix4___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__ico(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG

void VBoothRadix4___024root___eval_triggers__ico(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VBoothRadix4___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__act(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG

void VBoothRadix4___024root___eval_triggers__act(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VBoothRadix4___024root___dump_triggers__act(vlSelf);
    }
#endif
}
