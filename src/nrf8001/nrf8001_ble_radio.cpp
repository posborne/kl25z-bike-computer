#include "nrf8001_ble_radio.h"
#include "lib_aci.h"
#include "boards.h"

static hal_aci_evt_t aci_data;
static aci_state_t aci_state;

NRF8001BluetoothRadio::NRF8001BluetoothRadio(
        DebugSerialPort& debugPort,
        PinName misoPin, PinName mosiPin, PinName sckPin, PinName reqnPin,
        PinName rdynPin, PinName actPin, PinName resetPin) :
    m_debugPort(debugPort),
    m_misoPin(misoPin),
    m_mosiPin(mosiPin),
    m_sckPin(sckPin),
    m_reqnPin(reqnPin),
    m_rdynPin(rdynPin),
    m_actPin(actPin),
    m_resetPin(resetPin)
{
}

void NRF8001BluetoothRadio::init()
{

    aci_state.aci_setup_info.services_pipe_type_mapping = NULL;
    aci_state.aci_setup_info.number_of_pipes = 0;
    aci_state.aci_setup_info.setup_msgs = NULL;
    aci_state.aci_setup_info.num_setup_msgs = 0;

    aci_state.aci_pins.board_name = BOARD_DEFAULT; //See board.h for details
    aci_state.aci_pins.reqn_pin = m_reqnPin;
    aci_state.aci_pins.rdyn_pin = m_rdynPin;
    aci_state.aci_pins.mosi_pin = m_mosiPin;
    aci_state.aci_pins.miso_pin = m_misoPin;
    aci_state.aci_pins.sck_pin = m_sckPin;
    aci_state.aci_pins.active_pin = m_actPin;
    aci_state.aci_pins.reset_pin = m_resetPin;

    aci_state.aci_pins.interface_is_interrupt = true;
    aci_state.aci_pins.interrupt_number = 1; // not actually used in our HAL

    lib_aci_init(&aci_state, true);
}

void NRF8001BluetoothRadio::tick()
{
    bool setup_required = false;

    if (lib_aci_event_get(&aci_state, &aci_data))
    {
        aci_evt_t* aci_evt;
        aci_evt = &aci_data.evt;
        switch (aci_evt->evt_opcode)
        {
        case ACI_EVT_DEVICE_STARTED: // received on device start
            switch (aci_evt->params.device_started.device_mode)
            {
            case ACI_DEVICE_SETUP:
                setup_required = true;
                break;

            case ACI_DEVICE_STANDBY:
                if (aci_evt->params.device_started.hw_error)
                    wait_ms(20);
                else
                    lib_aci_connect(0, 0x0050);
                break;
            }
            break;

        case ACI_EVT_CMD_RSP:
            if (ACI_STATUS_SUCCESS != aci_evt->params.cmd_rsp.cmd_status) {

            }
        }
    }
}
