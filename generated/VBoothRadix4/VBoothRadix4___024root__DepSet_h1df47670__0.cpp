// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VBoothRadix4.h for the primary calling header

#include "VBoothRadix4__pch.h"
#include "VBoothRadix4___024root.h"

VL_INLINE_OPT void VBoothRadix4___024root___ico_sequent__TOP__0(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___ico_sequent__TOP__0\n"); );
    // Body
    vlSelf->done = 0U;
    vlSelf->BoothRadix4__DOT__state_next = vlSelf->BoothRadix4__DOT__state_reg;
    vlSelf->BoothRadix4__DOT__mcand_next = vlSelf->BoothRadix4__DOT__mcand_reg;
    vlSelf->BoothRadix4__DOT__prod_next = vlSelf->BoothRadix4__DOT__prod_reg;
    if ((1U == (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
        if (vlSelf->start) {
            vlSelf->BoothRadix4__DOT__state_next = 2U;
            vlSelf->BoothRadix4__DOT__mcand_next = vlSelf->mcand;
            vlSelf->BoothRadix4__DOT__prod_next = ((QData)((IData)(vlSelf->mplier)) 
                                                   << 1U);
        } else {
            vlSelf->BoothRadix4__DOT__mcand_next = vlSelf->BoothRadix4__DOT__mcand_reg;
        }
    } else if ((2U == (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
        if (((9U == (IData)(vlSelf->BoothRadix4__DOT__q_reg)) 
             & (~ (IData)(vlSelf->start)))) {
            vlSelf->BoothRadix4__DOT__state_next = 1U;
        }
        vlSelf->BoothRadix4__DOT__prod_next = ((1U 
                                                & (IData)(
                                                          (vlSelf->BoothRadix4__DOT__prod_reg 
                                                           >> 1U)))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->BoothRadix4__DOT__prod_reg))
                                                    ? 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U))))) 
                                                      << 0x25U) 
                                                     | (0x1fffffffffULL 
                                                        & (vlSelf->BoothRadix4__DOT__prod_reg 
                                                           >> 1U)))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          - 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U)))))))
                                                    : 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          - 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          - 
                                                                          ((0x80000U 
                                                                            & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                               << 2U)) 
                                                                           | (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                              << 1U)))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->BoothRadix4__DOT__prod_reg))
                                                    ? 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          + 
                                                                          ((0x80000U 
                                                                            & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                               << 2U)) 
                                                                           | (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                              << 1U)))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          + 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U)))))))
                                                    : 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          + 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U))))) 
                                                      << 0x25U) 
                                                     | (0x1fffffffffULL 
                                                        & (vlSelf->BoothRadix4__DOT__prod_reg 
                                                           >> 1U))))));
    }
    vlSelf->BoothRadix4__DOT__q_add = 0U;
    vlSelf->BoothRadix4__DOT__q_reset = 0U;
    if ((1U != (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
        if ((2U == (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
            vlSelf->BoothRadix4__DOT__q_add = 1U;
            if (((9U == (IData)(vlSelf->BoothRadix4__DOT__q_reg)) 
                 & (~ (IData)(vlSelf->start)))) {
                vlSelf->done = 1U;
                vlSelf->BoothRadix4__DOT__q_add = 0U;
                vlSelf->BoothRadix4__DOT__q_reset = 1U;
            }
        }
    }
    vlSelf->BoothRadix4__DOT__q_next = (0x1fU & ((0U 
                                                  == 
                                                  (((IData)(vlSelf->BoothRadix4__DOT__q_reset) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->BoothRadix4__DOT__q_add)))
                                                  ? (IData)(vlSelf->BoothRadix4__DOT__q_reg)
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (((IData)(vlSelf->BoothRadix4__DOT__q_reset) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->BoothRadix4__DOT__q_add)))
                                                   ? 
                                                  ((IData)(1U) 
                                                   + (IData)(vlSelf->BoothRadix4__DOT__q_reg))
                                                   : 0U)));
}

void VBoothRadix4___024root___eval_ico(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        VBoothRadix4___024root___ico_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
}

void VBoothRadix4___024root___eval_triggers__ico(VBoothRadix4___024root* vlSelf);

bool VBoothRadix4___024root___eval_phase__ico(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VBoothRadix4___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        VBoothRadix4___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VBoothRadix4___024root___eval_act(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_act\n"); );
}

VL_INLINE_OPT void VBoothRadix4___024root___nba_sequent__TOP__0(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->BoothRadix4__DOT__result_reg = ((IData)(vlSelf->n_reset) 
                                            && (1U 
                                                & (IData)(vlSelf->BoothRadix4__DOT__prod_next)));
    if (vlSelf->done) {
        vlSelf->product = (0xfffffffffULL & (vlSelf->BoothRadix4__DOT__prod_reg 
                                             >> 1U));
    }
    if (vlSelf->n_reset) {
        vlSelf->BoothRadix4__DOT__mcand_reg = vlSelf->BoothRadix4__DOT__mcand_next;
        vlSelf->BoothRadix4__DOT__q_reg = vlSelf->BoothRadix4__DOT__q_next;
        vlSelf->BoothRadix4__DOT__state_reg = vlSelf->BoothRadix4__DOT__state_next;
        vlSelf->BoothRadix4__DOT__prod_reg = (((QData)((IData)(
                                                               (1U 
                                                                & (IData)(
                                                                          (vlSelf->BoothRadix4__DOT__prod_next 
                                                                           >> 0x25U))))) 
                                               << 0x25U) 
                                              | (0x1fffffffffULL 
                                                 & (vlSelf->BoothRadix4__DOT__prod_next 
                                                    >> 1U)));
    } else {
        vlSelf->BoothRadix4__DOT__mcand_reg = 0U;
        vlSelf->BoothRadix4__DOT__q_reg = 0U;
        vlSelf->BoothRadix4__DOT__state_reg = 1U;
        vlSelf->BoothRadix4__DOT__prod_reg = 0ULL;
    }
    vlSelf->done = 0U;
    vlSelf->BoothRadix4__DOT__state_next = vlSelf->BoothRadix4__DOT__state_reg;
    vlSelf->BoothRadix4__DOT__mcand_next = vlSelf->BoothRadix4__DOT__mcand_reg;
    vlSelf->BoothRadix4__DOT__q_add = 0U;
    vlSelf->BoothRadix4__DOT__q_reset = 0U;
    if ((1U != (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
        if ((2U == (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
            vlSelf->BoothRadix4__DOT__q_add = 1U;
            if (((9U == (IData)(vlSelf->BoothRadix4__DOT__q_reg)) 
                 & (~ (IData)(vlSelf->start)))) {
                vlSelf->done = 1U;
                vlSelf->BoothRadix4__DOT__q_add = 0U;
                vlSelf->BoothRadix4__DOT__q_reset = 1U;
            }
        }
    }
    vlSelf->BoothRadix4__DOT__q_next = (0x1fU & ((0U 
                                                  == 
                                                  (((IData)(vlSelf->BoothRadix4__DOT__q_reset) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->BoothRadix4__DOT__q_add)))
                                                  ? (IData)(vlSelf->BoothRadix4__DOT__q_reg)
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (((IData)(vlSelf->BoothRadix4__DOT__q_reset) 
                                                     << 1U) 
                                                    | (IData)(vlSelf->BoothRadix4__DOT__q_add)))
                                                   ? 
                                                  ((IData)(1U) 
                                                   + (IData)(vlSelf->BoothRadix4__DOT__q_reg))
                                                   : 0U)));
    vlSelf->BoothRadix4__DOT__prod_next = vlSelf->BoothRadix4__DOT__prod_reg;
    if ((1U == (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
        if (vlSelf->start) {
            vlSelf->BoothRadix4__DOT__state_next = 2U;
            vlSelf->BoothRadix4__DOT__mcand_next = vlSelf->mcand;
            vlSelf->BoothRadix4__DOT__prod_next = ((QData)((IData)(vlSelf->mplier)) 
                                                   << 1U);
        } else {
            vlSelf->BoothRadix4__DOT__mcand_next = vlSelf->BoothRadix4__DOT__mcand_reg;
        }
    } else if ((2U == (IData)(vlSelf->BoothRadix4__DOT__state_reg))) {
        if (((9U == (IData)(vlSelf->BoothRadix4__DOT__q_reg)) 
             & (~ (IData)(vlSelf->start)))) {
            vlSelf->BoothRadix4__DOT__state_next = 1U;
        }
        vlSelf->BoothRadix4__DOT__prod_next = ((1U 
                                                & (IData)(
                                                          (vlSelf->BoothRadix4__DOT__prod_reg 
                                                           >> 1U)))
                                                ? (
                                                   (1U 
                                                    & (IData)(vlSelf->BoothRadix4__DOT__prod_reg))
                                                    ? 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U))))) 
                                                      << 0x25U) 
                                                     | (0x1fffffffffULL 
                                                        & (vlSelf->BoothRadix4__DOT__prod_reg 
                                                           >> 1U)))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          - 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U)))))))
                                                    : 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          - 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          - 
                                                                          ((0x80000U 
                                                                            & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                               << 2U)) 
                                                                           | (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                              << 1U)))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))))
                                                : (
                                                   (1U 
                                                    & (IData)(vlSelf->BoothRadix4__DOT__prod_reg))
                                                    ? 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          + 
                                                                          ((0x80000U 
                                                                            & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                               << 2U)) 
                                                                           | (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                              << 1U)))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          + 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U)))))))
                                                    : 
                                                   ((IData)(vlSelf->BoothRadix4__DOT__result_reg)
                                                     ? 
                                                    (((QData)((IData)(
                                                                      (0xfffffU 
                                                                       & (((0x80000U 
                                                                            & ((IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U)) 
                                                                               << 0x13U)) 
                                                                           | (0x7ffffU 
                                                                              & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x13U)))) 
                                                                          + 
                                                                          ((0xc0000U 
                                                                            & ((- (IData)(
                                                                                (1U 
                                                                                & (vlSelf->BoothRadix4__DOT__mcand_reg 
                                                                                >> 0x11U)))) 
                                                                               << 0x12U)) 
                                                                           | vlSelf->BoothRadix4__DOT__mcand_reg))))) 
                                                      << 0x12U) 
                                                     | (QData)((IData)(
                                                                       (0x3ffffU 
                                                                        & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 1U))))))
                                                     : 
                                                    (((QData)((IData)(
                                                                      (1U 
                                                                       & (IData)(
                                                                                (vlSelf->BoothRadix4__DOT__prod_reg 
                                                                                >> 0x25U))))) 
                                                      << 0x25U) 
                                                     | (0x1fffffffffULL 
                                                        & (vlSelf->BoothRadix4__DOT__prod_reg 
                                                           >> 1U))))));
    }
}

