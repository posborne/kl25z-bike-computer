/*
 * wheel.h
 *
 *  Created on: Sep 2, 2014
 *      Author: posborne
 */

#ifndef WHEEL_H_
#define WHEEL_H_

#include "mbed.h"
#include "debug.h"
#include "led.h"

class BicycleWheel
{
public:
    BicycleWheel(PinName reedSwitchPin, DebugSerialPort& debugSerialPort, MulticolorLED& debugLED);
    ~BicycleWheel();
    void init();
    void onFallingInterrupt();
    void onRisingInterrupt();

private:
    PinName m_reedSwitchPin;
    DigitalIn m_reedSwitchGPIO;
    InterruptIn m_reedSwitchInterrupt;
    DebugSerialPort& m_debugSerialPort;
    MulticolorLED& m_led;
};

#endif /* WHEEL_H_ */
