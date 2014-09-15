#include "nrf8001_ble_radio.h"
#include "lib_aci.h"
#include "boards.h"

NRF8001BluetoothRadio::NRF8001BluetoothRadio(
        PinName misoPin, PinName mosiPin, PinName sckPin, PinName reqnPin,
        PinName rdynPin, PinName actPin, PinName resetPin) :
    m_misoPin(misoPin),
    m_mosiPin(mosiPin),
    m_sckPin(sckPin),
    m_reqnPin(reqnPin),
    m_rdynPin(rdynPin),
    m_actPin(actPin),
    m_resetPin(resetPin)
{}

void NRF8001BluetoothRadio::init()
{
    aci_state_t aci_state;

    if (NULL != services_pipe_type_mapping)
    {
      aci_state.aci_setup_info.services_pipe_type_mapping = &services_pipe_type_mapping[0];
    }
    else
    {
      aci_state.aci_setup_info.services_pipe_type_mapping = NULL;
    }
    aci_state.aci_setup_info.number_of_pipes    = NUMBER_OF_PIPES;
    aci_state.aci_setup_info.setup_msgs         = setup_msgs;
    aci_state.aci_setup_info.num_setup_msgs     = NB_SETUP_MESSAGES;

    aci_state.aci_pins.board_name = BOARD_DEFAULT; //See board.h for details
    aci_state.aci_pins.reqn_pin   = m_reqnPin;
    aci_state.aci_pins.rdyn_pin   = m_rdynPin;
    aci_state.aci_pins.mosi_pin   = m_mosiPin;
    aci_state.aci_pins.miso_pin   = m_misoPin;
    aci_state.aci_pins.sck_pin    = m_sckPin;
    aci_state.aci_pins.active_pin = m_actPin;
    aci_state.aci_pins.reset_pin  = m_resetPin;

    aci_state.aci_pins.interface_is_interrupt = true;
    aci_state.aci_pins.interrupt_number = 1; // not actually used in our HAL

    lib_aci_init(&aci_state, true);
}
