#=========================================================================
# VRecFNToFN__expWidth_5__sigWidth_11_v.py
#=========================================================================
"""Provide a template of PyMTL wrapper to import verilated models.

This wrapper makes a Verilator-generated C++ model appear as if it were a
normal PyMTL model. This template is based on PyMTL v2.
"""

import os

from cffi  import FFI

from pymtl3.datatypes import *
from pymtl3.dsl import Component, connect, InPort, OutPort, Wire, M, U, RD, WR

# def full_vector( wire, signal ):

#   def to_string( num, nbits ):
#     ndigits = (nbits-1)//4+1
#     return "{0:#0{1}x}".format( num, ndigits+2 )

#   nbits = wire.nbits
#   if nbits <= 64:
#     return to_string( signal[0], nbits )
#   else:
#     ret = ""
#     num_elements = (nbits-1)//32+1
#     for idx in range(num_elements):
#       _nbits = 32 if idx != num_elements-1 else nbits%32
#       ret = to_string( signal[idx], _nbits )[2:] + ret
#     return "0x" + ret

#-------------------------------------------------------------------------
# RecFNToFN__expWidth_5__sigWidth_11
#-------------------------------------------------------------------------

class RecFNToFN__expWidth_5__sigWidth_11( Component ):
  id_ = 0

  def __init__( s, *args, **kwargs ):
    s._finalization_count = 0

    # initialize FFI, define the exposed interface
    s.ffi = FFI()
    s.ffi.cdef("""
      typedef struct {

        // Exposed port interface
        unsigned int * in_;        
        unsigned short * out;

        // Verilator model
        void * model;

      } VRecFNToFN__expWidth_5__sigWidth_11_t;

      VRecFNToFN__expWidth_5__sigWidth_11_t * create_model( const char * );
      void destroy_model( VRecFNToFN__expWidth_5__sigWidth_11_t *);
      void eval( VRecFNToFN__expWidth_5__sigWidth_11_t * );
      void assert_en( bool en );
      

    """)

    # Print the modification time stamp of the shared lib
    # print 'Modification time of {}: {}'.format(
    #   'libRecFNToFN__expWidth_5__sigWidth_11_v.so', os.path.getmtime( './libRecFNToFN__expWidth_5__sigWidth_11_v.so' ) )

    # Import the shared library containing the model. We defer
    # construction to the elaborate_logic function to allow the user to
    # set the vcd_file.
    s._ffi_inst = s.ffi.dlopen('./libRecFNToFN__expWidth_5__sigWidth_11_v.so')

    # increment instance count
    RecFNToFN__expWidth_5__sigWidth_11.id_ += 1

  def finalize( s ):
    """Finalize the imported component.

    This method closes the shared library opened through CFFI. If an imported
    component is not finalized explicitly (i.e. if you rely on GC to collect a
    no longer used imported component), importing a component with the same
    name before all previous imported components are GCed might lead to
    confusing behaviors. This is because once opened, the shared lib
    is cached by the OS until the OS reference counter for this lib reaches
    0 (you can decrement the reference counter by calling `dl_close()` syscall).

    Fortunately real designs tend to always have the same shared lib corresponding
    to the components with the same name. If you are doing translation testing and
    use the same component class name even if they refer to different designs,
    you might need to call `imported_object.finalize()` at the end of each test
    to ensure correct behaviors.
    """
    assert s._finalization_count == 0,\
      'Imported component can only be finalized once!'
    s._finalization_count += 1
    s._ffi_inst.destroy_model( s._ffi_m )
    s.ffi.dlclose( s._ffi_inst )
    s.ffi = None
    s._ffi_inst = None

  def __del__( s ):
    if s._finalization_count == 0:
      s._finalization_count += 1
      s._ffi_inst.destroy_model( s._ffi_m )
      s.ffi.dlclose( s._ffi_inst )
      s.ffi = None
      s._ffi_inst = None

  def construct( s, *args, **kwargs ):
    # Set up the VCD file name
    verilator_vcd_file = ""
    if 0:
      if False:
        verilator_vcd_file = ".vcd"
      else:
        verilator_vcd_file = "RecFNToFN__expWidth_5__sigWidth_11.verilator1.vcd"

    # Convert string to `bytes` which is required by CFFI on python 3
    verilator_vcd_file = verilator_vcd_file.encode('ascii')

    # Construct the model
    s._ffi_m = s._ffi_inst.create_model( s.ffi.new("char[]", verilator_vcd_file) )

    # Buffer for line tracing
    s._line_trace_str = s.ffi.new('char[512]')
    s._convert_string = s.ffi.string

    # Use non-attribute varialbe to reduce CPython bytecode count
    _ffi_m = s._ffi_m
    _ffi_inst = s._ffi_inst

    # declare the port interface
    s.in_ = InPort( Bits17 )
    s.out = OutPort( Bits16 )

    # update blocks that converts ffi interface to/from pymtl ports
    s.s_DOT_in_ = Wire( Bits17 )
    @s.update
    def isignal_s_DOT_in_():
      s.s_DOT_in_ = s.in_
    s.s_DOT_out = Wire( Bits16 )
    @s.update
    def osignal_s_DOT_out():
      s.out = s.s_DOT_out

    @s.update
    def comb_upblk():
      # Set inputs
      _ffi_m.in_[0] = int(s.s_DOT_in_)

      _ffi_inst.eval( _ffi_m )

      # Write all outputs
      s.s_DOT_out = Bits16(_ffi_m.out[0])

    if 0:
      @s.update_ff
      def seq_upblk():
        # Advance the clock
        _ffi_m.inv_clk[0] = 0
        _ffi_inst.eval( _ffi_m )
        _ffi_m.inv_clk[0] = 1
        _ffi_inst.eval( _ffi_m )

  def assert_en( s, en ):
    # TODO: for verilator, any assertion failure will cause the C simulator
    # to abort, which results in a Python internal error. A better approach
    # is to throw a Python exception at the time of assertion failure.
    # Verilator allows user-defined `stop` function which is called when
    # the simulation is expected to stop due to various reasons. We might
    # be able to raise a Python exception through Python C API (although
    # at this moment I'm not sure if the C API's are compatible between
    # PyPy and CPython).
    assert isinstance( en, bool )
    s._ffi_inst.assert_en( en )

  def line_trace( s ):
    if 0:
      s._ffi_inst.trace( s._ffi_m, s._line_trace_str )
      return s._convert_string( s._line_trace_str ).decode('ascii')
    else:
      return f' in_={s.in_}, out={s.out},'

  def internal_line_trace( s ):
    return ''
