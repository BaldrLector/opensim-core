#!/bin/bash
# Please see README.md for instructions to install 
# the dependencies for this script.
# This is a Unix Shell script that performs the following steps:
# 1. Obtain/build OpenSim's dependencies.
# 2. Build OpenSim.
# 3. Test OpenSim.
# 4. Install OpenSim.
# The script will make multiple directories adjacent to the directory
# containing this script.

git submodule update --init
cd ..
mkdir opensim_dependencies_build
cd opensim_dependencies_build
cmake ../opensim-core/dependencies
make -j8
cd ..
mkdir build
cd build
cmake ../opensim-core
make -j8
ctest -j8
make -j8 install
