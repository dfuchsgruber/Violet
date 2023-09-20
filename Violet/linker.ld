OUTPUT_ARCH(arm)
MEMORY {
        rom     : ORIGIN = 0x09000000, LENGTH = 32M
        ewram   : ORIGIN = 0x02000000, LENGTH = 4M - 4k
}

SECTIONS {
        .text : 
        ALIGN(4)
        {
                *(.text*)
        }

        .rodata :
        ALIGN(4)
        {
                *(.rodata*)
        } >rom = 0xff
        /* Discard everything not specifically mentioned above. */
        /DISCARD/ :
        {
                *(*);
        }
}
