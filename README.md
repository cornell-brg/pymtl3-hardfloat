pymtl3-hardfloat
================

[![Build Status](https://travis-ci.com/pymtl/pymtl3-hardfloat.svg?branch=master)](https://travis-ci.com/pymtl/pymtl3-hardfloat)

# PyMTL3 wrapper of the Berkeley Hardfloat IP
It includes support for half-precision (16-bit), single-precision (32-bit), and double-precision (64-bit) floating point arithmetic (addition, subtraction, multiplication). The following tutorial allows you to run the entire test harness currently available for pymtl3-hardfloat, which include a C++ test suite from Berkeley, as well as a Python test suite provided by Batten Research Group.

### Installing PyMTL3

See https://github.com/pymtl/pymtl3#installation

### Setting up the pymtl3-hardfloat repo on brg-vip
```
$ cd /work/global/<net_id>/
$ git clone https://github.com/cornell-brg/pymtl3-hardfloat.git
$ cd pymtl3-hardfloat
$ git checkout master
$ HOME=$PWD
```

### Running C++ test cases provided by the Berkeley Hardfloat IP
```
$ cd $HOME/sim/HardFloat/test/build/Verilator-GCC
$ make test-level1
```

*This command runs all level1 tests for all modules inside HardFloat. For more information on how to run specific commands please visit Berkeley's Hardfloat IP Documentation: http://www.jhauser.us/arithmetic/HardFloat-1/doc/HardFloat-test-Verilator.html*

### Running PyMTL3 test cases which include directed, random, and hypothesis testing
```
$ cd $HOME/sim
$ mkdir build
$ cd build/
$ pytest ../HardFloat/test/ -v
```

*This commands runs all PyMTL3 provided tests, which include testing for addition, multiplication, and multiply-add modules. For the detailed list of test files, simply execute the following command*

```
$ ls $HOME/sim/HardFloat/test
```
