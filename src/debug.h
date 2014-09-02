/*
 * debug.h
 *
 *  Created on: Sep 1, 2014
 *      Author: posborne
 */

#ifndef DEBUG_H_
#define DEBUG_H_

#include "mbed.h"

class DebugSerialPort
{
public:
    DebugSerialPort(Stream& debugStream);
    int write(const char * const fmt, ...);
    int writeln(const char * const fmt, ...);

private:
    Stream& m_debugStream;
};


#endif /* DEBUG_H_ */
