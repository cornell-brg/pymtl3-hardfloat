// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vui64ToRecF64__Syms.h"
#include "Vui64ToRecF64.h"



// FUNCTIONS
Vui64ToRecF64__Syms::Vui64ToRecF64__Syms(Vui64ToRecF64* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
}
