
#include "uvm.hpp"
#include <iostream>

RiscvSequencer::RiscvSequencer(
    std::unordered_set<uint8_t> allowedRegisters,
    std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps,
    std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps,
    std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps,
    std::unordered_set<LoadInstr::LoadOps> allowedLoadOps,
    std::unordered_set<StoreInstr::StoreOps> allowedStoreOps,
    int16_t mem_start,
    int16_t mem_end
)
    : allowedRegisters(allowedRegisters), allowedRTypeOps(allowedRTypeOps),
      allowedITypeOps(allowedITypeOps), allowedBTypeOps(allowedBTypeOps),
      allowedLoadOps(allowedLoadOps), allowedStoreOps(allowedStoreOps),
      mem_start(mem_start), mem_end(mem_end), gen(std::random_device{}()) {
    registerVector.assign(allowedRegisters.begin(), allowedRegisters.end());
}

uint8_t RiscvSequencer::getRandomRegister() {
    std::uniform_int_distribution<> dis(0, registerVector.size() - 1);
    return registerVector[dis(gen)];
}

int16_t RiscvSequencer::getRandomImmediate() {
    std::uniform_int_distribution<> dis(-2048, 2047);
    return dis(gen);
}

int16_t RiscvSequencer::getRandomWordAlignedImmediate(int16_t min, int16_t max) {
    if (min % 4 != 0 || max % 4 != 0) {
        throw std::invalid_argument("min and max must be multiples of 4 (including 0)");
    }

    int16_t stepCount = (max - min) / (4 + 1);

    std::uniform_int_distribution<> dis(0, stepCount - 1);

    return min + dis(gen) * 4;
}

template <typename T>
T RiscvSequencer::getRandomOp(const std::unordered_set<T>& allowedOps){
    std::vector<T> opsVector(allowedOps.begin(), allowedOps.end());
    std::uniform_int_distribution<> dis(0, opsVector.size() - 1);
    return opsVector[dis(gen)];
}

std::vector<std::unique_ptr<RiscvInstruction>> RiscvSequencer::generateRandomInstructions(size_t count) {
    std::vector<std::unique_ptr<RiscvInstruction>> instructions;

    std::uniform_int_distribution<> instrDis(0, 5); // types : R, I, B, Load, Store, J

    for (size_t i = 0; i < count; i++){
        int instrType = instrDis(gen);

        if (instrType == 0 && !allowedRTypeOps.empty()) { // R-Type
            auto r_op = getRandomOp(allowedRTypeOps);
            instructions.push_back(std::make_unique<RTypeInstr>(getRandomRegister(), getRandomRegister(), getRandomRegister(), r_op));
        } else if (instrType == 1 && !allowedITypeOps.empty()) { // I-Type
            auto i_op = getRandomOp(allowedITypeOps);
            instructions.push_back(std::make_unique<ITypeInstr>(getRandomRegister(), getRandomRegister(), getRandomImmediate(), i_op));
        } else if (instrType == 2 && !allowedBTypeOps.empty()) { // B-Type
            auto b_op = getRandomOp(allowedBTypeOps);
            instructions.push_back(std::make_unique<BTypeInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), b_op));
        } else if (instrType == 3 && !allowedLoadOps.empty()) { // Load
            auto load_op = getRandomOp(allowedLoadOps);
            instructions.push_back(std::make_unique<LoadInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), load_op));
        } else if (instrType == 4 && !allowedStoreOps.empty()) { // Store
            auto store_op = getRandomOp(allowedStoreOps);
            instructions.push_back(std::make_unique<StoreInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), store_op));
        } else if (instrType == 5) { // jump
            instructions.push_back(std::make_unique<JTypeInstr>(getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end)));
        }
    }

    return instructions;
}
