#ifndef RVV_GEN
#define RVV_GEN

#include "uvm.hpp"
#include <vector>
#include <unordered_set>
#include <random>
#include <string>

class RiscvVectorExtSequencer {
    public:
        RiscvVectorExtSequencer(
            std::unordered_set<uint8_t> allowedRegisters,
            std::unordered_set<uint8_t> allowedVecRegisters,
            std::unordered_set<VITypeInstr::VITypeOps> allowedVITypeOps,
            std::unordered_set<VXTypeInstr::VXTypeOps> allowedVXTypeOps,
            std::unordered_set<VVTypeInstr::VVTypeOps> allowedVVTypeOps
);
        ~RiscvVectorExtSequencer() = default;
        RiscvInTx generateRiscvVectorExtensionInstructions(size_t count);
        // debug functions
        void printRandomInstructionList() const;
    private:
        std::unordered_set<uint8_t> allowedRegisters;
        std::unordered_set<uint8_t> allowedVecRegisters;
        std::unordered_set<VITypeInstr::VITypeOps> allowedVITypeOps;
        std::unordered_set<VXTypeInstr::VXTypeOps> allowedVXTypeOps;
        std::unordered_set<VVTypeInstr::VVTypeOps> allowedVVTypeOps;

        std::vector<uint8_t> registerVector;
        std::vector<uint8_t> vecRegisterVector;
        std::mt19937 gen;

        uint8_t getRandomRegister();
        uint8_t getRandomVecRegister();
        int16_t getRandomPositiveImmediate(int16_t low, int16_t high);

        template <typename T>
        T getRandomOp(const std::unordered_set<T>& allowedOps);
};

#endif
