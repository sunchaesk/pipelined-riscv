
#include "uvm.hpp"
#include <iostream>


//////////////////////////////////////////////////
// RiscvInTx
//////////////////////////////////////////////////
RiscvInTx::RiscvInTx(std::vector<std::shared_ptr<RiscvInstruction>> instructions)
    : instructions(std::move(instructions)) {
}


//////////////////////////////////////////////////
// RiscvOutTx
//////////////////////////////////////////////////
RiscvOutTx::RiscvOutTx(std::vector<int32_t> register_values, std::vector<int32_t> memory_values)
    : register_values(std::move(register_values)), memory_values(std::move(memory_values)) {
}

////////////////////////////////////////////////
// RiscvSequencer
////////////////////////////////////////////////
RiscvSequencer::RiscvSequencer(
    std::unordered_set<uint8_t> allowedRegisters,
    std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps,
    std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps,
    std::unordered_set<BTypeInstr::BTypeOps> allowedBTypeOps,
    std::unordered_set<LoadInstr::LoadOps> allowedLoadOps,
    std::unordered_set<StoreInstr::StoreOps> allowedStoreOps,
    InstrTypeMap allowedInstrTypes,
    int16_t mem_start,
    int16_t mem_end
)
    : allowedRegisters(allowedRegisters), allowedRTypeOps(allowedRTypeOps),
      allowedITypeOps(allowedITypeOps), allowedBTypeOps(allowedBTypeOps),
      allowedLoadOps(allowedLoadOps), allowedStoreOps(allowedStoreOps),
      allowedInstrTypes(allowedInstrTypes),
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

// non inclusive
int16_t RiscvSequencer::getRandomPositiveImmediate(int16_t low, int16_t high) {
    std::uniform_int_distribution<> dis(low, high - 1);
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

RiscvInTx RiscvSequencer::generateRandomInstructions(size_t count) {
    std::vector<std::shared_ptr<RiscvInstruction>> instructions;

    std::uniform_int_distribution<> instrDis(0, 5); // types : R, I, B, Load, Store, J

    while(instructions.size() < count) {
        int instrType = instrDis(gen);
        // Generate R-Type instructions if allowed
        if (instrType == 0 && allowedInstrTypes.at("RType") && !allowedRTypeOps.empty()) {
            auto r_op = getRandomOp(allowedRTypeOps);
            /* if (r_op == RTypeInstr::RTypeOps::SLLI || r_op == RTypeInstr::RTypeOps::SRLI || r_op == RTypeInstr::RTypeOps::SRAI){ */
            /* } else { */
            /* } */
            instructions.push_back(std::make_shared<RTypeInstr>(getRandomRegister(), getRandomRegister(), getRandomRegister(), r_op));
        }
        // Generate I-Type instructions if allowed
        else if (instrType == 1 && allowedInstrTypes.at("IType") && !allowedITypeOps.empty()) {
            auto i_op = getRandomOp(allowedITypeOps);
            if (i_op == ITypeInstr::ITypeOps::SLLI || i_op == ITypeInstr::ITypeOps::SRLI || i_op == ITypeInstr::ITypeOps::SRAI){
                instructions.push_back(std::make_shared<ITypeInstr>(getRandomRegister(), getRandomRegister(), getRandomPositiveImmediate(0, 32), i_op));
            } else {
                instructions.push_back(std::make_shared<ITypeInstr>(getRandomRegister(), getRandomRegister(), getRandomImmediate(), i_op));
            }
        }
        // Generate B-Type instructions if allowed
        else if (instrType == 2 && allowedInstrTypes.at("BType") && !allowedBTypeOps.empty()) {
            auto b_op = getRandomOp(allowedBTypeOps);
            instructions.push_back(std::make_shared<BTypeInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), b_op));
        }
        // Generate Load instructions if allowed
        else if (instrType == 3 && allowedInstrTypes.at("Load") && !allowedLoadOps.empty()) {
            auto load_op = getRandomOp(allowedLoadOps);
            instructions.push_back(std::make_shared<LoadInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), load_op));
        }
        // Generate Store instructions if allowed
        else if (instrType == 4 && allowedInstrTypes.at("Store") && !allowedStoreOps.empty()) {
            auto store_op = getRandomOp(allowedStoreOps);
            instructions.push_back(std::make_shared<StoreInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), store_op));
        }
        // Generate J-Type instructions if allowed
        else if (instrType == 5 && allowedInstrTypes.at("JType")) {
            instructions.push_back(std::make_shared<JTypeInstr>(getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end)));
        }
    }
    // for (size_t i = 0; i < count; i++){
    //     int instrType = instrDis(gen);

    //     if (instrType == 0 && !allowedRTypeOps.empty()) { // R-Type
    //         auto r_op = getRandomOp(allowedRTypeOps);
    //         instructions.push_back(std::make_shared<RTypeInstr>(getRandomRegister(), getRandomRegister(), getRandomRegister(), r_op));
    //     } else if (instrType == 1 && !allowedITypeOps.empty()) { // I-Type
    //         auto i_op = getRandomOp(allowedITypeOps);
    //         instructions.push_back(std::make_shared<ITypeInstr>(getRandomRegister(), getRandomRegister(), getRandomImmediate(), i_op));
    //     } else if (instrType == 2 && !allowedBTypeOps.empty()) { // B-Type
    //         auto b_op = getRandomOp(allowedBTypeOps);
    //         instructions.push_back(std::make_shared<BTypeInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), b_op));
    //     } else if (instrType == 3 && !allowedLoadOps.empty()) { // Load
    //         auto load_op = getRandomOp(allowedLoadOps);
    //         instructions.push_back(std::make_shared<LoadInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), load_op));
    //     } else if (instrType == 4 && !allowedStoreOps.empty()) { // Store
    //         auto store_op = getRandomOp(allowedStoreOps);
    //         instructions.push_back(std::make_shared<StoreInstr>(getRandomRegister(), getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end), store_op));
    //     } else if (instrType == 5) { // jump
    //         instructions.push_back(std::make_shared<JTypeInstr>(getRandomRegister(), getRandomWordAlignedImmediate(mem_start, mem_end)));
    //     }
    // }

    return RiscvInTx(std::move(instructions));
}

