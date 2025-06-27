#ifndef RELAYCONTROLLER_H
#define RELAYCONTROLLER_H

#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

#include <libserial/SerialPort.h>

class RelayController {
private:
    LibSerial::SerialPort Serial;

    std::string portName_;

    uint8_t openPort();
    void sendCommand(const std::string& cmd);

public:
     RelayController(const std::string& portName);
    ~RelayController();

    int isOpen();

    void Open(uint8_t& relay);
    void Close(uint8_t& relay);
};

#endif