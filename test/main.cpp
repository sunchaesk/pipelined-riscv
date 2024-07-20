// testing purposes

#include "isa_gen.hpp"

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


    return 0;
}
