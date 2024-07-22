
#include "isa_gen.hpp"
#include "uvm.hpp"

/*
x0 (zero) - Always holds the constant value 0.
x1 (ra) - Return address for function calls.
x2 (sp) - Stack pointer.
x3 (gp) - Global pointer.
x4 (tp) - Thread pointer.
x5 (t0) - Temporary register.
x6 (t1) - Temporary register.
x7 (t2) - Temporary register.
x8 (s0/fp) - Saved register/frame pointer.
x9 (s1) - Saved register.
x10 (a0) - Function argument/return value.
x11 (a1) - Function argument/return value.
x12 (a2) - Function argument.
x13 (a3) - Function argument.
x14 (a4) - Function argument.
x15 (a5) - Function argument.
x16 (a6) - Function argument.
x17 (a7) - Function argument.
x18 (s2) - Saved register.
x19 (s3) - Saved register.
x20 (s4) - Saved register.
x21 (s5) - Saved register.
x22 (s6) - Saved register.
x23 (s7) - Saved register.
x24 (s8) - Saved register.
x25 (s9) - Saved register.
x26 (s10) - Saved register.
x27 (s11) - Saved register.
x28 (t3) - Temporary register.
x29 (t4) - Temporary register.
x30 (t5) - Temporary register.
x31 (t6) - Temporary register
*/

int main() {
    RTypeInstr addInstr(1, 2, 3, RTypeInstr::RTypeOps::ADD);
    ITypeInstr sraiInstr(5, 4, 100, ITypeInstr::ITypeOps::SRAI);
    ITypeInstr srliInstr(5, 4, 100, ITypeInstr::ITypeOps::SRLI);
    LoadInstr lwInstr(5, 4, 100, LoadInstr::LoadOps::LW);
    StoreInstr swInstr(5, 4, 100, StoreInstr::StoreOps::SW);
    BTypeInstr beqInstr(5, 4, 100, BTypeInstr::BTypeOps::BEQ);
    JTypeInstr jalInstr(7, 1000);
    JALRInstr jalrInstr(7, 6, 1000);
    std::cout << "Encoded: 0x" << std::hex << addInstr.encode() << " " << addInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << sraiInstr.encode() << " "<< sraiInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << srliInstr.encode() << " "<< srliInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << lwInstr.encode() << " " << lwInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << swInstr.encode() << " " << swInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << beqInstr.encode() << " " << beqInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << jalInstr.encode() << " " << jalInstr.toString() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << jalrInstr.encode() << " " << jalrInstr.toString() << std::endl;


    std::cout << "Sequencer test start" << std::endl;
    //// Define allowed registers and operations (example values)
    std::unordered_set<uint8_t> allowedRegisters = {
    0,
    5,
    6,
    7,
    8,
    9,
    10,
    11,
    12,
    13,
    14,
    15,
    16,
    17,
    18,
    19,
    20,
    21,
    22,
    23,
    24,
    25,
    26,
    27,
    28,
    29,
    30,
    31
};
    std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps = {RTypeInstr::RTypeOps::ADD, RTypeInstr::RTypeOps::SUB};
    std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps = {ITypeInstr::ITypeOps::ADDI};
    std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps = {BTypeInstr::BTypeOps::BEQ};
    std::unordered_set<LoadInstr::LoadOps> allowedLoadOps = {LoadInstr::LoadOps::LW};
    std::unordered_set<StoreInstr::StoreOps> allowedStoreOps = {StoreInstr::StoreOps::SW};

    int16_t mem_start = 0;
    int16_t mem_end = 1024;

    RiscvSequencer sequencer(allowedRegisters, allowedRTypeOps, allowedITypeOps, allowedBTypeOps, allowedLoadOps, allowedStoreOps, mem_start, mem_end);

    RiscvInTx tt = sequencer.generateRandomInstructions(10);

    for (const auto& instr : tt.instructions) {
        std::cout << "Test 0x" << instr->toString() << std::endl;
    }

    Vriscv dut;
    RiscvScoreBoard scb;

    RiscvInDriver inDriver(&dut, &scb);

    inDriver.drive(&tt);

    RiscvOutMonitor outMonitor(&dut, &scb);

    // run simulation

    outMonitor.monitor();




    //for (const auto& instr : tt.instructions) {
    //    // Print or process the instructions
    //    // Example: std::cout << instr->toString() << std::endl;
    //    std::cout << "Test 0x" << std::hex << instr->encode() << std::endl;
    //}

    return 0;
}
