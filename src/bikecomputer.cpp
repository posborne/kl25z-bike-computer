#include "mbed.h"
#include "debug.h"
#include "wheel.h"
#include "led.h"
#include "nrf8001_ble_radio.h"

/* Debug UART */
static const PinName PIN_SERIAL_RX = PTA1; // green (to TTL converter)
static const PinName PIN_SERIAL_TX = PTA2; // white (to TTL converter)
static Serial debugSerialPort(PIN_SERIAL_TX, PIN_SERIAL_RX, "debug");
static DebugSerialPort dbg(debugSerialPort);

/* Debug multicolor LED */
static MulticolorLED debugLED(LED_RED, LED_GREEN, LED_BLUE);

/* Reed Switch Input (Spinning of the Wheel) */
static const PinName PIN_REED_SWITCH_GPIO = PTD5;
static BicycleWheel bicycleWheel(PIN_REED_SWITCH_GPIO, dbg, debugLED);

/* NRF8001 Bluetooth LE Module (Adafruit Bluefruit LE) */
static const PinName PIN_NRF8001_SPI_SCK = PTD1; // yellow
static const PinName PIN_NRF8001_SPI_MOSI = PTD2; // brown
static const PinName PIN_NRF8001_SPI_MISO = PTD3; // gray
static const PinName PIN_NRF8001_GPIO_REQ = PTC9; // blue
static const PinName PIN_NRF8001_GPIO_RDY = PTC8; // white
static const PinName PIN_NRF8001_GPIO_ACT = PTA5; // purple
static const PinName PIN_NRF8001_GPIO_RST = PTA4; // orange
static NRF8001BluetoothRadio ble_radio(
        dbg,
        PIN_NRF8001_SPI_MISO,
        PIN_NRF8001_SPI_MOSI,
        PIN_NRF8001_SPI_SCK,
        PIN_NRF8001_GPIO_REQ,
        PIN_NRF8001_GPIO_RDY,
        PIN_NRF8001_GPIO_ACT,
        PIN_NRF8001_GPIO_RST);

int main()
{
    debugSerialPort.baud(115200);
    bicycleWheel.init();
    ble_radio.init();

    dbg.writeln("=== KL25Z Bike Computer ===");
    dbg.writeln("");

    while (true) {
        ble_radio.tick();
    }
}
