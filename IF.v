// module IF (
//            input             clk,
//            input             reset,
//            input             pc_src, // Control signal to select between PC + 4 and branch destination
//            input             stall_f,
//            input [31:0]      pc_branch_dest, // Branch target address
//            output reg [31:0] pc, // Program counter
//            output reg [31:0] pc_plus_4, // Program counter + 4
//            output reg [31:0] instruction // Current instruction
//            );

//    reg [31:0]                instr_mem [31:0]; // Instruction memory
//    reg [31:0]                next_pc;           // Next program counter value

//    // Calculate next PC value based on control signal
//    always @(*) begin
//       if (pc_src) begin
//          next_pc = pc_branch_dest;
//       end else begin
//          next_pc = pc + 4;
//       end
//    end

//    // Update the current program counter and instruction
//    always @(posedge clk or posedge reset) begin
//       if (reset) begin
//          pc <= 0;
//          pc_plus_4 <= 4; // Initialize to 4 on reset
//          instruction <= instr_mem[0]; // Assuming the instruction memory starts from address 0
//       end else if (!stall_f) begin
//          pc <= next_pc;
//          instruction <= instr_mem[next_pc >> 2];
//          pc_plus_4 <= next_pc + 4; // Calculate the program counter + 4 based on the next PC
//       end
//    end

// endmodule

module IF (
           input             clk,
           input             reset,
           input             pc_src, // Control signal to select between PC + 4 and branch destination
           input             stall_f,
           input [31:0]      pc_branch_dest, // Branch target address
           output reg [31:0] pc, // Program counter
           output reg [31:0] pc_plus_4, // Program counter + 4
           output reg [31:0] instruction // Current instruction
           );

   // reg [31:0]                instr_mem [0:255]; // Instruction memory
   reg [31:0]                instr_mem [31:0]; // Instruction memory
   reg [31:0]                next_pc;           // Next program counter value


   // Update the current program counter and instruction
   always @(posedge clk or posedge reset) begin
      if (reset) begin
         pc <= 0;
         pc_plus_4 <= 4; // Initialize to 4 on reset
         instruction <= instr_mem[0]; // Assuming the instruction memory starts from address 0
         next_pc <= 4; // Initialize next_pc to 4 on reset
      end else if (!stall_f) begin
         pc <= next_pc;
         instruction <= instr_mem[next_pc >> 2];
         pc_plus_4 <= next_pc + 4; // Calculate the program counter + 4 based on the next PC
         next_pc <= pc_src ? pc_branch_dest : (next_pc + 4);
      end
   end

endmodule
// module IF (
//     input clk,
//     input reset,
//     input pc_src,                // Control signal to select between PC + 4 and branch destination
//     input [31:0] pc_branch_dest, // Branch target address
//     output reg [31:0] pc,        // Program counter
//     output reg [31:0] pc_plus_4, // Program counter + 4
//     output reg [31:0] instruction // Current instruction
// );

//     reg [31:0] instr_mem [0:255]; // Instruction memory
//     reg [31:0] next_pc;           // Next program counter value


//     // Update the current program counter and instruction
//     always @(posedge clk or posedge reset) begin
//         if (reset) begin
//             pc <= 0;
//             pc_plus_4 <= 4; // Initialize to 4 on reset
//             instruction <= instr_mem[0]; // Assuming the instruction memory starts from address 0
//         end else begin
//             pc <= next_pc;
//             instruction <= instr_mem[next_pc >> 2];
//             pc_plus_4 <= next_pc + 4; // Calculate the program counter + 4 based on the next PC
//         end
//     end

//     // Determine the next program counter value
//     always @(*) begin
//         next_pc = pc_src ? pc_branch_dest : pc + 4;
//     end

// endmodule

// module IF (
//     input clk,
//     input reset,
//     input pc_src,             // Control signal to select between PC + 4 and branch destination
//     input [31:0] pc_branch_dest, // Branch target address
//     output reg [31:0] pc,     // Program counter
//     output reg [31:0] pc_plus_4, // Program counter + 4
//     output reg [31:0] instruction // Current instruction
// );

//     reg [31:0] instr_mem [0:255]; // Instruction memory

//     reg [31:0] next_count;      // Next program counter value
//     reg [31:0] curr_count;       // Current program counter value

//     // Update the current program counter value
//     always @(posedge clk or posedge reset) begin
//         if (reset) begin
//             curr_count <= 0;
//         end else begin
//             curr_count <= next_count;
//         end
//     end

//     // Fetch the instruction from memory
//     always @(posedge clk or posedge reset) begin
//         if (reset) begin
//             instruction <= 0;
//         end else begin
//             instruction <= instr_mem[curr_count >> 2];
//         end
//     end

//     // Calculate the program counter + 4
//     always @(*) begin
//         pc_plus_4 = curr_count + 4;
//     end

//     // Output the current program counter value
//     always @(*) begin
//         pc = curr_count;
//     end

//     // Determine the next program counter value
//     always @(*) begin
//         next_count = pc_src ? pc_branch_dest : pc + 4;
//     end

// endmodule
