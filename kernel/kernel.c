#include "../drivers/ports.h"

void main() {
    unsigned short input_register = 0x3d4, output_register = 0x3d5;
    int position;
    int vga_offset;
    char *vga = 0xb8000;

    port_byte_out(input_register, 14);
    position = port_byte_in(output_register);
    position = position << 8;
    port_byte_out(input_register, 15);
    position += port_byte_in(input_register);
    vga_offset = position * 2;
    vga[vga_offset] = 'X';
    vga[vga_offset + 1] = 0x0f;
}
