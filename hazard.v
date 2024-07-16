module hazard (
               input [4:0]       rs1_d,
               input [4:0]       rs2_d,
               input             pc_src_e,
               input [4:0]       rs1_e,
               input [4:0]       rs2_e,
               input [4:0]       rd_e,
               input             result_src_e_0,
               input             regwrite_w,
               input [4:0]       rd_m,
               input             regwrite_m,
               input [4:0]       rd_w,
               input             clk,
               input             reset,
               // output wire       stall_f,
               // output wire       stall_d,
               // output wire       flush_e,
               output reg        stall_f,
               output reg        stall_d,
               output reg        flush_e,
               output reg        flush_d,
               output wire [1:0] forward_operand_a_e,
               output wire [1:0] forward_operand_b_e
               );

   wire                          lw_stall;

   // Combinational logic for forwarding
   assign forward_operand_a_e = ((rs1_e == rd_m) & regwrite_m & (rs1_e != 5'b0)) ? 2'b10 :
                                ((rs1_e == rd_w) & regwrite_w & (rs1_e != 5'b0)) ? 2'b01 : 2'b00;

   assign forward_operand_b_e = ((rs2_e == rd_m) & regwrite_m & (rs2_e != 5'b0)) ? 2'b10 :
                                ((rs2_e == rd_w) & regwrite_w & (rs2_e != 5'b0)) ? 2'b01 : 2'b00;

   // Combinational logic for lw_stall
   assign lw_stall = result_src_e_0 & ((rs1_d == rd_e) | (rs2_d == rd_e));
   // assign stall_d = lw_stall;
   // assign stall_f = lw_stall;
   // assign flush_e = lw_stall | pc_src_e;

   always @(posedge clk or posedge reset) begin
      if (reset) begin
         stall_d <= 1'b0;
         stall_f <= 1'b0;
         flush_e <= 1'b0;
         flush_d <= 1'b0;
      end else begin
         // assign stall and flush signals
         stall_d <= lw_stall;
         stall_f <= lw_stall;
         flush_e <= lw_stall | pc_src_e;
         flush_d <= pc_src_e;
      end
   end
endmodule

// module hazard (
//                input [4:0]      rs1_d,
//                input [4:0]      rs2_d,
//                input            pc_src_e,
//                input [4:0]      rs1_e,
//                input [4:0]      rs2_e,
//                input [4:0]      rd_e,
//                input            result_src_e_0,
//                input            regwrite_w,
//                input [4:0]      rd_m,
//                input            regwrite_m,
//                input [4:0]      rd_w,
//                input            clk,
//                input            reset,
//                output reg       stall_f,
//                output reg       stall_d,
//                output reg       flush_d,
//                output reg       flush_e,
//                output reg [1:0] forward_operand_a_e,
//                output reg [1:0] forward_operand_b_e
//                );

//    reg                          lw_stall;

//    always @(posedge clk or posedge reset) begin
//       if (reset) begin
//          forward_operand_a_e <= 2'b00;
//          forward_operand_b_e <= 2'b00;
//          lw_stall <= 1'b0;
//          stall_f <= 1'b0;
//          stall_d <= 1'b0;
//          flush_d <= 1'b0;
//          flush_e <= 1'b0;
//       end else begin
//          // forward operand a
//          forward_operand_a_e <= ((rs1_e == rd_m) & regwrite_m & (rs1_e != 5'b0)) ? 2'b01 :
//                                 ((rs1_e == rd_w) & regwrite_w & (rs1_e != 5'b0)) ? 2'b10 : 2'b00;

//          // forward operand b
//          forward_operand_b_e <= ((rs2_e == rd_m) & regwrite_m & (rs2_e != 5'b0)) ? 2'b01 :
//                                 ((rs2_e == rd_w) & regwrite_w & (rs2_e != 5'b0)) ? 2'b10 : 2'b00;

//          // calculate lw_stall
//          lw_stall <= result_src_e_0 & ((rs1_d == rd_e) | (rs2_d == rd_e));

//          // assign stall and flush signals
//          stall_f <= lw_stall;
//          stall_d <= lw_stall;
//          flush_d <= pc_src_e;
//          flush_e <= lw_stall | pc_src_e;
//       end
//    end
// endmodule
// module hazard (
//                     input [4:0]  rs1_d,
//                     input [4:0]  rs2_d,
//                     input        pc_src_e,
//                     input [4:0]  rs1_e,
//                     input [4:0]  rs2_e,
//                     input [4:0]  rd_e,
//                     input        result_src_e_0,
//                     input        regwrite_w,
//                     input [4:0]  rd_m,
//                     input        regwrite_m,
//                     input [4:0]  rd_w,
//                     //input [31:0] alu_result_m,
//                     output       stall_f,
//                     output       stall_d,
//                     output       flush_d,
//                     output       flush_e,
//                     output [1:0] forward_operand_a_e,
//                     output [1:0] forward_operand_b_e
//                     );

//    wire lw_stall;

//    // forward operand a
//    assign forward_operand_a_e = ((rs1_e == rd_m) & regwrite_m & (rs1_e != 5'b0)) ? 2'b01 :
//                                 ((rs1_e == rd_w) & regwrite_w & (rs1_e != 5'b0)) ? 2'b10 : 2'b00;

//    // forward operand b
//    assign forward_operand_b_e = ((rs2_e == rd_m) & regwrite_m & (rs2_e != 5'b0)) ? 2'b01 :
//                                 ((rs2_e == rd_w) & regwrite_w & (rs2_e != 5'b0)) ? 2'b10 : 2'b00;

//    assign lw_stall = result_src_e_0 & ((rs1_d == rd_e) | (rs2_d == rd_e));
//    assign stall_f = lw_stall;
//    assign stall_d = lw_stall;

//    assign flush_d = pc_src_e;
//    assign flush_e = lw_stall | pc_src_e;

// endmodule
