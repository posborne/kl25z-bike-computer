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

class NRF8001BluetoothRadio : IBluetoothRadio
{
    NRF8001BluetoothRadio(SPI spi_port);
};

#endif /* NRF8001_BLE_RADIO_H_ */
