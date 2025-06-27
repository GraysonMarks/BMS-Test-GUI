#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>
#include <QTableWidget>
#include <QTextEdit>
#include <QSpinBox>
#include <QTimer>

#include "../inc/BMSTest.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

private:
    static constexpr int kNumRelays = 16;

    // Relay controls
    QComboBox*   comboRelayPort_;
    QPushButton* relayConnectBtn_;
    QLabel*      relayStatusLabel_;

    // DAQ controls
    QComboBox*   comboDacPort_;
    QPushButton* dacConnectBtn_;
    QLabel*      dacStatusLabel_;

    // Test controls
    QDoubleSpinBox* thresholdSpin_;
    QSpinBox*    cyclesSpin_;
    QLabel*      timeLabel_;
    QPushButton* btnStart_;
    QPushButton* btnStop_;

    // Countdown
    QTimer*      countdownTimer_;
    int          etaSeconds_  = 0;

    // Results
    QTableWidget* table_;
    QTextEdit*    logBox_;

    BMSTest*      tester_;

    bool relayConnected_;
    bool daqConnected_;

    void setupUi();
    void populatePorts();

private slots:
    void onRelayConnectClicked();
    void onDacConnectClicked();
    void onStartClicked();
    void onStopClicked();
    void onTableStateClicked(QTableWidgetItem* item);

    void handleRelayConnect(bool state);
    void handleDAQConnect(bool state);
    void handleRelayUpdate(int id, bool alive, int count);
    void handleLog(const QString& msg);
    void handleFinished(bool allDead);
    void handleCyclesRemaining(int remaining);
    void handleTimeRemaining(int seconds);

    void updateCountdown();

public:
     MainWindow(QWidget* parent = nullptr);
    ~MainWindow() override;
};

#endif // MAINWINDOW_
