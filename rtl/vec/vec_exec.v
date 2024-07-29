
module vec_exec (
                 input          clk,
                 input          reset,
                 input [2:0]    vsew,
                 input [5:0]    funct6,
                 input [31:0]   vlen,
                 input [255:0]  operand_a,
                 input [255:0]  operand_b,
                 output reg [255:0] vec_exec_out,
                 output reg vec_op_done
                 );

   parameter                    NUM_PE = 4;

   reg [3:0]                    state;
   reg [31:0]                   count; // can use a much smaller reg dont need 32 bits (max(vlen) / min(vsew))
   reg [31:0]                   num_elements;
   integer                      element_width;
   integer                      elements_per_cycle;
   integer                      num_cycles_needed;
   integer                      i;


   generate
      genvar                    pe_idx;
      for (pe_idx = 0; pe_idx < NUM_PE; pe_idx = pe_idx + 1) begin : pe_block
         vec_processing_element pe (
                                .a(pe_a[pe_idx]),
                                .b(pe_b[pe_idx]),
                                .funct6(funct6),
                                .result(pe_result[pe_idx])
                                );
      end
   endgenerate


endmodule
