#ifndef DAQ_H
#define DAQ_H

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

class DAQ {
private:
    std::fstream daqStream;

    std::string portName_;

    uint8_t openPort();
    void sendCommand(const std::string& cmd);
    std::string readResponse();

public:
     DAQ(const std::string& portName);
    ~DAQ();

    int isOpen();

    float Read(const uint8_t& channel);
};

#endif
