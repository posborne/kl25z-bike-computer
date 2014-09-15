/*
 * wheel.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: posborne
 */

#include <functional>
#include "wheel.h"

static DigitalOut tpin(PTD4);


BicycleWheel::BicycleWheel(PinName reedSwitchPin, DebugSerialPort& debugSerialPort, MulticolorLED& debugLED) :
    m_reedSwitchPin(reedSwitchPin),
    m_reedSwitchGPIO(m_reedSwitchPin),
    m_reedSwitchInterrupt(m_reedSwitchPin),
    m_debugSerialPort(debugSerialPort),
    m_led(debugLED)
{
}

BicycleWheel::~BicycleWheel()
{
}

void BicycleWheel::init()
{
    m_led.show(0.0, 0.0, 0.0);
    m_reedSwitchInterrupt.rise(this, &BicycleWheel::onRisingInterrupt);
    m_reedSwitchInterrupt.fall(this, &BicycleWheel::onFallingInterrupt);
}

void BicycleWheel::onFallingInterrupt()
{
    tpin = 0;
    m_debugSerialPort.writeln("Reed Switch Rising Edge");
    m_led.show(0, 0, 0.05); // subtle blue
}

void BicycleWheel::onRisingInterrupt()
{
    tpin = 1;
    m_debugSerialPort.writeln("Reed Switch Falling Edge");
    m_led.show(0.01, 0.05, 0.0); // subtle yellow
}
