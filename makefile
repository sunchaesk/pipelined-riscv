MODULE=riscv

VSRCS:=$(wildcard ./rtl/*.v)
CSRCS:= ./test/tb_$(MODULE).cpp ./test/uvm.cpp ./test/isa_gen.cpp

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/Valu

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
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: ./rtl/$(MODULE).v $(CSRCS)
	@echo
	@echo "### VERILATING ###"
	verilator --trace -cc $(VSRCS) --exe $(CSRCS) --top-module riscv
	@touch .stamp.verilate

.PHONY:lint
lint: $(MODULE).v
	verilator --lint-only $(MODULE).v

.PHONY:debug
debug: .stamp.verilate_debug

.stamp.verilate_debug: ./rtl/$(MODULE).v $(CSRCS)
	@echo
	@echo "### VERILATING IN DEBUG MODE ###"
	verilator --trace -cc $(VSRCS) --exe $(CSRCS) --top-module $(MODULE) --debug  --gdbbt
	@touch .stamp.verilate_debug

.PHONY: clean
clean:
	rm -rf .stamp.*;
	rm -rf ./obj_dir
	rm -rf waveform.vcd
	rm -rf waveform.vcd.pdf
	rm ./test/registers.txt
	rm ./test/simulator_output.txt
	rm ./test/memory.txt
	rm ./test/test.asm
