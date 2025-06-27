#ifndef BMSTEST_H
#define BMSTEST_H

#include <QThread>
#include <QObject>
#include <QVector>
#include <QString>
#include <atomic>

#include "../inc/RelayController.h"
#include "../inc/DAQ.h"

class BMSTest : public QThread {
    Q_OBJECT

private:
    RelayController* relays_ = nullptr;
    DAQ* daq_ = nullptr;
    QVector<int> enabledRelays_;
    int numRelays_ = 0;
    double threshold_ = 0.0;
    int targetCycles_ = 0;
    std::atomic<bool> running_{false};

    QVector<int> cycleCounts_;
    QVector<bool> dead_;
    
    QString relayPortName_;
    QString dacPortName_;
    bool relayReady_ = false;
    bool dacReady_   = false;
    
signals:
    void relayConnected(bool state);
    void daqConnected(bool state);

    void relayStatusUpdated(int id, bool alive, int cycleCount);
    void logMessage(const QString& msg);
    void cyclesRemaining(int remaining); 
    void testFinished(bool allDead);
    void timeRemaining(int seconds);
    
protected:
    void run() override;
    
public:
     BMSTest(QObject* parent = nullptr);
    ~BMSTest() override;

    Q_INVOKABLE void setRelayPort(const QString& portName);
    Q_INVOKABLE void setDacPort(const QString& portName);
    Q_INVOKABLE void setEnabledRelays(const QVector<int>& relays);
    Q_INVOKABLE void setNumRelays(int n);
    Q_INVOKABLE void setTargetCycles(int cycles);
    Q_INVOKABLE void setThreshold(double volts);

    Q_INVOKABLE void startTest();
    Q_INVOKABLE void stopTest();
};

#endif
