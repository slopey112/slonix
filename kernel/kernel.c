#include "../drivers/screen.h"
#include "../cpu/isr.h"
#include "../lib/string.h"

void main() {
    screen_clear();
    isr_install();
    __asm__ __volatile__("int $2");
    __asm__ __volatile__("int $3");
}
