`ifndef __ARM_VFPV2_HARDFLOAT_SPECIALIZE_V__
`define __ARM_VFPV2_HARDFLOAT_SPECIALIZE_V__

/*============================================================================

This Verilog source file is part of the Berkeley HardFloat IEEE Floating-Point
Arithmetic Package, Release 1, by John R. Hauser.

Copyright 2019 The Regents of the University of California.  All rights
reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice,
    this list of conditions, and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions, and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

 3. Neither the name of the University nor the names of its contributors may
    be used to endorse or promote products derived from this software without
    specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS "AS IS", AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE, ARE
DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

=============================================================================*/

`include "HardFloat_consts.vi"
`include "HardFloat_specialize.vi"

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

module
    iNFromException#(parameter width = 1) (
        input signedOut,
        input isNaN,
        input sign,
        output [(width - 1):0] out
    );

    assign out =
        {!isNaN && (signedOut == sign), {(width - 1){!isNaN && !sign}}};

endmodule

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

module
    propagateFloatNaN_add#(parameter sigWidth = 3) (
        input [(`floatControlWidth - 1):0] control,
        input subOp,
        input isNaNA,
        input signA,
        input [(sigWidth - 2):0] fractA,
        input isNaNB,
        input signB,
        input [(sigWidth - 2):0] fractB,
        output signNaN,
        output [(sigWidth - 2):0] fractNaN
    );

    wire selectA =
        isNaNA && (!isNaNB || !fractA[sigWidth - 2] || fractB[sigWidth - 2]);
    wire selectB =
        isNaNB && (!isNaNA || (!fractB[sigWidth - 2] && fractA[sigWidth - 2]));
    assign signNaN = (selectA && signA) || (selectB && signB);
    assign fractNaN =
        {1'b1,
           (selectA ? fractA[(sigWidth - 3):0] : 1'b0)
         | (selectB ? fractB[(sigWidth - 3):0] : 1'b0)};

endmodule

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

module
    propagateFloatNaN_mul#(parameter sigWidth = 3) (
        input [(`floatControlWidth - 1):0] control,
        input isNaNA,
        input signA,
        input [(sigWidth - 2):0] fractA,
        input isNaNB,
        input signB,
        input [(sigWidth - 2):0] fractB,
        output signNaN,
        output [(sigWidth - 2):0] fractNaN
    );

    wire selectA =
        isNaNA && (!isNaNB || !fractA[sigWidth - 2] || fractB[sigWidth - 2]);
    wire selectB =
        isNaNB && (!isNaNA || (!fractB[sigWidth - 2] && fractA[sigWidth - 2]));
    assign signNaN = (selectA && signA) || (selectB && signB);
    assign fractNaN =
        {1'b1,
           (selectA ? fractA[(sigWidth - 3):0] : 1'b0)
         | (selectB ? fractB[(sigWidth - 3):0] : 1'b0)};

endmodule

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

module
    propagateFloatNaN_mulAdd#(parameter sigWidth = 3) (
        input [(`floatControlWidth - 1):0] control,
        input [1:0] op,
        input isNaNA,
        input signA,
        input [(sigWidth - 2):0] fractA,
        input isNaNB,
        input signB,
        input [(sigWidth - 2):0] fractB,
        input invalidProd,
        input isNaNC,
        input signC,
        input [(sigWidth - 2):0] fractC,
        output signNaN,
        output [(sigWidth - 2):0] fractNaN
    );

    wire isSigNaNC = isNaNC && !fractC[sigWidth - 2];
    wire selectA =
        isNaNA && !isSigNaNC
            && (!isNaNB || !fractA[sigWidth - 2] || fractB[sigWidth - 2]);
    wire selectB =
        isNaNB && !isSigNaNC
            && (!isNaNA || (!fractB[sigWidth - 2] && fractA[sigWidth - 2]));
    wire isNaNProd = isNaNA || isNaNB || invalidProd;
    wire selectC = isNaNC && (!isNaNProd || !fractC[sigWidth - 2]);
    assign signNaN =
        (selectA && signA) || (selectB && signB) || (selectC && signC);
    assign fractNaN =
        {1'b1,
           (selectA ? fractA[(sigWidth - 3):0] : 1'b0)
         | (selectB ? fractB[(sigWidth - 3):0] : 1'b0)
         | (selectC ? fractC[(sigWidth - 3):0] : 1'b0)};

endmodule

/*----------------------------------------------------------------------------
*----------------------------------------------------------------------------*/

module
    propagateFloatNaN_divSqrt#(parameter sigWidth = 3) (
        input [(`floatControlWidth - 1):0] control,
        input sqrtOp,
        input isNaNA,
        input signA,
        input [(sigWidth - 2):0] fractA,
        input isNaNB,
        input signB,
        input [(sigWidth - 2):0] fractB,
        output signNaN,
        output [(sigWidth - 2):0] fractNaN
    );

    wire isTrueNaNB = !sqrtOp && isNaNB;
    wire selectA =
        isNaNA
            && (!isTrueNaNB || !fractA[sigWidth - 2] || fractB[sigWidth - 2]);
    wire selectB =
        isTrueNaNB
            && (!isNaNA || (!fractB[sigWidth - 2] && fractA[sigWidth - 2]));
    assign signNaN = (selectA && signA) || (selectB && signB);
    assign fractNaN =
        {1'b1,
           (selectA ? fractA[(sigWidth - 3):0] : 1'b0)
         | (selectB ? fractB[(sigWidth - 3):0] : 1'b0)};

endmodule

`endif /* __ARM_VFPV2_HARDFLOAT_SPECIALIZE_V__ */
