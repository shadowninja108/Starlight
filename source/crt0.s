.global __module_start

.section ".text.crt0","ax"
__module_start:
    .word 0 // This is a standard NSO
    .word __nx_mod0 - __module_start

.section ".rodata.application_name"
.word 0
.word 9
.ascii "Starlight\0"

.section ".rodata.mod0"
.global __nx_mod0
__nx_mod0:
    .ascii "MOD0"
    .word  __dynamic_start__      - __nx_mod0
    .word  __bss_start__          - __nx_mod0
    .word  __bss_end__            - __nx_mod0
    .word  __eh_frame_hdr_start__ - __nx_mod0
    .word  __eh_frame_hdr_end__   - __nx_mod0
    .word __nx_module_runtime     - __nx_mod0
