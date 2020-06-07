[org 0x7c00]

mov ah, 0x0e
mov al, "s"
int 0x10
mov al, "l"
int 0x10
mov al, "o"
int 0x10
mov al, "n"
int 0x10
mov al, "i"
int 0x10
mov al, "x"
int 0x10

jump $

times 510-($-$$) db 0
dw 0xaa55
