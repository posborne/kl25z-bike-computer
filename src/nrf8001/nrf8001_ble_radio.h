/*
 * nrf8001_ble_radio.h
 *
 *  Created on: Sep 1, 2014
 *      Author: posborne
 */

#ifndef NRF8001_BLE_RADIO_H_
#define NRF8001_BLE_RADIO_H_

#include "ble_radio.h"
#include "mbed.h"

class NRF8001BluetoothRadio : public IBluetoothRadio
{
public:
    NRF8001BluetoothRadio(PinName misoPin, PinName mosiPin, PinName sckPin, PinName reqnPin, PinName rdynPin, PinName actPin, PinName resetPin);
    void init();

private:
    PinName m_misoPin;
    PinName m_mosiPin;
    PinName m_sckPin;
    PinName m_reqnPin;
    PinName m_rdynPin;
    PinName m_actPin;
    PinName m_resetPin;
};

#endif /* NRF8001_BLE_RADIO_H_ */
