############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project conv_1
set_top conv1_1
add_files ../C_implementation/lenet5.c
add_files -tb ../C_implementation/prog.c
open_solution "solution1"
set_part {xc7z010clg400-2}
create_clock -period 10 -name default
#source "./conv_1/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
