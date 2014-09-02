/*
 * led.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: posborne
 */

#include "led.h"

MulticolorLED::MulticolorLED(PinName redPinName, PinName greenPinName, PinName bluePinName) :
    m_red(redPinName),
    m_green(greenPinName),
    m_blue(bluePinName)
{}

void MulticolorLED::show(float red, float green, float blue)
{
    // the PwmOut API uses floating point.  This allows us
    m_red = 1.0 - red;
    m_green = 1.0 - green;
    m_blue = 1.0 - blue;
}
