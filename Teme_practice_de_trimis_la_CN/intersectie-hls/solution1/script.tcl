############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project intersectie-hls
set_top intersectie
add_files intersectie-hls/intersectie.cpp
add_files -tb intersectie-hls/intersectie.h -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
add_files -tb intersectie-hls/intersectie_test.cpp -cflags "-Wno-unknown-pragmas" -csimflags "-Wno-unknown-pragmas"
open_solution "solution1" -flow_target vivado
set_part {xc7a100t-csg324-1}
create_clock -period 10 -name default
source "./intersectie-hls/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
