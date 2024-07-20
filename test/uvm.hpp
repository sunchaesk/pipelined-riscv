
#ifndef UVM_H
#define UVM_H

#include "isa_gen.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <random>

// testcase + sequence generator
class RiscvSequencer {
    public:
        RiscvSequencer(
            std::unordered_set<uint8_t> allowedRegisters,
            std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps,
            std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps,
            std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps,
            std::unordered_set<LoadInstr::LoadOps> allowedLoadOps,
            std::unordered_set<StoreInstr::StoreOps> allowedStoreOps,
            int16_t mem_start,
            int16_t mem_end
);
        ~RiscvSequencer() = default;

        std::vector<std::unique_ptr<RiscvInstruction>> generateRandomInstructions(size_t count);
    private:
        std::unordered_set<uint8_t> allowedRegisters;
        std::vector<uint8_t> registerVector;
        std::mt19937 gen;

        std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps;
        std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps;
        std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps;
        std::unordered_set<LoadInstr::LoadOps> allowedLoadOps;
        std::unordered_set<StoreInstr::StoreOps> allowedStoreOps;

        int16_t mem_start;
        int16_t mem_end;

        uint8_t getRandomRegister();
        int16_t getRandomImmediate();
        int16_t getRandomWordAlignedImmediate(int16_t min, int16_t max);

        template<typename T>
        T getRandomOp(const std::unordered_set<T>& allowedOps);
};

// riscv input interface transaction item class
// RiscvInTx obj will contain a sequence of instructions
class RiscvInTx {
    private:
    public:
        RiscvInTx();
        ~RiscvInTx();
};

class RiscvOutTx {
    private:
    public:
        RiscvOutTx();
        ~RiscvOutTx();
};

class RiscvScoreBoard {
    private:
    public:
        RiscvScoreBoard();
        ~RiscvScoreBoard();
};

class RiscvInDriver {
    private:
    public:
        RiscvInDriver();
        ~RiscvInDriver();
};

class RiscvInMonitor {
    private:
    public:
        RiscvInMonitor();
        ~RiscvInMonitor();
};

class RiscvOutMonitor {
    private:
    public:
        RiscvOutMonitor();
        ~RiscvOutMonitor();
};

#endif
