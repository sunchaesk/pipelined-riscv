
#include "data_hazard_gen.hpp"

////
// OperandNode
////////
OperandNode::OperandNode(OperandType op_type)
    : op_type(op_type), next_op_node(nullptr) {}

///////////////
// InstructionNode
///////////////
std::mt19937 InstructionNode::rng(static_cast<unsigned>(std::time(nullptr)));
std::uniform_int_distribution<int> InstructionNode::dist(0, 1);

InstructionNode::InstructionNode(){
    this->dest = new OperandNode(OperandType::DEST_REG);
    this->op1 = new OperandNode(OperandType::SRC_REG1);
    this->op2 = new OperandNode(this->getRandomOperandType());
}

OperandType InstructionNode::getRandomOperandType(){
    return (dist(rng) == 0) ? OperandType::IMMEDIATE : OperandType::SRC_REG2;
}

//////////////////////
/// RandomInstructionList
//////////////////////
// RandomInstructionList::RandomInstructionList (size_t count) {
//     // resize the instructions vector
//     this->instructions.resize(count);

//     for (size_t i = 0; i < count; ++i){
//         instructions[i] = new InstructionNode();
//     }
// }

// void RandomInstructionList::printRandomInstructionList () const{
//     for (size_t i = 0; i < this->instructions.size(); ++i){
//         std::cout << "idx: " << i << " " << instructions[i]->dest->op_type << " "
//                   << instructions[i]->op1->op_type << " " << instructions[i]->op2->op_type << std::endl;
//     }
// }

//////////////////////////////////////
// Data Hazard Riscv Sequencer
//////////////////////////////////////

uint8_t DataHazardRiscvSequencer::getRandomRegister() {
    std::uniform_int_distribution<> dis(0, registerVector.size() - 1);
    return registerVector[dis(gen)];
}

int16_t DataHazardRiscvSequencer::getRandomImmediate() {
    std::uniform_int_distribution<> dis(-2048, 2047);
    return dis(gen);
}

// non inclusive
int16_t DataHazardRiscvSequencer::getRandomPositiveImmediate(int16_t low, int16_t high) {
    std::uniform_int_distribution<> dis(low, high - 1);
    return dis(gen);
}

int16_t DataHazardRiscvSequencer::getRandomWordAlignedImmediate(int16_t min, int16_t max) {
    if (min % 4 != 0 || max % 4 != 0) {
        throw std::invalid_argument("min and max must be multiples of 4 (including 0)");
    }

    int16_t stepCount = (max - min) / (4 + 1);

    std::uniform_int_distribution<> dis(0, stepCount - 1);

    return min + dis(gen) * 4;
}

template <typename T>
T DataHazardRiscvSequencer::getRandomOp(const std::unordered_set<T>& allowedOps){
    std::vector<T> opsVector(allowedOps.begin(), allowedOps.end());
    std::uniform_int_distribution<> dis(0, opsVector.size() - 1);
    return opsVector[dis(gen)];
}

DataHazardRiscvSequencer::DataHazardRiscvSequencer (
    std::unordered_set<uint8_t> allowedRegisters,
    std::unordered_set<RTypeInstr::RTypeOps> allowedRTypeOps,
    std::unordered_set<ITypeInstr::ITypeOps> allowedITypeOps
) : allowedRegisters(allowedRegisters),
    allowedRTypeOps(allowedRTypeOps),
    allowedITypeOps(allowedITypeOps),
    gen(std::random_device{}()) {
    this->registerVector.assign(allowedRegisters.begin(), allowedRegisters.end());
}

