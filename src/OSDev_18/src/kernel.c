#include <libc/stdint.h>
#include <kernel/terminal.h>
#include <kernel/gdt.h>

void main(void) {
    gdtInitialize();

    terminalInitialize();
    terminalWriteString("Hello, World!\n");
    
    for (;;) {
        __asm__ volatile ("hlt");
    }
}