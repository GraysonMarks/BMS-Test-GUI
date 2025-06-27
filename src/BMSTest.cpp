#include "../inc/BMSTest.h"
#include <QCoreApplication>
#include <QElapsedTimer> 

BMSTest::BMSTest(QObject* parent) {
    parent = new QObject();
}

BMSTest::~BMSTest() {
    stopTest();
    wait();
}

void BMSTest::setRelayPort(const QString& portName) {
    relayPortName_ = portName;
    relayReady_ = !portName.isEmpty();
    relays_ = new RelayController(relayPortName_.toStdString());

    emit relayConnected(relays_->isOpen());
}

void BMSTest::setDacPort(const QString& portName) {
    dacPortName_ = portName;
    dacReady_ = !portName.isEmpty();
    daq_ = new DAQ(dacPortName_.toStdString());

    emit daqConnected(daq_->isOpen());
}

void BMSTest::setEnabledRelays(const QVector<int>& relays) {
    enabledRelays_ = relays;
}

void BMSTest::setNumRelays(int n) {
    numRelays_ = n;
}

void BMSTest::setTargetCycles(int cycles) {
    targetCycles_ = cycles;
}

void BMSTest::setThreshold(double volts) {
    threshold_ = volts;
}

void BMSTest::startTest() {
    if (!isRunning()) {
        running_      = true;
        cycleCounts_  = QVector<int>(enabledRelays_.size(), 0);
        dead_         = QVector<bool>(enabledRelays_.size(), false);
        start();
    }
}

void BMSTest::stopTest() {
    running_ = false;
}

void BMSTest::run() {
    emit logMessage(QString("Test started: %1 cycles").arg(targetCycles_));
    QElapsedTimer timer;
    timer.start(); 
    
    int completedGlobal = 0;
    bool allDead = false;

    while (running_ && !allDead && completedGlobal < targetCycles_) {
        allDead = true;
        ++completedGlobal;

        int remaining = qMax(0, targetCycles_ - completedGlobal);
        emit cyclesRemaining(remaining);

        qint64 elapsedMs = timer.elapsed(); 
        double avgCycleMs = double(elapsedMs) / completedGlobal;
        int etaSec = int((avgCycleMs * remaining) / 1000.0);
        emit timeRemaining(etaSec);  

        for (int idx = 0; idx < enabledRelays_.size(); ++idx) {
            int relayId = enabledRelays_.at(idx);
            if (dead_.at(idx)) continue;
            allDead = false;

            if (relayReady_) {
                relays_->Close(*(uint8_t*)&relayId);
            }
            msleep(500);

            float v;

            if (dacReady_) {
                v = daq_->Read(relayId + 1);
            }

            if (relayReady_) {
                relays_->Open(*(uint8_t*)&relayId);
            }
            msleep(500);

            ++cycleCounts_[idx];
            bool alive = true;
            if (v < threshold_ && v != 0.0f) {
                dead_[idx] = true;
                alive    = false;
                emit logMessage(
                    QString("Relay %1 died at V=%2").arg(relayId).arg(v)
                );
            } else {
                emit logMessage(
                    QString("Relay %1 OK at V=%2").arg(relayId).arg(v)
                );
            }

            emit relayStatusUpdated(relayId, alive, cycleCounts_[idx]);

            QCoreApplication::processEvents();
            if (!running_) break;
        }
    }

    if (completedGlobal >= targetCycles_) {
        emit logMessage("Target cycle count reached");
    }

    emit logMessage("Test finished");
    emit testFinished(allDead);
}