RiscvInTx DataHazardRiscvSequencer::generateDataHazardRandomInstructions(size_t count) {
    // Call the propagateInstructions private method
    propagateInstructions(count);

    // Initialize instructions

    // Check if instructions vector is not empty
    if (this->instructions.empty()) {
        std::cerr << "Error: instructions vector is empty" << std::endl;
        return RiscvInTx({}); // Return an empty RiscvInTx object or handle the error appropriately
    }

    // Parse the instructions to generate RiscvInTx
    uint8_t dest_reg;
    uint8_t source_reg1;
    uint8_t source_reg2;
    int16_t immediate;

    // Check the last instruction's op2 type
    dest_reg = getRandomRegister();
    source_reg1 = getRandomRegister();
    source_reg2 = getRandomRegister();
    immediate = getRandomImmediate();
    if (this->instructions.back() && this->instructions.back()->op2 && this->instructions.back()->op2->op_type == OperandType::SRC_REG2) { // R type
        auto r_op = this->getRandomOp(this->allowedRTypeOps);
        riscv_instructions.push_back(std::make_shared<RTypeInstr>(dest_reg, source_reg1, source_reg2, r_op));
    } else { // I type
        auto i_op = this->getRandomOp(this->allowedITypeOps);
        riscv_instructions.push_back(std::make_shared<ITypeInstr>(dest_reg, source_reg1, source_reg2, i_op));
    }

    for (int i = instructions.size() - 2; i >= 0; --i){
        auto current_instruction_node_ptr = this->instructions[i];
        auto next_generated_instruction_node = riscv_instructions[0];  // because we always add to the front, riscv_instructions[0] is the prev instr
        if (current_instruction_node_ptr->dest->next_op_node == nullptr){
            dest_reg = getRandomRegister();
        } else {
            if (current_instruction_node_ptr->dest->next_op_node->op_type == OperandType::DEST_REG){
                dest_reg = next_generated_instruction_node->rd;
            } else if (current_instruction_node_ptr->dest->next_op_node->op_type == OperandType::SRC_REG1) {
                dest_reg = next_generated_instruction_node->rs1;
            } else if (current_instruction_node_ptr->dest->next_op_node->op_type == OperandType::SRC_REG2){
                dest_reg = next_generated_instruction_node->rs2;
            }
        }

        if (current_instruction_node_ptr->op1->next_op_node == nullptr){
            source_reg1 = getRandomRegister();
        } else {
            if (current_instruction_node_ptr->op1->next_op_node->op_type == OperandType::DEST_REG){
                source_reg1 = next_generated_instruction_node->rd;
            } else if (current_instruction_node_ptr->op1->next_op_node->op_type == OperandType::SRC_REG1){
                source_reg1 = next_generated_instruction_node->rs1;
            } else if (current_instruction_node_ptr->op1->next_op_node->op_type == OperandType::SRC_REG2){
                source_reg1 = next_generated_instruction_node->rs2;
            }
        }

        if (current_instruction_node_ptr->op2->op_type != OperandType::IMMEDIATE){
            if (current_instruction_node_ptr->op2->next_op_node == nullptr){
                source_reg2 = getRandomRegister();
            } else {
                if (current_instruction_node_ptr->op2->next_op_node->op_type == OperandType::DEST_REG){
                    source_reg2 = next_generated_instruction_node->rd;
                } else if (current_instruction_node_ptr->op2->next_op_node->op_type == OperandType::SRC_REG1){
                    source_reg2 = next_generated_instruction_node->rs1;
                } else if (current_instruction_node_ptr->op2->next_op_node->op_type == OperandType::SRC_REG2){
                    source_reg2 = next_generated_instruction_node->rs2;
                }
            }
            riscv_instructions.insert(riscv_instructions.begin(), std::make_shared<RTypeInstr>(dest_reg, source_reg1, source_reg2, getRandomOp(this->allowedRTypeOps)));
        } else {
            immediate = getRandomImmediate();
            riscv_instructions.insert(riscv_instructions.begin(), std::make_shared<ITypeInstr>(dest_reg, source_reg1, immediate, getRandomOp(this->allowedITypeOps)));
        }
    }

    RiscvInTx return_riscv_in_tx (riscv_instructions);
    return return_riscv_in_tx;
}

