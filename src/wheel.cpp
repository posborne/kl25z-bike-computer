/*
 * wheel.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: posborne
 */

#include <functional>
#include "wheel.h"

// TODO: only necessary as mbed does not allow for passing a data pointer
// along with interrupt registrations.  Obviously, this breaks if we ever
// have more than one wheel sensor created.
static BicycleWheel* g_wheel; /* global wheel reference */

/*
 * ISR called when we receive an rising edge on the reed sensor
 */
static void reedSwitchRisingInterrupt()
{
    if (g_wheel != NULL) {
        g_wheel->onRisingInterrupt();
    }
}

/*
 * ISR called when we receive an falling edge on the reed sensor
 */
static void reedSwitchFallingInterrupt()
{
    if (g_wheel != NULL) {
        g_wheel->onFallingInterrupt();
    }
}


BicycleWheel::BicycleWheel(PinName reedSwitchPin, DebugSerialPort& debugSerialPort, MulticolorLED& debugLED) :
    m_reedSwitchPin(reedSwitchPin),
    m_reedSwitchGPIO(m_reedSwitchPin),
    m_reedSwitchInterrupt(m_reedSwitchPin),
    m_debugSerialPort(debugSerialPort),
    m_led(debugLED)
{
    g_wheel = this;
}

BicycleWheel::~BicycleWheel()
{
    g_wheel = NULL;
}

void BicycleWheel::init()
{
    m_led.show(0.0, 0.0, 0.0);
    m_reedSwitchInterrupt.rise(reedSwitchRisingInterrupt);
    m_reedSwitchInterrupt.fall(reedSwitchFallingInterrupt);
}

void BicycleWheel::onFallingInterrupt()
{
    m_debugSerialPort.writeln("Reed Switch Rising Edge");
    m_led.show(0, 0, 0.05); // subtle blue
}

void BicycleWheel::onRisingInterrupt()
{
    m_debugSerialPort.writeln("Reed Switch Falling Edge");
    m_led.show(0.01, 0.05, 0.0); // subtle yellow
}
