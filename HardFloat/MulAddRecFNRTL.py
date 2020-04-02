#=========================================================================
# Wrapper for HardFloat's multiplication module
#=========================================================================

from pymtl3 import *
from pymtl3.passes.backends.verilog import \
    VerilogPlaceholderConfigs, VerilatorImportConfigs, TranslationConfigs

class MulAddRecFN( Placeholder, Component ):

  # Constructor

  def construct( s, expWidth = 5, sigWidth = 11 ):

    # Interface
	
    s.control        = InPort ()
    s.op             = InPort ( Bits2 )
    s.a              = InPort ( mk_bits(expWidth + sigWidth + 1) )
    s.b              = InPort ( mk_bits(expWidth + sigWidth + 1) )
    s.c              = InPort ( mk_bits(expWidth + sigWidth + 1) )
    s.roundingMode   = InPort ( Bits3 ) 
    
    s.out            = OutPort ( mk_bits(expWidth + sigWidth + 1) )
    s.exceptionFlags = OutPort ( Bits5 )

    # Configurations

    from os import path
    s.config_placeholder = VerilogPlaceholderConfigs(
      src_file   = path.dirname(__file__) + '/source/mulAddRecFN.v',
      top_module = 'mulAddRecFN',
      v_include  = [ path.dirname(__file__) + '/source' ],
      v_libs     = [
        path.dirname(__file__) + '/source/HardFloat_primitives.v',
        path.dirname(__file__) + '/source/isSigNaNRecFN.v',
        path.dirname(__file__) + '/source/HardFloat_rawFN.v',
      ],
      has_clk    = False,
      has_reset  = False,
    )

    s.config_verilog_import = VerilatorImportConfigs(
      vl_Wno_list = ['WIDTH'], # to surpress some Verilator warnings
    )

    s.verilog_translate_import = True