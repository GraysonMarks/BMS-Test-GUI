#include "../inc/RelayController.h"
#include <iostream>

RelayController::RelayController(const std::string& portName) {
    portName_ = portName;
    
    if (openPort() != 0) {
        std::cerr << "RelayController: failed to open port\n";
    }
}

RelayController::~RelayController() {
    Serial.Close();
}

uint8_t RelayController::openPort() {
    try {
        Serial.Open(portName_);
        Serial.SetBaudRate(LibSerial::BaudRate::BAUD_9600);
        Serial.SetCharacterSize(LibSerial::CharacterSize::CHAR_SIZE_8);
        Serial.SetStopBits(LibSerial::StopBits::STOP_BITS_1);
        Serial.SetParity(LibSerial::Parity::PARITY_NONE);
        Serial.SetFlowControl(LibSerial::FlowControl::FLOW_CONTROL_NONE);
    }
    catch (...) {
        return 1;
    }
    return 0;
}

int RelayController::isOpen() {
    if (Serial.IsOpen()) {
        std::cout << "Relay is open!" << std::endl;
        return 0;
    }

    return 1;
}

void RelayController::sendCommand(const std::string& cmd) {
    Serial.Write(cmd + "\r");
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

void RelayController::Open(uint8_t& relay) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << int(relay);
    sendCommand("relay off " + ss.str());
}

void RelayController::Close(uint8_t& relay) {
    std::stringstream ss;
    ss << std::hex << std::uppercase << int(relay);
    sendCommand("relay on "  + ss.str());
}
