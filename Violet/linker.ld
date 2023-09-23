PHDRS
{
  headers PT_PHDR PHDRS ;
  interp PT_INTERP ;
  text PT_LOAD FILEHDR PHDRS ;
  data PT_LOAD ;
  dynamic PT_DYNAMIC ;
  test PT_SHLIB ;
}

OUTPUT_ARCH(arm)
MEMORY {
        rom     : ORIGIN = 0x09000000, LENGTH = 32M
        /* 4K are gained from the helper system, but in theory everything to the end of EWRAM 0x4e8c should be garbage firered features  */
        ewram   : ORIGIN = 0x0203b174, LENGTH = 0x4000
}

SECTIONS {
        .text : 
        ALIGN(4)
        {
                *(.text*)
        } >rom :text = 0xff

        .rodata :
        ALIGN(4)
        {
                *(.rodata*)
        } >rom :text = 0xff

        free_ewram(NOLOAD) : AT(0x0203b174)
        {
                *(free_ewram)
        } >ewram
        /* Discard everything not specifically mentioned above. */
        /DISCARD/ :
        {
                *(*);
        }
}
