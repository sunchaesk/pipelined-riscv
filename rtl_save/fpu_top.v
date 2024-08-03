module fpu_top (input             clk,
    input             reset,
    input [31:0]      in_a,
    input [31:0]      in_b,
    output reg [31:0] out
);

    // Extract components from inputs
    wire sign_a = in_a[31];
    wire sign_b = in_b[31];
    wire [7:0] exp_a = in_a[30:23];
    wire [7:0] exp_b = in_b[30:23];
    wire [22:0] mantissa_a = in_a[22:0];
    wire [22:0] mantissa_b = in_b[22:0];

    // Intermediate signals for exponent operations
    wire exp_a_gt_b = exp_a > exp_b;
    wire exp_equal = (exp_a == exp_b);
    reg [7:0] exp_diff;
    reg [7:0] exp_prenorm;

    // Calculate exponent difference and normalization exponent
    always @(*) begin
        if (exp_a_gt_b) begin
            exp_diff = exp_a - exp_b;
            exp_prenorm = exp_a;
        end else begin
            exp_diff = exp_b - exp_a;
            exp_prenorm = exp_b;
        end
    end

    // Align mantissas
    reg [23:0] aligned_mantissa_a, aligned_mantissa_b;

    always @(*) begin
        if (exp_a_gt_b) begin
            aligned_mantissa_a = {1'b1, mantissa_a}; // Add implicit leading 1
            aligned_mantissa_b = {1'b1, mantissa_b} >> exp_diff;
        end else begin
            aligned_mantissa_a = {1'b1, mantissa_a} >> exp_diff;
            aligned_mantissa_b = {1'b1, mantissa_b}; // Add implicit leading 1
        end
    end

    // Add or subtract mantissas
    reg [24:0] mantissa_sum;
    reg result_sign;

    always @(*) begin
        if (sign_a == sign_b) begin
            mantissa_sum = aligned_mantissa_a + aligned_mantissa_b;
            result_sign = sign_a;
        end else begin
            if (aligned_mantissa_a >= aligned_mantissa_b) begin
                mantissa_sum = aligned_mantissa_a - aligned_mantissa_b;
                result_sign = sign_a;
            end else begin
                mantissa_sum = aligned_mantissa_b - aligned_mantissa_a;
                result_sign = sign_b;
            end
        end
    end

    // Normalize result
    reg [23:0] normalized_mantissa;
    reg [7:0] normalized_exp;

    always @(*) begin
        if (mantissa_sum[24]) begin
            normalized_mantissa = mantissa_sum[23:0];
            normalized_exp = exp_prenorm + 1;
        end else begin
            normalized_mantissa = mantissa_sum[23:0];
            normalized_exp = exp_prenorm;
            while (normalized_mantissa[23] == 0 && normalized_exp > 0) begin
                normalized_mantissa = normalized_mantissa << 1;
                normalized_exp = normalized_exp - 1;
            end
        end
    end

    // Round and pack result
    reg [22:0] final_mantissa;

    always @(*) begin
        // Simple rounding: Add 0.5 if LSB of normalized mantissa is 1
        if (normalized_mantissa[0]) begin
            final_mantissa = normalized_mantissa[23:1] + 1;
            if (final_mantissa == 23'hFFFFFF) begin
                normalized_exp = normalized_exp + 1;
            end
        end else begin
            final_mantissa = normalized_mantissa[23:1];
        end
    end

    // Output result
    always @(posedge clk or posedge reset) begin
        if (reset) begin
            out <= 32'b0;
        end else begin
            out <= {result_sign, normalized_exp, final_mantissa};
        end
    end

endmodule
