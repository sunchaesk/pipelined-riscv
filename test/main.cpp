// testing purposes

#include "isa_gen.hpp"
#include "uvm.hpp"

int main() {
    RTypeInstr addInstr(1, 2, 3, RTypeInstr::RTypeOps::ADD);
    ITypeInstr sraiInstr(5, 4, 100, ITypeInstr::ITypeOps::SRAI);
    ITypeInstr srliInstr(5, 4, 100, ITypeInstr::ITypeOps::SRLI);
    LoadInstr lwInstr(5, 4, 100, LoadInstr::LoadOps::LW);
    StoreInstr swInstr(5, 4, 100, StoreInstr::StoreOps::SW);
    BTypeInstr beqInstr(5, 4, 100, BTypeInstr::BTypeOps::BEQ);
    JTypeInstr jalInstr(7, 1000);
    JALRInstr jalrInstr(7, 6, 1000);
    std::cout << "Encoded: 0x" << std::hex << addInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << sraiInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << srliInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << lwInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << swInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << beqInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << jalInstr.encode() << std::endl;
    std::cout << "Encoded: 0x" << std::hex << jalrInstr.encode() << std::endl;


    std::cout << "Sequencer test start" << std::endl;
    // Define allowed registers and operations (example values)
    std::unordered_set<uint8_t> allowedRegisters = {1, 2, 3, 4, 5};
    std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps = {RTypeInstr::RTypeOps::ADD, RTypeInstr::RTypeOps::SUB};
    std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps = {ITypeInstr::ITypeOps::ADDI};
    std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps = {BTypeInstr::BTypeOps::BEQ};
    std::unordered_set<LoadInstr::LoadOps> allowedLoadOps = {LoadInstr::LoadOps::LW};
    std::unordered_set<StoreInstr::StoreOps> allowedStoreOps = {StoreInstr::StoreOps::SW};

    RiscvSequencer sequencer(allowedRegisters, allowedRTypeOps, allowedITypeOps, allowedBTypeOps, allowedLoadOps, allowedStoreOps, 0, 64);

    auto instructions = sequencer.generateRandomInstructions(10);

    for (const auto& instr : instructions) {
        // Print or process the instructions
        // Example: std::cout << instr->toString() << std::endl;
        std::cout << "Test 0x" << std::hex << instr->encode() << std::endl;
    }

    return 0;
}
