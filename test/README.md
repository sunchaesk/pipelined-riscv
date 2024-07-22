java -jar rars1_6.jar asm.txt dump .text dump.txt HexText mc CompactDataAtZero 0-1000

outputs the commands to the dump.txt, runs the simulation with the memory addresses starting at index 0, and prints the memory values from 0 - 1000

### Running RARS for baseline
the UVM uses the RARS simulator for comparing with the output of the dut (pipelined riscv processor)

the UVM C++ library will make a syscall to run the RARS simulator, and uses the `parse.pl` perl script to parse the result which will then be fed back into c++.

Important files:
- test/simulator_output.txt : RARS cmd line output
- test/registers.txt : register values from RARS newline separated
- test/memory.txt : memory values from RARS newline separated
