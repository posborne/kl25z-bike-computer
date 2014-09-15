/*
 * nrf8001_ble_radio.h
 *
 *  Created on: Sep 1, 2014
 *      Author: posborne
 */

#ifndef NRF8001_BLE_RADIO_H_
#define NRF8001_BLE_RADIO_H_

#include "ble_radio.h"
#include "debug.h"
#include "mbed.h"

class NRF8001BluetoothRadio
{
public:
    NRF8001BluetoothRadio(
            DebugSerialPort& debugPort,
            PinName misoPin, PinName mosiPin, PinName sckPin, PinName reqnPin,
            PinName rdynPin, PinName actPin, PinName resetPin);
    ~NRF8001BluetoothRadio() {}
    void init(void);
    void tick(void);

private:
    DebugSerialPort& m_debugPort;
    PinName m_misoPin;
    PinName m_mosiPin;
    PinName m_sckPin;
    PinName m_reqnPin;
    PinName m_rdynPin;
    PinName m_actPin;
    PinName m_resetPin;
};

#endif /* NRF8001_BLE_RADIO_H_ */
