[org 0x7c00]

mov [BOOT_DRIVE], dl

mov bx, 0x1000
mov dh, 1
mov dl, [BOOT_DRIVE]
call disk_load

; disable interrupts
cli

; simple protected mode prep
mov eax, cr0
or eax, 0x1
mov cr0, eax

; jump to kernel (may not fully work yet)
jmp 0x1000

jmp $

BOOT_DRIVE db 0

disk_load:
    pusha
    mov ah, 0x02
    mov al, dh
    mov ch, 0x00
    mov dh, 0x00
    mov cl, 0x02
    int 0x13
    jc disk_error
    popa
    ret

disk_error:
    mov ah, 0x0e
    mov al, 'E'
    int 0x10
    jmp $

times 510 - ($ - $$) db 0
dw 0xaa55
