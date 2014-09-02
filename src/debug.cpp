/*
 * debug.cpp
 *
 *  Created on: Sep 1, 2014
 *      Author: posborne
 */

#include <stdarg.h>
#include <stdio.h>
#include "debug.h"


DebugSerialPort::DebugSerialPort(Stream& debugStream) :
    m_debugStream(debugStream)
{
}

int DebugSerialPort::write(const char * const fmt, ...)
{
    char buffer[256];
    int bytesWritten;
    va_list args;
    va_start(args, fmt);
    bytesWritten = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    m_debugStream.puts(buffer);
    return bytesWritten;
}

int DebugSerialPort::writeln(const char * const fmt, ...)
{
    char buffer[256];
    int bytesWritten;
    va_list args;
    va_start(args, fmt);
    bytesWritten = vsnprintf(buffer, sizeof(buffer), fmt, args);
    va_end(args);
    strncat(buffer, "\r\n", 2);
    m_debugStream.puts(buffer);
    return bytesWritten + 2;
}
