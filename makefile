# make clean && make && make waves
# make rtl_test
MODULE=riscv

VSRCS:=$(wildcard ./rtl/*.v) $(wildcard ./rtl/vec/*.v)
CSRCS:= ./test/tb_$(MODULE).cpp ./test/uvm.cpp ./test/isa_gen.cpp ./test/data_hazard_gen.cpp
RTL_TEST_CSRC:=./test/tb_rtl.cpp ./test/uvm.cpp ./test/isa_gen.cpp ./test/data_hazard_gen.cpp

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/Vriscv

.PHONY:waves
waves: waveform.vcd
	@echo
	@echo "### WAVES ###"
	gtkwave -S gtkwave.tcl waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE)

./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -j -C obj_dir -f V$(MODULE).mk V$(MODULE) CXXFLAGS="-g"

.stamp.verilate: ./rtl/$(MODULE).v $(CSRCS)
	@echo
	@echo "### VERILATING ###"
	verilator --trace -cc $(VSRCS) --exe $(CSRCS) --top-module riscv
	@touch .stamp.verilate

.PHONY:lint
lint: $(MODULE).v
	verilator --lint-only $(MODULE).v

# debug build start
.PHONY:debug
debug: .stamp.verilate_debug

.stamp.verilate_debug: ./rtl/$(MODULE).v $(CSRCS)
	@echo
	@echo "### VERILATING IN DEBUG MODE ###"
	verilator --trace -cc $(VSRCS) --exe $(CSRCS) --top-module $(MODULE) --debug  --gdbbt
	@touch .stamp.verilate_debug

# debug build end

##############################
# rtl test build start
##############################
.PHONY: verilate_rtl_test
verilate_rtl_test: .stamp.verilate_rtl_test

.PHONY: build_rtl_test
build_rtl_test: ./obj_dir/Vtest

.PHONY: waves_rtl_test
waves_rtl_test: waveform_rtl_test.vcd
	@echo
	@echo "### WAVES RTL TEST ###"
	gtkwave -S gtkwave.tcl waveform_rtl_test.vcd

waveform_rtl_test.vcd: ./obj_dir/Vtest
	@echo
	@echo "### SIMULATING RTL TEST ###"
	@./obj_dir/Vtest

./obj_dir/Vtest: .stamp.verilate_rtl_test
	@echo
	@echo "### BUILDING RTL TEST SIM ###"
	make -j -C obj_dir -f Vtest.mk Vtest CXXFLAGS="-g"

.stamp.verilate_rtl_test: ./rtl/test.v $(RTL_TEST_CSRC)
	@echo
	@echo "### VERILATING RTL TEST ###"
	verilator -Wno-caseincomplete -Wno-width -Wno-latch -Wno-unoptflat --trace -cc $(VSRCS) --exe $(RTL_TEST_CSRC) --top-module test
	@touch .stamp.verilate_rtl_test

.PHONY: run_rtl_test
run_rtl_test: verilate_rtl_test build_rtl_test waves_rtl_test
	@echo
	@echo "### RTL TEST COMPLETE ###"
##############################
# rtl test build end
##############################

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm ./waveform_rtl_test.vcd
	rm ./waveform_rtl_test.vcd.pdf
	rm -rf waveform.vcd
	rm -rf waveform.vcd.pdf
	rm ./test/registers.txt
	rm ./test/simulator_output.txt
	rm ./test/memory.txt
	rm ./test/test.asm
