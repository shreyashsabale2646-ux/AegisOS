section .text
global _start

_start:
    mov ah, 0x0e

    mov al, 'H'
    int 0x10

    mov al, 'i'
    int 0x10

hang:
    jmp hang
