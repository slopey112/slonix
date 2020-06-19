#include "screen.h"
#include "ports.h"

int get_cursor_position();
void set_cursor_position(int position);
void write_to_video_memory(unsigned char c, unsigned char attrib, int position);
unsigned char color_to_attr(unsigned char foreground, unsigned char background);

/*
 * NAME: screen_puts
 *
 * DESCRIPTION:
 *     Every character in the target string is printed on the string using the screen_putchar function.
 *
 * PARAMETERS:
 *     char *string    A string to print on the screen.
 *
 * RETURNS:
 *     void
 *
 */
void screen_puts(char *string) {
    int i = 0;
    while (string[i] != 0) {
        screen_putchar(string[i]);
        i++;
    }
    screen_putchar('\n');
}

/*
 * NAME: screen_clear
 *
 * DESCRIPTION:
 *     Clears the entire screen, filling each cell with a space character.
 *
 * PARAMTERS:
 *     void
 *
 * RETURNS:
 *     void
 *
 */
void screen_clear() {
    for (int i = 0; i < SCREEN_MAX_COLS * SCREEN_MAX_ROWS; i++) {
        write_to_video_memory(' ', 0x0f, i * 2);
    }
    set_cursor_position(0);
}

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

    position = get_cursor_position();
    if (c == '\n') {
        int row = position / (SCREEN_MAX_COLS * 2);
        position = 2 * (row + 1) * SCREEN_MAX_COLS;
    } else {
        write_to_video_memory(c, 0x0f, position);
        position += 2;
    }
    set_cursor_position(position);
}

int get_cursor_position() {
    int position;

    port_byte_out(SCREEN_ADDR_REGISTER, 14);
    position = port_byte_in(SCREEN_DATA_REGISTER) << 8;
    port_byte_out(SCREEN_ADDR_REGISTER, 15);
    position += port_byte_in(SCREEN_DATA_REGISTER); 
    return position * 2;
}

void set_cursor_position(int position) {
    position /= 2;
    port_byte_out(SCREEN_ADDR_REGISTER, 14);
    port_byte_out(SCREEN_DATA_REGISTER, (unsigned char) (position >> 8));
    port_byte_out(SCREEN_ADDR_REGISTER, 15);
    port_byte_out(SCREEN_DATA_REGISTER, (unsigned char) (position & 0xff));
}

void write_to_video_memory(unsigned char c, unsigned char attrib, int position) {
    unsigned char *video_memory = (unsigned char *) SCREEN_VIDEO_MEMORY;
    video_memory[position] = c;
    video_memory[position + 1] = attrib;
}

unsigned char color_to_attrib(unsigned char foreground, unsigned char background) {
    return foreground + (background << 4);
}



