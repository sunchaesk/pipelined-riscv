
#include "isa_gen.hpp"

//////////////////////////////////////////////////////////
// RTYPE
//////////////////////////////////////////////////////////
RTypeInstr::RTypeInstr(uint8_t rd, uint8_t rs1, uint8_t rs2, RTypeOps r_ops, uint8_t opcode)
    : rd(rd), rs1(rs1), rs2(rs2), opcode(opcode) {
    setFunctBits(r_ops);
}

void RTypeInstr::setFunctBits(RTypeOps r_ops) {
    switch (r_ops) {
        case RTypeOps::ADD:
            funct7 = 0b0000000;
            funct3 = 0b000;
            break;
        case RTypeOps::SUB:
            funct7 = 0b0100000;
            funct3 = 0b000;
            break;
        case RTypeOps::XOR:
            funct7 = 0b0000000;
            funct3 = 0b100;
            break;
        case RTypeOps::OR:
            funct7 = 0b0000000;
            funct3 = 0b110;
            break;
        case RTypeOps::AND:
            funct7 = 0b0000000;
            funct3 = 0b111;
            break;
        case RTypeOps::SLL:
            funct7 = 0b0000000;
            funct3 = 0b001;
            break;
        case RTypeOps::SRL:
            funct7 = 0b0000000;
            funct3 = 0b101;
            break;
        case RTypeOps::SRA:
            funct7 = 0b0100000;
            funct3 = 0b101;
            break;
        case RTypeOps::SLT:
            funct7 = 0b0000000;
            funct3 = 0b010;
            break;
        case RTypeOps::SLTU:
            funct7 = 0b0000000;
            funct3 = 0b011;
            break;
        default:
            throw std::invalid_argument("Invalid R-Type instruction operation");
    }
}

uint32_t RTypeInstr::encode() const {
    return (static_cast<uint32_t>(funct7) << 25) |
        (static_cast<uint32_t>(rs2) << 20) |
        (static_cast<uint32_t>(rs1) << 15) |
        (static_cast<uint32_t>(funct3) << 12) |
        (static_cast<uint32_t>(rd) << 7) |
        opcode;
}


//////////////////////////////////////////////////////////
// ITYPE
//////////////////////////////////////////////////////////
ITypeInstr::ITypeInstr(uint8_t rd, uint8_t rs1, int16_t imm, ITypeOps i_ops, uint8_t opcode )
    : rd(rd), rs1(rs1), imm(imm), opcode(opcode) {
    setFunctBits(i_ops);
    checkImmeidateRange(imm);
}

void ITypeInstr::setFunctBits(ITypeOps i_ops) {
    switch (i_ops) {
        case ITypeOps::ADDI:
            funct3 = 0b000;
            break;
        case ITypeOps::XORI:
            funct3 = 0b100;
            break;
        case ITypeOps::ORI:
            funct3 = 0b110;
            break;
        case ITypeOps::ANDI:
            funct3 = 0b111;
            break;
        case ITypeOps::SLLI:
            funct3 = 0b001;
            break;
        case ITypeOps::SRLI:
            funct3 = 0b101;
            imm &= ~(1 << 10);
            break;
        case ITypeOps::SRAI:
            funct3 = 0b101;
            imm |= (1 << 10);
            break;
        case ITypeOps::SLTI:
            funct3 = 0b010;
            break;
        case ITypeOps::SLTUI:
            funct3 = 0b011;
            break;
        default:
            throw std::invalid_argument("Invalid I-Type instruction operation");
    }
}

void ITypeInstr::checkImmeidateRange(int16_t imm) const {
    if (imm < -2048 || imm > 2047) {
        throw std::out_of_range("Immediate value is 12bits, but provided imm was exceeded the range");
    }
}

uint32_t ITypeInstr::encode() const {
    return (static_cast<uint32_t>(imm) << 20) |
        (static_cast<uint32_t>(rs1) << 15) |
        (static_cast<uint32_t>(funct3) << 12) |
        (static_cast<uint32_t>(rd) << 7) |
        opcode;
}

