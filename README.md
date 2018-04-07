# Exception Handling Costing Test

## Introduction

This program performs a minimal comparative test of executable size and performance with C++ 
exception handling and run-time type information *enabled* and *disabled*. It is intended to test 
the assertion that C++ supports only zero-cost abstractions with whatever compiler is installed on 
the host system (using the `c++` command). It runs a simple program that calls a destructor 
multiple times. The aim of the program is to create a situation where a thrown exception would 
require a separate code path.

Notes:
1. With exceptions disabled, the program is *not* ISO C++ compliant;
   this tests a non-standard implementation feature.
2. This program makes no used of exceptions. The suggestion is that *if* it produces a larger 
   executable or runs more slowly with your tool chain when exceptions are *enabled*, then you are 
   paying for a feature -- even when you don't use it.

## Requirements

* A UN*X-like command line interpreter and tools
* C++ compiler:
  * [GCC](https://gcc.gnu.org/) 
  * [Clang](https://clang.llvm.org/)
* [cmake](https://cmake.org/)
* [time](http://man7.org/linux/man-pages/man1/time.1.html)

## Instructions

The bash script, [test.sh], builds and runs the sample program and prints out:

* The toolchain used to build the program (using the `c++` command)
* For the program built with EH/RTTI enabled:
  * the size in bytes
  * the `time` result of running the executable
* For the program built without EH/RTTI enabled:
  * the size in bytes
  * the `time` result of running the executable

It should be run from an empty directory to avoid deleting any existing files:

```
cd /tmp
mkdir ehct
cd ehct
/some/path/ehct/test.sh
```
