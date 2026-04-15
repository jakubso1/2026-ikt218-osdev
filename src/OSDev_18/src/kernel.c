#include <libc/stdint.h>
#include <kernel/terminal.h>
#include <kernel/gdt.h>
#include <kernel/idt.h>
#include <kernel/interrupt.h>
#include <kernel/keyboard.h>
#include <kernel/memory.h>
#include <kernel/pit.h>


/*TODO
clean up terminal - enable scrolling?

*/


extern uint32_t end;

void main(void) {
    TerminalInitialize();
    GdtInitialize();
    IdtInitialize();
    PitInitialize();

    RegisterInterruptHandler(IRQ1, KeyboardHandler);

    InitKernelMemory(&end);
    InitPaging();
    PrintMemoryLayout();

    void* memory1 = malloc(48261);
    void* memory2 = malloc(27261);
    void* memory3 = malloc(12617);

    TerminalWriteString("memory1 = ");
    TerminalWriteHex((uint32_t)memory1);
    TerminalWriteString("\n");

    TerminalWriteString("memory2 = ");
    TerminalWriteHex((uint32_t)memory2);
    TerminalWriteString("\n");

    TerminalWriteString("memory3 = ");
    TerminalWriteHex((uint32_t)memory3);
    TerminalWriteString("\n");

    free(memory2);

    void* memory4 = malloc(1000);

    TerminalWriteString("memory4 = ");
    TerminalWriteHex((uint32_t)memory4);
    TerminalWriteString("\n");

    SleepTest();

    for (;;) {
        __asm__ volatile("hlt");
    }
}