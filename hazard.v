module hazard (
                    input [4:0]  rs1_d,
                    input [4:0]  rs2_d,
                    input        pc_src_e,
                    input [4:0]  rs1_e,
                    input [4:0]  rs2_e,
                    input [4:0]  rd_e,
                    input        result_src_e_0,
                    input        memwrite_m,
                    input        regwrite_w,
                    input [4:0]  rd_m,
                    input        regwrite_m,
                    input [4:0]  rd_w,
                    output       stall_f,
                    output       stall_d,
                    output       flush_d,
                    output       flush_e,
                    output [1:0] forward_operand_a_e,
                    output [1:0] forward_operand_b_e
                    );

   wire lw_stall;

   // forward operand a
   assign forward_operand_a_e = ((rs1_e == rd_m) & regwrite_m & (rs1_e != 5'b0)) ? 2'b01 :
                                ((rs1_e == rd_w) & regwrite_w & (rs1_e != 5'b0)) ? 2'b10 : 2'b00;

   // forward operand b
   assign forward_operand_b_e = ((rs2_e == rd_m) & regwrite_m & (rs2_e != 5'b0)) ? 2'b01 :
                                ((rs2_e == rd_w) & regwrite_w & (rs2_e != 5'b0)) ? 2'b10 : 2'b00;

   assign lw_stall = result_src_e_0 & ((rs1_d == rd_e) | (rs2_d == rd_e));
   assign stall_f = lw_stall;
   assign stall_d = lw_stall;

   assign flush_d = pc_src_e;
   assign flush_e = lw_stall | pc_src_e;

endmodule
