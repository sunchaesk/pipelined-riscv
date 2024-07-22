
#ifndef UVM_H
#define UVM_H

#include "isa_gen.hpp"

#include <verilated.h>
#include <verilated_vcd_c.h>
#include "Vriscv.h"
#include "Vriscv__Syms.h"
// #include "../obj_dir/Vriscv.h"
// #include "../obj_dir/Vriscv__Syms.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <memory>
#include <unordered_set>
#include <random>
#include <cstdlib>
#include <unordered_map>


// for generateRandomInstructions settings stuff
using InstrTypeMap = std::unordered_map<std::string, bool>;

// riscv input interface transaction item class
// RiscvInTx obj will contain a sequence of instructions
class RiscvInTx {
    private:
    public:
        RiscvInTx(std::vector<std::shared_ptr<RiscvInstruction>> instructions);
        ~RiscvInTx() =  default;
        std::vector<std::shared_ptr<RiscvInstruction>> instructions;
};

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
            InstrTypeMap allowedInstrTypes,
            int16_t mem_start,
            int16_t mem_end
);
        ~RiscvSequencer() = default;

        RiscvInTx generateRandomInstructions(size_t count);
    private:
        std::unordered_set<uint8_t> allowedRegisters;
        std::vector<uint8_t> registerVector;
        std::mt19937 gen;

        // from constructor
        std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps;
        std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps;
        std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps;
        std::unordered_set<LoadInstr::LoadOps> allowedLoadOps;
        std::unordered_set<StoreInstr::StoreOps> allowedStoreOps;
        InstrTypeMap allowedInstrTypes;
        int16_t mem_start;
        int16_t mem_end;

        uint8_t getRandomRegister();
        int16_t getRandomImmediate();
        int16_t getRandomPositiveImmediate(int16_t low, int16_t high);
        int16_t getRandomWordAlignedImmediate(int16_t min, int16_t max);

        template<typename T>
        T getRandomOp(const std::unordered_set<T>& allowedOps);
};


class RiscvOutTx {
    private:
    public:
        std::vector<int32_t> register_values;
        std::vector<int32_t> memory_values;
        RiscvOutTx(std::vector<int32_t> register_values, std::vector<int32_t> memory_values);
        ~RiscvOutTx() = default;
};

class RiscvScoreBoard {
    private:
        uint32_t total_correct;
        uint32_t total_test;
        std::unordered_set<uint8_t> allowedRegisters;
        std::vector<std::string> instructions;
        std::vector<int32_t> readSimulatorMemArray();
        std::vector<int32_t> readSimulatorRegArray();
        std::string generateSimulationASM();
    public:
        RiscvScoreBoard(std::unordered_set<uint8_t> allowedRegisters);
        ~RiscvScoreBoard() = default;
        void writeIn(RiscvInTx * tx);
        void writeOut(RiscvOutTx * tx);
};

class RiscvInDriver {
    private:
        Vriscv * dut;
        RiscvScoreBoard * scb;
    public:
        RiscvInDriver(Vriscv * dut, RiscvScoreBoard * scb);
        ~RiscvInDriver() = default;
       void drive(RiscvInTx * tx);
};

class RiscvOutMonitor {
    private:
        Vriscv * dut;
        RiscvScoreBoard * scb;
    public:
        RiscvOutMonitor(Vriscv * dut, RiscvScoreBoard * scb);
        ~RiscvOutMonitor() = default;
        void monitor();
};

#endif
