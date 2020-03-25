// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VrecF64ToF64__Syms_H_
#define _VrecF64ToF64__Syms_H_

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "VrecF64ToF64.h"

// SYMS CLASS
class VrecF64ToF64__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    VrecF64ToF64*                  TOPp;
    
    // CREATORS
    VrecF64ToF64__Syms(VrecF64ToF64* topp, const char* namep);
    ~VrecF64ToF64__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(64);

#endif  // guard
