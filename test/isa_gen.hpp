#ifndef ISA_GEN_H
#define ISA_GEN_H

#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <unordered_map>

// for generateRandomInstructions settings stuff
using InstrTypeMap = std::unordered_map<std::string, bool>;

class RiscvInstruction {
        private:
        public:
                virtual ~RiscvInstruction() = default;
                virtual uint32_t encode() const = 0;
                virtual std::string toString() const = 0;
                virtual std::shared_ptr<RiscvInstruction> clone() const = 0;
                uint8_t rd;
                uint8_t rs1;
                uint8_t rs2;
};

class RTypeInstr : public RiscvInstruction {
        public:
                enum class RTypeOps {
                ADD,
                SUB,
                XOR,
                OR,
                AND,
                SLL,
                SRL,
                SRA,
                SLT,
                SLTU
        };

                static constexpr uint8_t RTYPE_OPCODE = 0b0110011;

                // constructor
                RTypeInstr(uint8_t rd, uint8_t rs1, uint8_t rs2, RTypeOps r_ops, uint8_t opcode = RTYPE_OPCODE);

                ~RTypeInstr() override = default;


                // override methods
                std::string toString() const override; // TODO might be too much of a case-statement hassle
                uint32_t encode() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<RTypeInstr>(*this);
                }
        private:
                uint8_t opcode;
                uint8_t funct7;
                uint8_t funct3;
                uint8_t rs2;
                uint8_t rs1;
                uint8_t rd;

                void setFunctBits(RTypeOps r_ops);
};

class ITypeInstr : public RiscvInstruction {
        public:
                enum class ITypeOps {
                ADDI,
                // SUB, NOTE riscv doesn't have immediate
                XORI,
                ORI,
                ANDI,
                SLLI,
                SRLI,
                // SRAI,
                SLTI,
                SLTUI
        };

                static constexpr uint8_t ITYPE_OPCODE = 0b0010011;

                // constructor
                ITypeInstr(uint8_t rd, uint8_t rs1, int16_t imm, ITypeOps r_ops, uint8_t opcode = ITYPE_OPCODE);

                ~ITypeInstr() override = default;


                // override methods
                // std::string toString() const override; // TODO might be too much of a case-statement hassle
                uint32_t encode() const override;
                std::string toString() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<ITypeInstr>(*this);
                }
        private:
                uint8_t opcode;
                uint8_t funct7;
                uint8_t funct3;
                int16_t imm;
                uint8_t rs1;
                uint8_t rd;

                void setFunctBits(ITypeOps i_ops);
                void checkImmeidateRange(int16_t imm) const;
};

class LoadInstr : public RiscvInstruction {
        public:
                enum class LoadOps {
                LB,
                LH,
                LW,
                LBU,
                LHU
        };

                static constexpr uint8_t LOAD_OPCODE = 0b0000011;

                // constructor
                LoadInstr(uint8_t rd, uint8_t rs1, int16_t imm, LoadOps l_ops, uint8_t opcode = LOAD_OPCODE);

                ~LoadInstr() override = default;


                // override methods
                // std::string toString() const override; // TODO might be too much of a case-statement hassle
                uint32_t encode() const override;
                std::string toString() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<LoadInstr>(*this);
                }
        private:
                uint8_t opcode;
                uint8_t funct7;
                uint8_t funct3;
                int16_t imm;
                uint8_t rs1;
                uint8_t rd;

                void setFunctBits(LoadOps l_ops);
                void checkImmeidateRange(int16_t imm) const;
};

class StoreInstr : public RiscvInstruction {
        public:
                enum class StoreOps {
                SB,
                SH,
                SW
        };

                static constexpr uint8_t STORE_OPCODE = 0b0100011;

                StoreInstr(uint8_t rs1, uint8_t rs2, int16_t imm, StoreOps s_ops, uint8_t opcode = STORE_OPCODE);

                ~StoreInstr() override = default;

                uint32_t encode() const override;

                std::string toString() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<StoreInstr>(*this);
                }
        private:
                uint8_t opcode;
                uint8_t funct7;
                uint8_t funct3;
                int16_t imm;
                uint8_t rs1;
                uint8_t rs2;

                void setFunctBits(StoreOps s_ops);
                void checkImmeidateRange(int16_t imm) const;
};

class BTypeInstr : public RiscvInstruction {
        public:
                enum class BTypeOps {
                BEQ,
                BNE,
                BLT,
                BGE,
                BLTU,
                BGEU
        };

                static constexpr uint8_t BTYPE_OPCODE = 0b1100011;

                BTypeInstr(uint8_t rs1, uint8_t rs2, int16_t imm, BTypeOps b_ops, uint8_t opcode = BTYPE_OPCODE);

                ~BTypeInstr() override = default;

                uint32_t encode() const override;
                std::string toString() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<BTypeInstr>(*this);
                }
        private:
                uint8_t opcode;
                uint8_t funct7;
                uint8_t funct3;
                int16_t imm;
                uint8_t rs1;
                uint8_t rs2;

                void setFunctBits(BTypeOps b_ops);
                void checkImmeidateRange(int16_t imm) const;
};

class JTypeInstr : public RiscvInstruction {
        public:
                static constexpr uint8_t JTYPE_OPCODE = 0b1101111;

                // Constructor
                JTypeInstr(uint8_t rd, int32_t imm, uint8_t opcode = JTYPE_OPCODE);

                // Destructor
                ~JTypeInstr() override = default;

                // Override methods
                uint32_t encode() const override;
                std::string toString() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<JTypeInstr>(*this);
                }
        private:
                uint8_t opcode;
                int32_t imm;
                uint8_t rd;

                void checkImmediateRange(int32_t imm) const; // Function to check the range of imm
};

class JALRInstr : public RiscvInstruction {
        public:
                static constexpr uint8_t JALR_OPCODE = 0b1100111;
                static constexpr uint8_t JALR_FUNCT3 = 0b000;

                JALRInstr(uint8_t rd, uint8_t rs1, int16_t imm, uint8_t opcode = JALR_OPCODE);

                ~JALRInstr() override = default;

                uint32_t encode() const override;
                std::string toString() const override;
                std::shared_ptr<RiscvInstruction> clone() const override {
                        return std::make_shared<JALRInstr>(*this);
                }
        private:
                uint8_t opcode;
                uint8_t funct7;
                uint8_t funct3;
                int16_t imm;
                uint8_t rs1;
                uint8_t rd;

                void checkImmediateRange(int16_t imm) const;
};

#endif
