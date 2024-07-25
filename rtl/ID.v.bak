module ID (
           input             clk,
           input             reset,
           input             writeback_control,
           input [4:0]       rd,
           input [31:0]      instruction,
           input [31:0]      pc,
           input [31:0]      pc_plus_4,
           input [31:0]      writeback_data,

           // forward
           input             stall_d,
           input             flush_d,

           output reg [31:0] immediate,
           output reg [31:0] rs1_data,
           output reg [31:0] rs2_data,
           output reg [4:0]  rd_out,
           // control unit outputs
           output reg        regwrite_d,
           output reg [1:0]  result_src_d,
           output wire [1:0] result_src_d_wire,
           output reg        memwrite_d,
           output reg        jump_d,
           output reg        branch_d,
           output reg [3:0]  alu_control_d,
           output reg [2:0]  branch_control_d,
           output reg        alu_src_d,
           // send to next pipeline
           output reg [31:0] id_ex_pc_plus_4,
           output reg [31:0] id_ex_pc,
           // forward/hazard unit
           output [4:0]      id_ex_rs1_d_wire,
           output [4:0]      id_ex_rs2_d_wire,
           output reg [4:0]  id_ex_rs1_d_reg,
           output reg [4:0]  id_ex_rs2_d_reg
           );


   reg [31:0]                reg_array [31:0]; // registers definition

   wire [4:0]                rs1;
   wire [4:0]                rs2;
   wire [6:0]                opcode;
   wire [2:0]                funct3;
   wire                      funct7b5;

   // intermediate wires
   wire [31:0]               immediate_temp;
   wire                      regwrite_d_temp, memwrite_d_temp, jump_d_temp, branch_d_temp, alu_src_d_temp;
   wire [3:0]                alu_control_d_temp;
   wire [2:0]                branch_control_d_temp;
   wire [1:0]                result_src_d_temp;

   assign result_src_d_wire = result_src_d_temp;

   // hazard
   assign id_ex_rs1_d_wire = rs1;
   assign id_ex_rs2_d_wire = rs2;

   // assigns
   assign rs1 = instruction[19:15];
   assign rs2 = instruction[24:20];
   // assign rd = instr[11:7];
   assign opcode = instruction[6:0];
   assign funct3 = instruction[14:12];
   assign funct7b5 = instruction[30];

   // fetch rs1_data and rs2_data
   integer                   i;
   always @(posedge clk or posedge reset) begin
      if (reset || flush_d) begin // flush_d is synchronous with the clock cycle
         //    for (i = 0; i < 32; i = i + 1) begin
         //       reg_array[i] <= 32'b0;
         //    end
         immediate <= 32'b0;
         regwrite_d <= 1'b0;
         memwrite_d <= 1'b0;
         jump_d <= 1'b0;
         branch_d <= 1'b0;
         alu_src_d <= 1'b0;
         alu_control_d <= 4'b0;
         branch_control_d <= 3'b0;
         result_src_d <= 2'b0;
         // foward
         id_ex_pc_plus_4 <= 32'b0;
         id_ex_pc <= 32'b0;
         // hazard
         id_ex_rs1_d_reg <= 5'b0;
         id_ex_rs2_d_reg <= 5'b0;
      end else if (!stall_d) begin
         rs1_data <= reg_array[rs1];
         rs2_data <= reg_array[rs2];
         rd_out <= instruction[11:7];
         immediate <= immediate_temp;
         regwrite_d <= regwrite_d_temp;
         memwrite_d <= memwrite_d_temp;
         jump_d <= jump_d_temp;
         branch_d <= branch_d_temp;
         alu_src_d <= alu_src_d_temp;
         alu_control_d <= alu_control_d_temp;
         branch_control_d <= branch_control_d_temp;
         result_src_d <= result_src_d_temp;
         // forward
         id_ex_pc_plus_4 <= pc_plus_4;
         id_ex_pc <= pc;
         // hazard
         id_ex_rs1_d_reg <= rs1;
         id_ex_rs2_d_reg <= rs2;
      end
   end

   // Handle writeback on negative edge of the clock
   always @(negedge clk or posedge reset) begin
      if (reset) begin
         for (i = 0; i < 32; i = i + 1) begin
            reg_array[i] <= 32'b0;
         end
      end else if (writeback_control) begin
         if (rd  != 5'b0) begin
            reg_array[rd] <= writeback_data;
         end
      end
   end

   //module instantiations
   imm_gen immediate_generation_unit (
                                      .instruction(instruction),
                                      .opcode(opcode),
                                      // output
                                      .immediate_out(immediate_temp)
                                      );

   control control_signal_unit (
                                .opcode(opcode),
                                .funct3(funct3),
                                .funct7b5(funct7b5),
                                //output
                                .regwrite_d(regwrite_d_temp),
                                .memwrite_d(memwrite_d_temp),
                                .jump_d(jump_d_temp),
                                .branch_d(branch_d_temp),
                                .alu_src_d(alu_src_d_temp),
                                .result_src_d(result_src_d_temp),
                                .alu_control_d(alu_control_d_temp),
                                .branch_control_d(branch_control_d_temp)
                                );

endmodule

// ID also has the control unit as part of it
// module ID (
//            input             clk,
//            input             reset,
//            input             writeback_control,
//            input [4:0]       rd,
//            input [31:0]      instruction,
//            input [31:0]      pc,
//            input [31:0]      pc_plus_4,
//            input [31:0]      writeback_data,

//            output reg [31:0] immediate,
//            output reg [31:0] rs1_data,
//            output reg [31:0] rs2_data,
//            output reg [4:0]  rd_out,
//            // control unit outputs
//            output reg        regwrite_d,
//            output reg [1:0]  result_src_d,
//            output reg        memwrite_d,
//            output reg        jump_d,
//            output reg        branch_d,
//            output reg [3:0]  alu_control_d,
//            output reg [2:0]  branch_control_d,
//            output reg        alu_src_d,
//            // forward
//            output reg [31:0] id_ex_pc_plus_4,
//            output reg [31:0] id_ex_pc
//            );

//    reg [31:0]                reg_array [31:0]; // registers definition

//    wire [4:0]                rs1;
//    wire [4:0]                rs2;
//    wire [6:0]                opcode;
//    wire [2:0]                funct3;
//    wire                      funct7b5;


//    // intermediate wires
//    wire [31:0]               immediate_temp;
//    wire                      regwrite_d_temp, memwrite_d_temp, jump_d_temp, branch_d_temp, alu_src_d_temp;
//    wire [3:0]                alu_control_d_temp;
//    wire [2:0]                branch_control_d_temp;
//    wire [1:0]                result_src_d_temp;



//    // assigns
//    assign rs1 = instruction[19:15];
//    assign rs2 = instruction[24:20];
//    // assign rd = instr[11:7];
//    assign opcode = instruction[6:0];
//    assign funct3 = instruction[14:12];
//    assign funct7b5 = instruction[30];


//    // fetch rs1_data and rs2_data
//    integer                   i;
//    always @(posedge clk or posedge reset) begin
//       if (reset) begin
//          for (i = 0; i < 32; i = i + 1) begin
//             reg_array[i] <= 32'b0;
//          end
//          immediate <= 32'b0;
//          regwrite_d <= 1'b0;
//          memwrite_d <= 1'b0;
//          jump_d <= 1'b0;
//          branch_d <= 1'b0;
//          alu_src_d <= 1'b0;
//          alu_control_d <= 4'b0;
//          branch_control_d <= 3'b0;
//          result_src_d <= 2'b0;
//          // foward
//          id_ex_pc_plus_4 <= 32'b0;
//          id_ex_pc <= 32'b0;
//       end else begin
//          if (writeback_control) begin
//             reg_array[rd] <= writeback_data;
//          end
//          rs1_data <= reg_array[rs1];
//          rs2_data <= reg_array[rs2];
//          rd_out <= instruction[11:7];
//          immediate <= immediate_temp;
//          regwrite_d <= regwrite_d_temp;
//          memwrite_d <= memwrite_d_temp;
//          jump_d <= jump_d_temp;
//          branch_d <= branch_d_temp;
//          alu_src_d <= alu_src_d_temp;
//          alu_control_d <= alu_control_d_temp;
//          branch_control_d <= branch_control_d_temp;
//          result_src_d <= result_src_d_temp;
//          // forward
//          id_ex_pc_plus_4 <= pc_plus_4;
//          id_ex_pc <= pc;
//       end
//    end

//    //module instantiations
//    imm_gen immediate_generation_unit (
//                                       .instruction(instruction),
//                                       .opcode(opcode),
//                                       // output
//                                       .immediate_out(immediate_temp)
//                                       );

//    control control_signal_unit (
//                                 .opcode(opcode),
//                                 .funct3(funct3),
//                                 .funct7b5(funct7b5),
//                                 //output
//                                 .regwrite_d(regwrite_d_temp),
//                                 .memwrite_d(memwrite_d_temp),
//                                 .jump_d(jump_d_temp),
//                                 .branch_d(branch_d_temp),
//                                 .alu_src_d(alu_src_d_temp),
//                                 .result_src_d(result_src_d_temp),
//                                 .alu_control_d(alu_control_d_temp),
//                                 .branch_control_d(branch_control_d_temp)
//                                 );


// endmodule
