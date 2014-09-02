/*
 * led.h
 *
 *  Created on: Sep 2, 2014
 *      Author: posborne
 */

#ifndef LED_H_
#define LED_H_

#include <cstdint>
#include "mbed.h"

class MulticolorLED
{
public:
    MulticolorLED(PinName redPinName, PinName greenPinName, PinName bluePinName);
    void show(float red, float green, float blue);

private:
    PwmOut m_red;
    PwmOut m_green;
    PwmOut m_blue;
};


#endif /* LED_H_ */
