# RISCV Vector "V" extension

- max vsew is 32bit

important vector registers:
- v0: is the vector mask register (prob implement this stuff later)

types of vector instructions (arithmetic):
- v(alu_code).v(v, x, i)
- v: vector with vector
- x: vector with register value 
- i: vector with immediate value

### implementation notes
Novel aspect of the following RTL for RVV processor (currently, only implemented up to VV, VX, VI instruction with masking operation), is that instead of using unrealistic for loops for all combinations of the VLEN, VSEW, the module is parameterized by NUM_PE, which defines the number of processing elements. The module will calculate the number of cycles needed as a function of VLEN, VSEW, NUM_PE, and take multiple cycles to complete.

The above strategy makes it so that the design's size remains reasonable, and synthesizable. For instance, calculation of required cycle intuitively requires division, but characteristics of binary digits were used to implement the cycle num required only using bit shift operators.
