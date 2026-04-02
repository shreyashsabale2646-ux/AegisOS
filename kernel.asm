[org 0x1000]

mov ah, 0x0e

; print first message
mov si, msg1
call print

; newline
mov al, 0x0D
int 0x10
mov al, 0x0A
int 0x10

; print second message
mov si, msg2
call print

jmp $

print:
    mov al, [si]
    cmp al, 0
    je done
    int 0x10
    inc si
    jmp print

done:
    ret

msg1 db 'KERNEL STAGE 2 OK', 0
msg2 db 'READY FOR NEXT STAGE', 0