void DataHazardRiscvSequencer::propagateInstructions(size_t count){
    // initialize the instruction node vector
    this->instructions.resize(count);
    for (size_t i = 0; i < count; ++i){
        instructions[i] = new InstructionNode();
    }

    // generate connections
    for (size_t i = 1; i < count; ++i){
        int prev_i = i - 1;
        std::vector<uint8_t> valid_connection_next {0, 1};
        if (this->instructions[i]->op2->op_type != OperandType::IMMEDIATE){
            valid_connection_next.push_back(2);
        }
        std::vector<uint8_t> valid_connection_prev {0, 1};
        if (this->instructions[prev_i]->op2->op_type != OperandType::IMMEDIATE){
            valid_connection_prev.push_back(2);
        }
        for (int j = 0; j < valid_connection_next.size(); ++j){
            std::uniform_int_distribution<int> dist_make_connection (0, 1);
            std::uniform_int_distribution<int> dist_valid_connection_prev_two (0, 1);
            std::uniform_int_distribution<int> dist_valid_connection_prev_three (0, 2);

            // std::cout << "77 " << i << " " << j << std::endl;

            OperandNode * current_operand_node = nullptr;
            if (j == 0){
                current_operand_node = this->instructions[i]->dest;
            } else if (j == 1) {
                current_operand_node = this->instructions[i]->op1;
            } else if (j == 2){
                current_operand_node = this->instructions[i]->op2;
            }

            uint8_t connection_idx;
            if (dist_make_connection(this->gen) == 1){
                // make connection
                if (valid_connection_prev.size() == 3) {
                    connection_idx = dist_valid_connection_prev_three(this->gen);
                } else if (valid_connection_prev.size() == 2){
                    connection_idx = dist_valid_connection_prev_two(this->gen);
                }

                if (connection_idx == 0){
                    this->instructions[prev_i]->dest->next_op_node = current_operand_node;
                } else if (connection_idx == 1) {
                    this->instructions[prev_i]->op1->next_op_node = current_operand_node;
                } else if (connection_idx == 2) {
                    this->instructions[prev_i]->op2->next_op_node = current_operand_node;
                }
            }
        }
    }
}

void DataHazardRiscvSequencer::printRandomInstructionList() const {
    int i = 0;
    for (const auto& instr : instructions) {
        std::cout << "Instruction: " << i << std::endl;

        // Print destination operand
        if (instr->dest) {
            std::cout << "  Dest: " << static_cast<int>(instr->dest->op_type) << std::endl;
            if (instr->dest->next_op_node) {
                std::cout << "    Dest next op: " << static_cast<int>(instr->dest->next_op_node->op_type) << std::endl;
            } else {
                std::cout << "    Dest next op: No connection" << std::endl;
            }
        } else {
            std::cout << "  Dest: No destination operand" << std::endl;
        }

        // Print operand 1
        if (instr->op1) {
            std::cout << "  Op1: " << static_cast<int>(instr->op1->op_type) << std::endl;
            if (instr->op1->next_op_node) {
                std::cout << "    Op1 next op: " << static_cast<int>(instr->op1->next_op_node->op_type) << std::endl;
            } else {
                std::cout << "    Op1 next op: No connection" << std::endl;
            }
        } else {
            std::cout << "  Op1: No operand 1" << std::endl;
        }

        // Print operand 2
        if (instr->op2) {
            std::cout << "  Op2: " << static_cast<int>(instr->op2->op_type) << std::endl;
            if (instr->op2->next_op_node) {
                std::cout << "    Op2 next op: " << static_cast<int>(instr->op2->next_op_node->op_type) << std::endl;
            } else {
                std::cout << "    Op2 next op: No connection" << std::endl;
            }
        } else {
            std::cout << "  Op2: No operand 2" << std::endl;
        }

        i++;
    }
}
