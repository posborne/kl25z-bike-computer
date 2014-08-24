#include <stdio.h>
#include "freedom.h"
#include "common.h"

extern char *_sbrk(int len);

static void bikecomputer_init()
{
    // Initialize all modules
    uart_init(115200);
    accel_init();
    touch_init((1 << 9) | (1 << 10));       // Channels 9 and 10
    // usb_init();
    setvbuf(stdin, NULL, _IONBF, 0);        // No buffering
}

static void bikecomputer_show_heap_usage()
{
    char i;
    char *heap_end;
    heap_end = _sbrk(0);
    iprintf("Reset code: 0x%02x 0x%02x\r\n", RCM_SRS0, RCM_SRS1);
    iprintf("Heap:  %p to %p (%d bytes used)\r\n", __heap_start, heap_end,
                heap_end - (char *)__heap_start);
    iprintf("Stack: %p to %p (%d bytes used)\r\n", &i, __StackTop,
                (char *)__StackTop - &i);
    iprintf("%d bytes free\r\n", &i - heap_end);
}

static void bikecomputer_show_blinkies()
{
    // Blink the green LED to indicate booting
    int i, val;
    const int delay_ms = 25;
    const int iterations = 1000 / delay_ms;
    for (i = 0; i < iterations; i++)
    {

        val = i % 2 == 0 ? 10 : 0;
        RGB_LED(val, 0, val);
        delay(25);
    }
    RGB_LED(0, 0, 3); // subtle blue glow
}

static void bikecomputer_tick()
{
    iprintf("bike-computer> ");
    getchar();
    iprintf("\r\n");
    iprintf("Inputs:  x=%5d   y=%5d   z=%5d ", accel_x(), accel_y(), accel_z());
    iprintf("touch=(%d,%d)\r\n", touch_data(9), touch_data(10));
    // usb_dump();
}

// Main program
int main(void)
{
    bikecomputer_init();
    bikecomputer_show_blinkies();

    // Welcome banner
    iprintf("\r\n\r\n====== Freescale Freedom FRDM-KL25Z\r\n");
    iprintf("Built: %s %s\r\n\r\n", __DATE__, __TIME__);

    bikecomputer_show_heap_usage();

    for (;;)
    {
        bikecomputer_tick();
    }

}
