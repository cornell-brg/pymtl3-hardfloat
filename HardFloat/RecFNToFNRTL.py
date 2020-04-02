#=========================================================================
# Wrapper for HardFloat's format conversion (from recorded to standard) module
#=========================================================================

from pymtl3 import *
from pymtl3.passes.backends.verilog import \
    VerilogPlaceholderConfigs, VerilatorImportConfigs, TranslationConfigs

class RecFNToFN( Placeholder, Component ):

  # Constructor

  def construct( s, expWidth = 5, sigWidth = 11 ):

    # Interface

    s.in_            = InPort ( mk_bits(expWidth + sigWidth + 1) )
    
    s.out            = OutPort ( mk_bits(expWidth + sigWidth) )

    # Configurations

    from os import path
    s.config_placeholder = VerilogPlaceholderConfigs(
      src_file   = path.dirname(__file__) + '/source/recFNToFN.v',
      top_module = 'recFNToFN',
      v_include  = [ path.dirname(__file__) + '/source' ],
      v_libs     = [
        path.dirname(__file__) + '/source/HardFloat_primitives.v',
        path.dirname(__file__) + '/source/isSigNaNRecFN.v',
        path.dirname(__file__) + '/source/HardFloat_rawFN.v',
        path.dirname(__file__) + '/source/recFNToRecFN.v',
        path.dirname(__file__) + '/source/HardFloat_specialize.vi',
      ],
      has_clk    = False,
      has_reset  = False,
    )

    s.config_verilog_import = VerilatorImportConfigs(
      vl_Wno_list = ['WIDTH'], # to surpress some Verilator warnings
    )

    s.verilog_translate_import = True