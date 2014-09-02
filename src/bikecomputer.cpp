#include "mbed.h"
#include "debug.h"

/* Reed Switch Input (Spinning of the Wheel) */
static const PinName PIN_REED_SWITCH_GPIO = PTD5;
InterruptIn reed_switch_interrupt(PIN_REED_SWITCH_GPIO);

/* NRF8001 Bluetooth LE Module (Adafruit Bluefruit LE) */
static const PinName PIN_NRF8001_SPI_SCK = PTD1; // yellow
static const PinName PIN_NRF8001_SPI_MOSI = PTD2; // brown
static const PinName PIN_NRF8001_SPI_MISO = PTD3; // gray
static const PinName PIN_NRF8001_GPIO_REQ = PTC9; // blue
static const PinName PIN_NRF8001_GPIO_RDY = PTC8; // white
static const PinName PIN_NRF8001_GPIO_ACT = PTA5; // purple
static const PinName PIN_NRF8001_GPIO_RST = PTA4; // orange
static const DigitalInOut nrf8001_gpio_req(PIN_NRF8001_GPIO_REQ);
static const DigitalInOut nrf8001_gpio_rdy(PIN_NRF8001_GPIO_RDY);
static const DigitalInOut nrf8001_gpio_act(PIN_NRF8001_GPIO_ACT);
static const DigitalInOut nrf8001_gpio_rst(PIN_NRF8001_GPIO_RST);

/* Debug UART */
static const PinName PIN_SERIAL_RX = PTA1; // green (to TTL converter)
static const PinName PIN_SERIAL_TX = PTA2; // white (to TTL converter)
static Serial debugSerialPort(PIN_SERIAL_TX, PIN_SERIAL_RX, "debug");
static DebugSerialPort dbg(debugSerialPort);

/* FRDM board LED */
DigitalOut frdm_led_green_channel(LED_GREEN);
DigitalOut frdm_led_red_channel(LED_RED);
DigitalOut frdm_led_blue_channel(LED_BLUE);
static uint8_t const LED_OFF = 1;
static uint8_t const LED_ON = 0;


static void debug_serial_init()
{
    debugSerialPort.baud(115200);
}

static void reed_switch_rising()
{
    frdm_led_green_channel.write(LED_ON);
    dbg.writeln("Reed Switch Rising Edge");
}

static void reed_switch_falling()
{
    frdm_led_green_channel.write(LED_OFF);
    dbg.writeln("Reed Switch Falling Edge");
}

int main()
{
    debug_serial_init();
    reed_switch_interrupt.rise(&reed_switch_rising);
    reed_switch_interrupt.fall(&reed_switch_falling);
    frdm_led_green_channel.write(LED_OFF);
    frdm_led_red_channel.write(LED_OFF);
    frdm_led_blue_channel.write(LED_OFF);
    while (true) {
        wait_ms(50);
    }
}
