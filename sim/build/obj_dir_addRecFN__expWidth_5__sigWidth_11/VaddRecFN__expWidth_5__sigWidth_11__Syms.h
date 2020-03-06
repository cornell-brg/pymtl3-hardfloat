// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VADDRECFN__EXPWIDTH_5__SIGWIDTH_11__SYMS_H_
#define _VADDRECFN__EXPWIDTH_5__SIGWIDTH_11__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VaddRecFN__expWidth_5__sigWidth_11.h"

// SYMS CLASS
class VaddRecFN__expWidth_5__sigWidth_11__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VaddRecFN__expWidth_5__sigWidth_11* TOPp;
    
    // CREATORS
    VaddRecFN__expWidth_5__sigWidth_11__Syms(VaddRecFN__expWidth_5__sigWidth_11* topp, const char* namep);
    ~VaddRecFN__expWidth_5__sigWidth_11__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