void VBoothRadix4___024root___eval_nba(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VBoothRadix4___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
}

void VBoothRadix4___024root___eval_triggers__act(VBoothRadix4___024root* vlSelf);

bool VBoothRadix4___024root___eval_phase__act(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VBoothRadix4___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        VBoothRadix4___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VBoothRadix4___024root___eval_phase__nba(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        VBoothRadix4___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__ico(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__nba(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VBoothRadix4___024root___dump_triggers__act(VBoothRadix4___024root* vlSelf);
#endif  // VL_DEBUG

void VBoothRadix4___024root___eval(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            VBoothRadix4___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/BoothRadix4.v", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VBoothRadix4___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            VBoothRadix4___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/BoothRadix4.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                VBoothRadix4___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/BoothRadix4.v", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (VBoothRadix4___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (VBoothRadix4___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VBoothRadix4___024root___eval_debug_assertions(VBoothRadix4___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    VBoothRadix4__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    VBoothRadix4___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->mplier & 0xfffc0000U))) {
        Verilated::overWidthError("mplier");}
    if (VL_UNLIKELY((vlSelf->mcand & 0xfffc0000U))) {
        Verilated::overWidthError("mcand");}
    if (VL_UNLIKELY((vlSelf->n_reset & 0xfeU))) {
        Verilated::overWidthError("n_reset");}
    if (VL_UNLIKELY((vlSelf->start & 0xfeU))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
}
#endif  // VL_DEBUG