//////////////////////////////////////////////
// RiscvInDriver
//////////////////////////////////////////////
RiscvInDriver::RiscvInDriver(Vriscv * dut, RiscvScoreBoard * scb)
    : dut(dut), scb(scb) {}

void RiscvInDriver::drive(RiscvInTx * tx){
    for (std::size_t i = 0; i < tx->instructions.size(); ++i){
        dut->riscv__DOT__IF_unit__DOT__instr_mem[i] = tx->instructions[i]->encode();
    }

    // use the scoreboard writeIn
    this->scb->writeIn(tx);

    // delete tx;
    // TODO
}


//////////////////////////////////////////////
// RiscvOutMonitor
//////////////////////////////////////////////
RiscvOutMonitor::RiscvOutMonitor(Vriscv * dut, RiscvScoreBoard * scb)
    : dut(dut), scb(scb) {}

void RiscvOutMonitor::monitor() {
    // read the register and memory array values
    // create RiscvOutTx instance
    // write out to the scoreboard
    std::vector<int32_t> final_mem_array;
    std::vector<int32_t> final_reg_array;

    // 32 registers TODO possible way to fetch from the generated verilator class?
    for (size_t i = 0; i < 32; ++i){
        final_reg_array.push_back(dut->riscv__DOT__ID_unit__DOT__reg_array[i]);
    }

    // 256 memaddresses
    for (size_t i = 0; i < 256; ++i){
        final_mem_array.push_back(dut->riscv__DOT__MEM_unit__DOT__mem_array[i]);
    }

    RiscvOutTx * tx = new RiscvOutTx(final_reg_array, final_mem_array);

    this->scb->writeOut(tx);

    delete tx;
}

//////////////////////////////////////////////
// RiscvScoreBoard
//////////////////////////////////////////////
RiscvScoreBoard::RiscvScoreBoard (std::unordered_set<uint8_t> allowedRegisters)
    : allowedRegisters(allowedRegisters) {
    this->total_correct = 0;
    this->total_test = 0;
}

// NOTE: pointer to tx will be deleted in the parent function
void RiscvScoreBoard::writeIn(RiscvInTx * tx){
    std::cout << "Writing In: " << tx << std::endl; // Debug output
    // this->instructions.clear();

    for (const auto& instr : tx->instructions){
        // std::cout << "Instr: " << instr->toString() << std::endl;
        this->instructions.push_back(instr->toString());
    }
}

