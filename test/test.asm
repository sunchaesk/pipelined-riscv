.section text
.globl _start

_start:
    xori x20, x8, 1356
    srai x24, x10, 25
    and x6, x29, x10
    xor x7, x29, x31
    addi x24, x0, -1936
    and x26, x7, x10
    srai x11, x10, 22
    sub x24, x7, x8
    add x8, x7, x26
    add x10, x15, x18
