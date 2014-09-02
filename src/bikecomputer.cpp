#include "mbed.h"
#include "debug.h"

static const PinName PIN_REED_SWITCH = PTD5;
static const PinName PIN_SPI_SCK = PTD1;
static const PinName PIN_SPI_MOSI = PTD2;
static const PinName PIN_SPI_MISO = PTD3;

/* Debug UART */
static const PinName PIN_SERIAL_RX = PTA1;
static const PinName PIN_SERIAL_TX = PTA2;
static Serial debugSerialPort(PIN_SERIAL_TX, PIN_SERIAL_RX, "debug");
static DebugSerialPort dbg(debugSerialPort);

DigitalOut g(LED_GREEN);
DigitalOut r(LED_RED);
DigitalOut b(LED_BLUE);
InterruptIn reed_switch_interrupt(PIN_REED_SWITCH);

static uint8_t const LED_OFF = 1;
static uint8_t const LED_ON = 0;

static void debug_serial_init()
{
    debugSerialPort.baud(115200);
}

static void reed_switch_rising()
{
    g.write(LED_ON);
    dbg.writeln("Reed Switch Rising Edge");
}

static void reed_switch_falling()
{
    g.write(LED_OFF);
    dbg.writeln("Reed Switch Falling Edge");
}

int main()
{
    debug_serial_init();
    reed_switch_interrupt.rise(&reed_switch_rising);
    reed_switch_interrupt.fall(&reed_switch_falling);
    g.write(LED_OFF);
    r.write(LED_OFF);
    b.write(LED_OFF);
    while (true) {
        wait_ms(50);
    }
}
