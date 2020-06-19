#include "screen.h"
#include "ports.h"

int get_cursor_position();
void set_cursor_position(int position);

/*
 * NAME: screen_putchar
 *
 * DESCRIPTION:
 *     Puts a single character on the screen at the current cursor position.
 *
 * PARAMTERS:
 *     char c    A single character to output.
 *
 * RETURNS:
 *     void
 *
 */
void screen_putchar(char c) {
    int position;
    unsigned char *video_memory = (unsigned char *) SCREEN_VIDEO_MEMORY;

    position = get_cursor_position();
    video_memory[position] = c;
    video_memory[position + 1] = 0x0f;
    position += 2;
    set_cursor_position(position);
}

/*
 * NAME: get_cursoir_offset
 *
 * DESCRIPTION:
 *     Fetches the current cursor position from the VGA ports.
 *
 * PARAMTERS:
 *     void
 *
 * RETURNS:
 *     int position    An integer representing the current cursor position.
 *
 */
int get_cursor_position() {
    int position;

    port_byte_out(SCREEN_ADDR_REGISTER, 14);
    position = port_byte_in(SCREEN_DATA_REGISTER) << 8;
    port_byte_out(SCREEN_ADDR_REGISTER, 15);
    position += port_byte_in(SCREEN_DATA_REGISTER); 
    return position * 2;
}

/*
 * NAME: set_cursor_offset
 *
 * DESCRIPTION:
 *     Sets the cursor position through the VGA I/O ports.
 *
 * PARAMTERS:
 *     int position    An integer representing the desired cursor position.
 *
 * RETURNS:
 *     void
 *
 */
void set_cursor_position(int position) {
    position /= 2;
    port_byte_out(SCREEN_ADDR_REGISTER, 14);
    port_byte_out(SCREEN_DATA_REGISTER, (unsigned char) (position >> 8));
    port_byte_out(SCREEN_ADDR_REGISTER, 15);
    port_byte_out(SCREEN_DATA_REGISTER, (unsigned char) (position & 0xff));
}
