#ifndef DATA_HAZARD_GEN
#define DATA_HAZARD_GEN

#include "uvm.hpp"
#include <vector>
#include <unordered_set>
#include <random>
#include <string>

typedef enum {
DEST_REG,
IMMEDIATE,
SRC_REG1,
SRC_REG2
} OperandType;

class OperandNode {
    public:
        OperandType op_type;
        OperandNode * next_op_node;
        OperandNode(OperandType op_type);
        ~OperandNode() = default;
};

class InstructionNode {
    public:
        InstructionNode();
        ~InstructionNode() = default;
        OperandNode * dest;
        OperandNode * op1;
        OperandNode * op2;
    private:
        static std::mt19937 rng;
        static std::uniform_int_distribution<int> dist;
        OperandType getRandomOperandType();
};


class DataHazardRiscvSequencer {
    public:
        DataHazardRiscvSequencer(
            std::unordered_set<uint8_t> allowedRegisters,
            std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps,
            std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps
);
        ~DataHazardRiscvSequencer() = default;
        RiscvInTx generateDataHazardRandomInstructions(size_t count);
        //debug functions
        void printRandomInstructionList() const;
        void propagateInstructions(size_t count);
    private:
        std::vector<InstructionNode*> instructions;
        std::vector<std::shared_ptr<RiscvInstruction>> riscv_instructions;

        std::unordered_set<uint8_t> allowedRegisters;
        std::vector<uint8_t> registerVector;
        std::mt19937 gen;

        std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps;
        std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps;

        uint8_t getRandomRegister();
        int16_t getRandomImmediate();
        int16_t getRandomPositiveImmediate(int16_t low, int16_t high);
        int16_t getRandomWordAlignedImmediate(int16_t low, int16_t high);

        template<typename T>
        T getRandomOp(const std::unordered_set<T>& allowedOps);
};

#endif
