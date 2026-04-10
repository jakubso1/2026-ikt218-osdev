%define GDT_CODE_SELECTOR 0x08
%define GDT_DATA_SELECTOR 0x10

global gdtFlush

section .text
bits 32

gdtFlush:
    mov eax, [esp + 4]
    lgdt [eax]

    jmp GDT_CODE_SELECTOR:.reload_cs

.reload_cs:
    mov ax, GDT_DATA_SELECTOR
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret