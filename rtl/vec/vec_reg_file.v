
module vec_reg_file (
                     input              clk,
                     input              reset,
                     input [4:0]        v_rs1, // vector register 1
                     input [4:0]        v_rs2, // vector register 2
                     input [4:0]        v_rd, // vector dest reg
                     input [255:0]      v_writedata,
                     input              v_regwrite,
                     output reg [255:0] read_data1,
                     output reg [255:0] read_data2
                     );

   reg [31:0]                           register_array [0:31];
   reg [255:0]                          vec_register_array [0:31];

   integer                              i;
   always @(posedge clk or posedge reset) begin
      if (reset) begin
         for (i = 0; i < 32; i=i+1) begin
            vec_register_array[i] = 256'b0;
         end
      end else if (v_regwrite) begin
         vec_register_array[v_rd] = v_writedata;
      end else begin
         read_data1 <= vec_register_array[v_rs1];
         read_data2 <= vec_register_array[v_rs2];
      end
   end


endmodule
