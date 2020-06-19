#define SCREEN_VIDEO_MEMORY 0xb8000
#define SCREEN_ADDR_REGISTER 0x3d4
#define SCREEN_DATA_REGISTER 0x3d5
#define SCREEN_MAX_COLS 80
#define SCREEN_MAX_ROWS 25

void screen_putchar(char c);
void screen_clear();
void screen_puts(char *string);
