
module vec_processing_element (
                               input [63:0]  a,
                               input [63:0]  b,
                               input [5:0]   funct6,
                               output reg [63:0] result
                               );

   localparam                                VADD = 6'b000000;
   localparam                                VSUB = 6'b000010;
   localparam                                VAND = 6'b001001;
   localparam                                VOR = 6'b001010;
   localparam                                VXOR = 6'b001011;
   localparam                                VMV = 6'b010111;
   localparam                                VSLIDEUP = 6'b001110;
   localparam                                VSLIDEDOWN = 6'b001111;

   always @(*) begin
      case(funct6)
        VADD: result = a + b;
        VSUB: result = a - b;
        VAND: result = a & b;
        VOR: result = a | b;
        VXOR: result = a ^ b;
        VMV: result = a;
        VSLIDEUP: result = (a << b[4:0]) | (a >> (32 - b[4:0])); // Barrel shift left
        VSLIDEDOWN: result = (a >> b[4:0]) | (a << (32 - b[4:0]));
        default: result = 64'b0;
      endcase
   end

endmodule