////////////////////////////////////////////////
// I-type (load word)
////////////////////////////////////////////////
LoadInstr::LoadInstr(uint8_t rd, uint8_t rs1, int16_t imm, LoadOps l_ops, uint8_t opcode)
    : rd(rd), rs1(rs1), imm(imm), opcode(opcode) {
    setFunctBits(l_ops);
    checkImmeidateRange(imm);
}

void LoadInstr::checkImmeidateRange(int16_t imm) const {
    if (imm < -2048 || imm > 2047) {
        throw std::out_of_range("Immediate value is 12bits, but provided imm was exceeded the range");
    }
}

void LoadInstr::setFunctBits(LoadOps l_ops) {
    switch(l_ops) {
        case LoadOps::LB:
            funct3= 0b000;
            break;
        case LoadOps::LH:
            funct3 = 0b001;
            break;
        case LoadOps::LW:
            funct3 = 0b010;
            break;
        case LoadOps::LBU:
            funct3 = 0b100;
            break;
        case LoadOps::LHU:
            funct3 = 0b101;
            break;
        default:
            throw std::invalid_argument("Invalid Load instruction operation");
    }
}

uint32_t LoadInstr::encode() const {
    return (static_cast<uint32_t>(imm) << 20) |
        (static_cast<uint32_t>(rs1) << 15) |
        (static_cast<uint32_t>(funct3) << 12) |
        (static_cast<uint32_t>(rd) << 7) |
        opcode;
}


////////////////////////////////////////////////
// S-Type (store)
////////////////////////////////////////////////
StoreInstr::StoreInstr(uint8_t rs1, uint8_t rs2, int16_t imm, StoreOps s_ops, uint8_t opcode)
    : rs1(rs1), rs2(rs2), imm(imm), opcode(opcode){
    setFunctBits(s_ops);
    checkImmeidateRange(imm);
}

void StoreInstr::setFunctBits(StoreOps s_ops) {
    switch(s_ops){
        case StoreOps::SB :
            funct3 = 0b000;
            break;
        case StoreOps::SH :
            funct3 = 0b001;
            break;
        case StoreOps::SW :
            funct3 = 0b010;
            break;
    }
}

void StoreInstr::checkImmeidateRange(int16_t imm) const{
    if (imm < -2048 || imm > 2047) {
        throw std::out_of_range("Immediate value is 12 bits, and imm provided exceeds allowed range");
    }
}

uint32_t StoreInstr::encode () const {
    uint8_t imm_11_5 = (imm >> 5) & 0x7F; // Extract bits 11 to 5 of the immediate
    uint8_t imm_4_0 = imm & 0x1F;          // Extract bits 4 to 0 of the immediate

    return (static_cast<uint32_t>(imm_11_5) << 25) |
        (static_cast<uint32_t>(rs2) << 20) |
        (static_cast<uint32_t>(rs1) << 15) |
        (static_cast<uint32_t>(funct3) << 12) |
        (static_cast<uint32_t>(imm_4_0) << 7) |
        opcode;
}

////////////////////////////////////////////
// B-Type instr (Branch)
////////////////////////////////////////////
BTypeInstr::BTypeInstr(uint8_t rs1, uint8_t rs2, int16_t imm, BTypeOps b_ops, uint8_t opcode)
    : rs1(rs1), rs2(rs2), imm(imm), opcode(opcode) {

    setFunctBits(b_ops);
    checkImmeidateRange(imm);
}

void BTypeInstr::setFunctBits(BTypeOps b_ops) {
    switch(b_ops){
        case BTypeOps::BEQ:
            funct3 = 0b000;
            break;
        case BTypeOps::BNE:
            funct3 = 0b001;
            break;
        case BTypeOps::BLT:
            funct3 = 0b100;
            break;
        case BTypeOps::BGE:
            funct3 = 0b101;
            break;
        case BTypeOps::BLTU:
            funct3 = 0b110;
            break;
        case BTypeOps::BGEU:
            funct3 = 0b111;
            break;
        default:
            throw std::invalid_argument("Invalid B type instruction operation");
    }
}

