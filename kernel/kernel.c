#include "../drivers/screen.h"

void main() {
    screen_clear();
    screen_puts("hello world!");
    screen_puts("le stupid has not arrived!!!!");
    for (int i = 0; i < 500; i++) {
        screen_puts("test");
    }
}
