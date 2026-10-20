// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBoothRadix4.h for the primary calling header

#include "VBoothRadix4__pch.h"
#include "VBoothRadix4___024root.h"

VL_ATTR_COLD void VBoothRadix4___024root___eval_static(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_static\n"); );
}

VL_ATTR_COLD void VBoothRadix4___024root___eval_initial(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_initial\n"); );
    // Body
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
}

VL_ATTR_COLD void VBoothRadix4___024root___eval_final(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__stl(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VBoothRadix4___024root___eval_phase__stl(VBoothRadix4___024root* vlSelf);

VL_ATTR_COLD void VBoothRadix4___024root___eval_settle(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            VBoothRadix4___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("rtl/BoothRadix4.v", 2, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VBoothRadix4___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__stl(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VBoothRadix4___024root___ico_sequent__TOP__0(VBoothRadix4___024root* vlSelf);

VL_ATTR_COLD void VBoothRadix4___024root___eval_stl(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VBoothRadix4___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

VL_ATTR_COLD void VBoothRadix4___024root___eval_triggers__stl(VBoothRadix4___024root* vlSelf);

VL_ATTR_COLD bool VBoothRadix4___024root___eval_phase__stl(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VBoothRadix4___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        VBoothRadix4___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__ico(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__act(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__nba(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VBoothRadix4___024root___ctor_var_reset(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->product = VL_RAND_RESET_Q(36);
    vlSelf->done = VL_RAND_RESET_I(1);
    vlSelf->mplier = VL_RAND_RESET_I(18);
    vlSelf->mcand = VL_RAND_RESET_I(18);
    vlSelf->n_reset = VL_RAND_RESET_I(1);
    vlSelf->start = VL_RAND_RESET_I(1);
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->BoothRadix4__DOT__state_reg = VL_RAND_RESET_I(2);
    vlSelf->BoothRadix4__DOT__state_next = VL_RAND_RESET_I(2);
    vlSelf->BoothRadix4__DOT__q_reg = VL_RAND_RESET_I(5);
    vlSelf->BoothRadix4__DOT__q_next = VL_RAND_RESET_I(5);
    vlSelf->BoothRadix4__DOT__prod_reg = VL_RAND_RESET_Q(38);
    vlSelf->BoothRadix4__DOT__prod_next = VL_RAND_RESET_Q(38);
    vlSelf->BoothRadix4__DOT__result_reg = VL_RAND_RESET_I(1);
    vlSelf->BoothRadix4__DOT__mcand_reg = VL_RAND_RESET_I(18);
    vlSelf->BoothRadix4__DOT__mcand_next = VL_RAND_RESET_I(18);
    vlSelf->BoothRadix4__DOT__q_add = VL_RAND_RESET_I(1);
    vlSelf->BoothRadix4__DOT__q_reset = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 3; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