// create assembly file to be run on the RARS simulation based on RiscvInTx
// get the simulation results and the dut results
// -> requires running the simulation and calling the perl script
// compare results
void RiscvScoreBoard::writeOut(RiscvOutTx *tx){
    // generate assembly file
    std::string generated_assembly_string = generateSimulationASM();
    std::ofstream asmOutFile("./test/test.asm");
    if (!asmOutFile.is_open()){
        std::cerr << "ERROR: can't open the test.asm file for writing" << std::endl;
        exit(1);
    }
    asmOutFile << generated_assembly_string;
    asmOutFile.close();

    // run the simulation
    std::string simulationCommand = "java -jar ./test/rars1_6.jar ./test/test.asm mc CompactDataAtZero 0-1020 x0 x1 x2 x3 x4 x5 x6 x7 x8 x9 x10 x11 x12 x13 x14 x15 x16 x17 x18 x19 x20 x21 x22 x23 x24 x25 x26 x27 x28 x29 x30 x31 > ./test/simulator_output.txt";
    std::string perlParseCommand = "perl ./test/parse.pl";

    int resultSimuatlionCommand = system(simulationCommand.c_str());
    if (resultSimuatlionCommand == -1){
        std::cerr << "Error in executing simulationCommand (running RARS simulator)" << std::endl;
    }
    int resultPerlParseCommand = system(perlParseCommand.c_str());
    if (resultPerlParseCommand == -1){
        std::cerr << "Error in executing perlParseCommand" << std::endl;
    }

    // fetch results from the RARS simulation
    std::vector<int32_t> simulator_mem_array = this->readSimulatorMemArray();
    std::vector<int32_t> simulator_reg_array = this->readSimulatorRegArray();


    // compare register content (based on allowedRegisters)
    for (const auto& reg_idx : this->allowedRegisters) {
        bool comparison_result = simulator_reg_array[reg_idx] == tx->register_values[reg_idx];
        if (!comparison_result){
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "Test case failed! : register values don't agree" << std::endl;
            for (const auto& reg_idx : this->allowedRegisters) {
                std::cout << "Reg x" << static_cast<unsigned int>(reg_idx) << " Value (sim, dut)" << simulator_reg_array[reg_idx] << " " << tx->register_values[reg_idx] << std::endl;
            }
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            exit(1);
        }
    }
    for (size_t i = 0; i < 256; ++i){
        bool comparison_result = simulator_mem_array[i] == tx->memory_values[i];
        if (!comparison_result){
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "Test case failed! : memory values don't agree" << std::endl;
            for (size_t i = 0; i < 256; ++i){
                std::cout << "Reg x" << i << " Value (sim, dut)" << simulator_mem_array[i] << " " << tx->memory_values[i] << std::endl;
            }
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            exit(1);
        }
    }
    // compare memory content

    // for (size_t i = 0; i < simulator_mem_array.size(); ++i){
    //     std::cout << i << " " << simulator_mem_array[i] << std::endl;
    // }
    // for (size_t i = 0; i < simulator_reg_array.size(); ++i){
    //     std::cout << i << " " << simulator_reg_array[i] << std::endl;
    // }

    delete tx;

}

std::vector<int32_t> RiscvScoreBoard::readSimulatorMemArray() {
    std::vector<int32_t> simulator_mem_array;

    std::ifstream simulationMemArrayFile("./test/memory.txt");
    std::string memoryEntry;
    int i = 0;

    while (std::getline(simulationMemArrayFile, memoryEntry)){
        if (memoryEntry.empty()){
            std::cout << "WARNING: unintended behaviour " << i << std::endl;
            // NOTE shouldn't be reached
            continue;
        }
        try {
            int32_t memory_read = std::stol(memoryEntry, nullptr, 16); // try reading the hex format
            simulator_mem_array.push_back(memory_read);
            i++;
        } catch (const std::invalid_argument& e){
            std::cerr << "readSimulatorMemArray" << std::endl;
            break;
        }
    }

    // for (size_t i = 0; i < simulator_mem_array.size(); ++i){
    //     std::cout << i << " " << simulator_mem_array[i] << std::endl;
    // }

    if (simulator_mem_array.size() != 1024/4) {
        throw std::range_error("Memory size was not equal to the expected value of 256 entries");
    }

    return simulator_mem_array;
}

std::vector<int32_t> RiscvScoreBoard::readSimulatorRegArray() {
    std::vector<int32_t> simulator_reg_array;

    std::ifstream simulationRegArrayFile("./test/registers.txt");
    std::string registerEntry;
    int i = 0;

    while (std::getline(simulationRegArrayFile, registerEntry)){
        if (registerEntry.empty()){
            std::cout << "WARNING: unintended behaviour " << i << std::endl;
            // NOTE shouldn't be reached
            continue;
        }
        try {
            int32_t register_read = std::stol(registerEntry, nullptr, 16);
            simulator_reg_array.push_back(register_read);
            i++;
        } catch (const std::invalid_argument& e){
            std::cerr << "readSimulatorRegArray invalid argument" << std::endl;
            break;
        } catch (const std::out_of_range& e){
            std::cerr << "readSimulatorRegArray out of range" << std::endl;
            break;
        }
    }

    // for (size_t i = 0; i < simulator_reg_array.size(); ++i){
    //     std::cout << i << " " << simulator_reg_array[i] << std::endl;
    // }
    if (simulator_reg_array.size() != 32) {
        throw std::range_error("Register size was not equal to the expected value of 1024 entries");
    }

    return simulator_reg_array;
}

std::string RiscvScoreBoard::generateSimulationASM(){
    std::ostringstream asmStream;

    asmStream << ".section text\n";
    asmStream << ".globl _start\n";
    asmStream << "\n";
    asmStream << "_start:\n";

    for (const auto& instruction : this->instructions){
        asmStream << "    " << instruction << "\n";
    }

    return asmStream.str();
}
