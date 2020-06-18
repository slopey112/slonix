[org 0x7c00]

mov bx, HELLO
call print
call println

mov bx, GOODBYE
call print
call println

jmp $

%include "boot_sect_print.asm"

HELLO:
    db 'Hello, World', 0

GOODBYE:
    db 'Goodbye', 0

times 510-($-$$) db 0
dw 0xaa55
