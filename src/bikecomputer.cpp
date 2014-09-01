#include "mbed.h"

DigitalOut g(LED_GREEN);
DigitalOut r(LED_RED);
DigitalOut b(LED_BLUE);
DigitalIn gpio_d5(PTD5);

static uint8_t const LED_OFF = 1;
static uint8_t const LED_ON = 0;

int main()
{
    g.write(LED_OFF);
    r.write(LED_OFF);
    b.write(LED_OFF);
    while (true) {
        if (gpio_d5) {
            g.write(LED_ON);
        } else {
            g.write(LED_OFF);
        }
        wait_ms(50);
    }
}
