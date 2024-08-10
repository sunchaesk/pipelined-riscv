
#include "rvv_gen.hpp"

RiscvVectorExtSequencer::RiscvVectorExtSequencer(
    std::unordered_set<uint8_t> allowedRegisters,
    std::unordered_set<uint8_t> allowedVecRegisters,
    std::unordered_set<VITypeInstr::VITypeOps> allowedVITypeOps,
    std::unordered_set<VXTypeInstr::VXTypeOps> allowedVXTypeOps,
    std::unordered_set<VVTypeInstr::VVTypeOps> allowedVVTypeOps
) : allowedRegisters(allowedRegisters), allowedVecRegisters(allowedVecRegisters),
    allowedVITypeOps(allowedVITypeOps), allowedVXTypeOps(allowedVXTypeOps),
    allowedVVTypeOps(allowedVVTypeOps), gen(std::random_device{}()) {
    registerVector.assign(allowedRegisters.begin(), allowedRegisters.end());
    vecRegisterVector.assign(allowedVecRegisters.begin(), allowedVecRegisters.end());
}

uint8_t RiscvVectorExtSequencer::getRandomRegister() {
    std::uniform_int_distribution<> dis(0, registerVector.size() - 1);
    return registerVector[dis(gen)];
}

uint8_t RiscvVectorExtSequencer::getRandomVecRegister() {
    std::uniform_int_distribution<>> dis(0, registerVector.size() - 1);
    return vecRegisterVector[dis(gen)];
}

int16_t RiscvVectorExtSequencer::getRandomPositiveImmediate(int16_t low, int16_t high){
    std::uniform_int_distribution<> dis(low, high - 1);
    return dis(gen);
}

template <typename T>
T RiscvVectorExtSequencer::getRandomOp(const std::unordered_set<T>& allowedOps){
    std::vector<T> opsVector(allowedOps.begin(), allowedOps.end());
    std::uniform_int_distribution<> dis(0, opsVector.size() - 1);
    return opsVector[dis(gen)];
}

RiscvInTx RiscvVectorExtSequencer:: generateRiscvVectorExtensionInstructions(size_t count){
    std::vector<std::shared_ptr<RiscvInstruction>> instructions;

    std::uniform_int_distribution<> instrDis(0, 3); // types: VV, VX, VI
    std::uniform_int_distribution<int> maskDis(0, 1); // 0 : vm = 0, 1: vm = 1

    while(instructions.size() < count){
        int instrType = instrDis(gen);

        // generate VV instructions NOTE: allowedInstrTypes not implemented for rvv_gen
        if (instrType == 0 && !allowedVVTypeOps.empty()) {
            auto vv_op = getRandomOp(allowedVVTypeOps);
            int vm = maskDis(gen);
            instructions.push_back(std::make_shared<VVTypeInstr>(getRandomVecRegister(), getRandomVecRegister(), getRandomVecRegister(), vm, vv_op));
        }
        // generate VI instructions
        else if (instrType == 1 && !allowedVITypeOps.empty()) {
            auto vi_op = getRandomOp(allowedVITypeOps);
            int vm = maskDis(gen);
            instructions.push_back(std::make_shared<VITypeInstr>(getRandomVecRegister(), getRandomPositiveImmediate(-16, 15), getRandomVecRegister(), vm, vi_op));
        }
        // generate VX instructions
        else if (instrType == 1 && !allowedVXTypeOps.empty()) {
            auto vx_op = getRandomOp(allowedVXTypeOps);
            int vm = maskDis(gen);
            instructions.push_back(std::make_shared<VXTypeInstr>(getRandomVecRegister(), getRandomRegister(), getRandomVecRegister(), vm, vx_op));
        }
    }

    return RiscvInTx(std::move(instructions));

}