void BTypeInstr::checkImmeidateRange(int16_t imm) const{
    if (imm < -2048 || imm > 2047) {
        throw std::out_of_range("Immediate value is 12bits, but provided imm was exceeded the range");
    }
}

uint32_t BTypeInstr::encode() const {
    uint8_t imm_12 = (imm >> 12) & 0x1;     // Extract bit 12 of the immediate
    uint8_t imm_10_5 = (imm >> 5) & 0x3F;   // Extract bits 10 to 5 of the immediate
    uint8_t imm_4_1 = (imm >> 1) & 0xF;     // Extract bits 4 to 1 of the immediate
    uint8_t imm_11 = (imm >> 11) & 0x1;     // Extract bit 11 of the immediate

    return (static_cast<uint32_t>(imm_12) << 31) |
        (static_cast<uint32_t>(imm_11) << 7) |
        (static_cast<uint32_t>(imm_10_5) << 25) |
        (static_cast<uint32_t>(rs2) << 20) |
        (static_cast<uint32_t>(rs1) << 15) |
        (static_cast<uint32_t>(funct3) << 12) |
        (static_cast<uint32_t>(imm_4_1) << 8) |
        opcode;
}

////////////////////////////////////////
// J Type (only jal instr)
////////////////////////////////////////
JTypeInstr::JTypeInstr(uint8_t rd, int32_t imm, uint8_t opcode)
    : rd(rd), imm(imm), opcode(opcode) {
    checkImmediateRange(imm);
}

// Encode the instruction into a 32-bit integer
uint32_t JTypeInstr::encode() const {
    uint32_t imm_20 = (imm >> 20) & 0x1;      // Extract bit 20 of the immediate
    uint32_t imm_10_1 = (imm >> 1) & 0x3FF;   // Extract bits 10 to 1 of the immediate
    uint32_t imm_11 = (imm >> 11) & 0x1;      // Extract bit 11 of the immediate
    uint32_t imm_19_12 = (imm >> 12) & 0xFF;  // Extract bits 19 to 12 of the immediate

    return (imm_20 << 31) |
        (imm_19_12 << 12) |
        (imm_11 << 20) |
        (imm_10_1 << 21) |
        (static_cast<uint32_t>(rd) << 7) |
        opcode;
}

void JTypeInstr::checkImmediateRange(int32_t imm) const {
    if (imm < -(1 << 20) || imm > ((1 << 20) - 1)) { // 21-bit signed immediate range is from -2^20 to 2^20-1
        throw std::out_of_range("Immediate value out of 21-bit range");
    }
}

////////////////////////////////////
// JALR
////////////////////////////////////
JALRInstr::JALRInstr(uint8_t rd, uint8_t rs1, int16_t imm, uint8_t opcode)
    : rd(rd), rs1(rs1), imm(imm), opcode(opcode), funct3(JALR_FUNCT3) {
    checkImmediateRange(imm);
}

// Encode the instruction into a 32-bit integer
uint32_t JALRInstr::encode() const {
    return (static_cast<uint32_t>(imm) << 20) |
        (static_cast<uint32_t>(rs1) << 15) |
        (static_cast<uint32_t>(funct3) << 12) |
        (static_cast<uint32_t>(rd) << 7) |
        opcode;
}


// Check if the immediate value is within the valid 12-bit range for I-Type instructions
void JALRInstr::checkImmediateRange(int16_t imm) const {
    if (imm < -2048 || imm > 2047) { // 12-bit signed immediate range is from -2048 to 2047
        throw std::out_of_range("Immediate value out of 12-bit range");
    }
}
