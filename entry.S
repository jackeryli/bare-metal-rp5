.section .text
.global _entry

_entry:
  mrs     x1, MPIDR_EL1     // Read Register to x1
  and     x1, x1, #3        // Extract cpu_id from x1
  cbz     x1, 2f            // If cpu=0, jump to 2

1:
  wfe                       // Wait for Event instruction
  b       1b                // Jump to 1

2:
  ldr     x1, =_entry       // Load the address of _entry to x1
  mov     sp, x1            // move stack pointer to x1

  // clear bss
  ldr     x1, =__bss_start  // Load __bss_start to x1
  ldr     x2, =__bss_end    // Load __bss_end to x2

3:
  cmp     x1, x2            // Compare x1 and x2
  beq     4f                // if x1=x2, jump to 4
  str     xzr, [x1], #8
  sub     x2, x2, #1
  cbnz    x2, 3b

4:
  bl      start             // Jump to start function in C
  b       1b                // Halt this core if return