/*
flash is non-volatile memory, for stuff that needs to persist even when power turns off
RAM is volatile memory, for stuff that only exist when power is only
hence why the initial values of data is in FLASH, but when running it is stored in RAM
*/

MEMORY
{
    FLASH (rx)  : ORIGIN = 0x00000000, LENGTH = 512K
    RAM (rwx)   : ORIGIN = 0x00080000, LENGTH = 128K
}

SECTIONS
{
    .text : {
        KEEP(*(.vectors))
        *(.text)
        *(.text*)
        *(.rodata)
        *(.rodata*)
        *(.init)
        *(.fini)
        PROVIDE(__global_pointer$ = . + 0x0);
    } > FLASH

    .data : {
        __data_start = .;
        *(.data)
        *(.data*)
        __data_end = .;
    } > RAM AT > FLASH

    .bss : {
        __bss_start = .;
        *(.bss)
        *(.bss*)
        *(COMMON)
        __bss_end = .;
    } > RAM

    . = ALIGN(4);
    _end = .;
}
