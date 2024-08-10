.section text
.globl _start

_start:
    andi x17, x31, -283
    srai x23, x17, 25
    srli x29, x31, 26
    andi x6, x7, 1272
    slli x25, x17, 13
    srli x5, x6, 7
    sub x31, x12, x22
    xor x15, x9, x15
    addi x19, x9, -1893
    and x28, x22, x15
