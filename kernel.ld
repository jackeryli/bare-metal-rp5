ENTRY( _entry )

SECTIONS
{
  . = 0x80000;
  .text :
  {
    *(.text)
  }
  .data :
  {
    *(.data)
  }
  .bss ALIGN(16) (NOLOAD) :
  {
    __bss_start = .;

    *(.bss)

    __bss_end = .;
  }
  _end = .;
}