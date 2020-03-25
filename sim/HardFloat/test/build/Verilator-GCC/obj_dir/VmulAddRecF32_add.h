// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VmulAddRecF32_add_H_
#define _VmulAddRecF32_add_H_

#include "verilated.h"

class VmulAddRecF32_add__Syms;

//----------

VL_MODULE(VmulAddRecF32_add) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(control,0,0);
    VL_IN8(roundingMode,2,0);
    VL_OUT8(exceptionFlags,4,0);
    VL_IN64(a,32,0);
    VL_IN64(b,32,0);
    VL_OUT64(out,32,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__invalidExc;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__out_isNaN;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__out_isInf;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__out_isZero;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__out_sign;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__intermed_compactState;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isNaNA;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isInfA;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isNaNC;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isInfC;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__doSubMags;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__opSignC;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isMinCAlign;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__CIsDominant;
        CData/*6:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__CAlignDist;
        CData/*6:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__reduced4SigC;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__CExtraMask;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__reduced4CExtra;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isNaNAny;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__notSigNaN_invalidExc;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__notNaN_addZeros;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__specialCase;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__isNaNOut;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__lowMask_CExtraMask__DOT__reverseOut;
        CData/*6:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__CDom_reduced4LowSig;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__CDom_sigExtraMask;
        CData/*6:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__notCDom_reduced4AbsSigSum;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__notCDom_sigExtraMask;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__lowMask_CDom_sigExtraMask__DOT__reverseOut;
        CData/*4:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__countLeadingZeros_notCDom__DOT__Bit__BRA__10__KET____DOT__countSoFar;
        CData/*4:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__countLeadingZeros_notCDom__DOT__Bit__BRA__20__KET____DOT__countSoFar;
        CData/*4:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__countLeadingZeros_notCDom__DOT__Bit__BRA__26__KET____DOT__countSoFar;
        CData/*5:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__lowMask_notCDom_sigExtraMask__DOT__reverseOut;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__roundMagUp;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__isNaNOut;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__common_underflow;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__commonCase;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__overflow;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__overflow_roundMagUp;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__pegMinNonzeroMagOut;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__pegMaxFiniteMagOut;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__notNaN_isInfOut;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__roundPosBit;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__anyRoundExtra;
        CData/*0:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__anyRound;
        SData/*9:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__out_sExp;
        SData/*10:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__sNatCAlignDist;
        SData/*9:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__sExpSum;
        SData/*8:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__lowMask_CDom_sigExtraMask__DOT__c;
        SData/*10:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__sRoundedExp;
        IData/*26:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__out_sig;
        IData/*25:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__intermed_highAlignedSigC;
        IData/*24:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__sigA;
        IData/*24:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__sigC;
        WData/*76:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__mainAlignedSigC[3];
        WData/*74:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__alignedSigC[3];
        WData/*74:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__sigSum[3];
        IData/*28:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__CDom_mainSig;
        IData/*25:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__notCDom_reduced2AbsSigSum;
        IData/*28:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__notCDom_mainSig;
        IData/*26:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__notCDom_sig;
        IData/*25:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__countLeadingZeros_notCDom__DOT__reverseIn;
        IData/*26:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__countLeadingZeros_notCDom__DOT__oneLeastReverseIn;
        IData/*16:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__lowMask_notCDom_sigExtraMask__DOT__c;
    };
    struct {
        IData/*22:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__common_fractOut;
        IData/*26:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__roundMask;
        IData/*24:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__genblk2__DOT__roundMask_main;
        IData/*26:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__roundPosMask;
        IData/*25:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__roundedSig;
        WData/*512:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__genblk2__DOT__lowMask_roundMask__DOT__c[17];
        IData/*24:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__roundRawOut__DOT__roundAnyRawFNToRecFN__DOT__genblk4__DOT__genblk2__DOT__lowMask_roundMask__DOT__reverseOut;
        QData/*48:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddResult;
        QData/*32:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_preMul__DOT__lowMask_CExtraMask__DOT__c;
        QData/*49:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__CDom_absSigSum;
        QData/*50:0*/ mulAddRecF32_add__DOT__mulAddRecFN__DOT__mulAddRecFNToRaw__DOT__mulAddToRaw_postMul__DOT__notCDom_absSigSum;
    };
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VmulAddRecF32_add__Syms* __VlSymsp;  // Symbol table
    
    // PARAMETERS
    // Parameters marked /*verilator public*/ for use by application code
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VmulAddRecF32_add);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VmulAddRecF32_add(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VmulAddRecF32_add();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VmulAddRecF32_add__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VmulAddRecF32_add__Syms* symsp, bool first);
  private:
    static QData _change_request(VmulAddRecF32_add__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__2(VmulAddRecF32_add__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VmulAddRecF32_add__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif // VL_DEBUG
  public:
    static void _eval_initial(VmulAddRecF32_add__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VmulAddRecF32_add__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__1(VmulAddRecF32_add__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(128);

#endif // guard
