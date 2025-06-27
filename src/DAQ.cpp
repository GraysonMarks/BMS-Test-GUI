#include "../inc/DAQ.h"
#include <iostream>

DAQ::DAQ(const std::string& portName) {
    portName_ = portName;
    
    std::cout << portName_ << std::endl;

    if (openPort() != 0) {
        std::cerr << "DAQ: failed to open port\n";
    }
}

DAQ::~DAQ() {
    daqStream.close();
}

uint8_t DAQ::openPort() {
    daqStream.open(portName_, std::ios::in | std::ios::out);

    if (daqStream.is_open()) {
        return 0;
    }

    return 1;
}

int DAQ::isOpen() {
    if (daqStream.is_open()) {
        std::cout << "DAQ is open!" << std::endl;
        return 0;
    }
    
    return 1;
}

void DAQ::sendCommand(const std::string& cmd) {
    daqStream << cmd << "\n";
    daqStream.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

std::string DAQ::readResponse() {
    std::string response;
    std::getline(daqStream, response);
    return response;
}

float DAQ::Read(const uint8_t& channel) {
    std::string ch = (channel < 10 ? "10" : "1") + std::to_string(channel);
    sendCommand("CONF:VOLT:DC 100,0.003,(@" + ch + ")");
    sendCommand("ROUT:CLOS (@" + ch + ")");
    sendCommand("READ?");
    std::string resp = readResponse();
    sendCommand("ROUT:OPEN (@" + ch + ")");

    try { return std::stof(resp); }
    catch (...) { return 0.0f; }
}
