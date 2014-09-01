#include "mbed.h"

static const PinName PIN_REED_SWITCH = PTD5;

DigitalOut g(LED_GREEN);
DigitalOut r(LED_RED);
DigitalOut b(LED_BLUE);
InterruptIn reed_switch_interrupt(PIN_REED_SWITCH);


static uint8_t const LED_OFF = 1;
static uint8_t const LED_ON = 0;

static void reed_switch_rising()
{
    g.write(LED_ON);
}

static void reed_switch_falling()
{
    g.write(LED_OFF);
}

int main()
{
    reed_switch_interrupt.rise(&reed_switch_rising);
    reed_switch_interrupt.fall(&reed_switch_falling);
    g.write(LED_OFF);
    r.write(LED_OFF);
    b.write(LED_OFF);
    while (true) {
        wait_ms(50);
    }
}
