#include "../inc/MainWindow.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QDir>
#include <QtSerialPort/QSerialPortInfo>
#include <QHeaderView>

MainWindow::MainWindow(QWidget* parent) {
    parent = new QMainWindow();
    tester_ = new BMSTest(this);
    countdownTimer_ = new QTimer(this);

    setupUi();
    populatePorts();

    // Connect clicks
    connect(relayConnectBtn_, &QPushButton::clicked, this, &MainWindow::onRelayConnectClicked);
    connect(dacConnectBtn_,   &QPushButton::clicked, this, &MainWindow::onDacConnectClicked);
    connect(thresholdSpin_, QOverload<double>::of(&QDoubleSpinBox::valueChanged), tester_, &BMSTest::setThreshold);
    connect(btnStart_,        &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(btnStop_,         &QPushButton::clicked, this, &MainWindow::onStopClicked);
    connect(table_, &QTableWidget::itemClicked, this,    &MainWindow::onTableStateClicked);

    // Test updates
    connect(tester_, &BMSTest::relayConnected, this, &MainWindow::handleRelayConnect);
    connect(tester_, &BMSTest::daqConnected, this, &MainWindow::handleDAQConnect);
    connect(tester_, &BMSTest::relayStatusUpdated, this,  &MainWindow::handleRelayUpdate);
    connect(tester_, &BMSTest::logMessage, this,  &MainWindow::handleLog);
    connect(tester_, &BMSTest::timeRemaining, this,  &MainWindow::handleTimeRemaining);
    connect(tester_, &BMSTest::testFinished, this,  &MainWindow::handleFinished);

    // Countdown timer setup
    countdownTimer_->setInterval(1000); 
    connect(countdownTimer_, &QTimer::timeout, this, &MainWindow::updateCountdown); 
}

MainWindow::~MainWindow() {
    tester_->stopTest();
}

void MainWindow::setupUi() {
    auto* cw = new QWidget(this);
    auto* mainLay = new QHBoxLayout(cw);

    // Left column: controls + log
    auto* leftLay = new QVBoxLayout;
    auto* ctrlLay = new QGridLayout;

    // Relay row
    ctrlLay->addWidget(new QLabel("Relay COM:"), 0, 0);
    comboRelayPort_ = new QComboBox;
    comboRelayPort_->setEditable(true);
    ctrlLay->addWidget(comboRelayPort_, 0, 1);
    relayConnectBtn_ = new QPushButton("Connect");
    relayConnectBtn_->setMinimumSize(new QSize());
    ctrlLay->addWidget(relayConnectBtn_, 0, 2);
    relayStatusLabel_ = new QLabel("Not connected");
    ctrlLay->addWidget(relayStatusLabel_, 0, 3);

    // DAQ row
    ctrlLay->addWidget(new QLabel("DAQ COM:"), 1, 0);
    comboDacPort_ = new QComboBox;
    comboDacPort_->setEditable(true);
    ctrlLay->addWidget(comboDacPort_, 1, 1);
    dacConnectBtn_ = new QPushButton("Connect");
    ctrlLay->addWidget(dacConnectBtn_, 1, 2);
    dacStatusLabel_ = new QLabel("Not connected");
    ctrlLay->addWidget(dacStatusLabel_, 1, 3);

    // Set Threshold voltage
    ctrlLay->addWidget(new QLabel("Threshold Voltage:"), 2, 0);
    thresholdSpin_ = new QDoubleSpinBox;
    thresholdSpin_->setRange(0.0, 100.0);
    thresholdSpin_->setSingleStep(0.1);
    thresholdSpin_->setValue(40.0);
    ctrlLay->addWidget(thresholdSpin_, 2, 1);

    // Cycles + ETA
    ctrlLay->addWidget(new QLabel("Number of Cycles:"), 3, 0);
    cyclesSpin_ = new QSpinBox;
    cyclesSpin_->setRange(1, 1'000'000);
    cyclesSpin_->setValue(100);
    ctrlLay->addWidget(cyclesSpin_, 3, 1);

    timeLabel_ = new QLabel("ETA: --:--");
    ctrlLay->addWidget(timeLabel_, 3, 2, 1, 2);

    // Start/Stop
    btnStart_ = new QPushButton("Start Test");
    ctrlLay->addWidget(btnStart_, 4, 0, 1, 2);
    btnStop_ = new QPushButton("Stop Test");
    btnStop_->setEnabled(false);
    ctrlLay->addWidget(btnStop_, 4, 2, 1, 2);

    leftLay->addLayout(ctrlLay);

    logBox_ = new QTextEdit;
    logBox_->setReadOnly(true);
    leftLay->addWidget(logBox_);

    mainLay->addLayout(leftLay, 2);

    // ── Right column: status table ─────────────────────────
    table_ = new QTableWidget(kNumRelays, 4, this);
    table_->setHorizontalHeaderLabels({"State","Relay","Alive","Cycles"});
    table_->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table_->verticalHeader()->setVisible(false);
    table_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    table_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    for (int i = 0; i < kNumRelays; ++i) {
        // Enabled text
        auto* en = new QTableWidgetItem("Enabled");
        en->setTextAlignment(Qt::AlignCenter);
        en->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        table_->setItem(i, 0, en);

        // Relay ID (centered)
        auto* idItem = new QTableWidgetItem(QString::number(i));
        idItem->setFlags(idItem->flags() & ~Qt::ItemIsEditable);
        idItem->setTextAlignment(Qt::AlignCenter);
        table_->setItem(i, 1, idItem);

        // Alive (centered)
        auto* alive = new QTableWidgetItem("—");
        alive->setTextAlignment(Qt::AlignCenter);
        table_->setItem(i, 2, alive);

        // Cycles (centered)
        auto* cycles = new QTableWidgetItem("0");
        cycles->setTextAlignment(Qt::AlignCenter);
        table_->setItem(i, 3, cycles);
    }

    mainLay->addWidget(table_, 2);

    setCentralWidget(cw);
    resize(950, 520);
}

void MainWindow::populatePorts() {
    comboRelayPort_->clear();
    comboDacPort_->clear();
    
    QDir devDirDAQs("/dev");
    QDir devDirRelays("/dev");
    QStringList daqs = devDirDAQs.entryList({"usbtmc*"}, QDir::System | QDir::Readable);
    QStringList relays = devDirRelays.entryList({"ttyACM*"}, QDir::System | QDir::Readable);

    for (const QString& d : daqs) {
        comboDacPort_->addItem("/dev/" + d);
    }

    for (const QString& r : relays) {
        comboRelayPort_->addItem("/dev/" + r);
    }
    
    if (comboDacPort_->count() == 0) {
        comboDacPort_->addItem("/dev/usbtmc0");
    }

    if (comboRelayPort_->count() == 0) {
        comboRelayPort_->addItem("/dev/ttyACM0");
    }
}

void MainWindow::onRelayConnectClicked() {
    const QString port = comboRelayPort_->currentText();
    std::cout << "Relay port: " + port.toStdString() << std::endl;
    tester_->setRelayPort(port);
    relayStatusLabel_->setText(relayConnected_ ? "Failed" : "Connected");

    if (relayStatusLabel_->text() == "Connected") {
        comboRelayPort_->setEnabled(false);
        relayConnectBtn_->setEnabled(false);
    }
}

void MainWindow::onDacConnectClicked() {
    const QString port = comboDacPort_->currentText();
    std::cout << "DAQ port: " + port.toStdString() << std::endl;
    tester_->setDacPort(port);
    dacStatusLabel_->setText(daqConnected_ ? "Failed" : "Connected");

    if (dacStatusLabel_->text() == "Connected") {
        comboDacPort_->setEnabled(false);
        dacConnectBtn_->setEnabled(false);
    }
}

void MainWindow::onStartClicked() {
    // Gather enabled relays
    QVector<int> enabled;
    for (int i = 0; i < kNumRelays; ++i) {
        if (table_->item(i, 0)->text() == "Enabled")
            enabled.append(i);
    }

    tester_->setEnabledRelays(enabled);
    tester_->setThreshold(40.0);
    tester_->setTargetCycles(cyclesSpin_->value());

    // initialize ETA = cycles × enabled.size()
    etaSeconds_ = cyclesSpin_->value() * enabled.size();
    int m = etaSeconds_ / 60, s = etaSeconds_ % 60;
    timeLabel_->setText(
        QString("ETA: %1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'))
    );
    countdownTimer_->start();

    btnStart_->setEnabled(false);
    btnStop_ ->setEnabled(true);
    thresholdSpin_->setEnabled(false);
    cyclesSpin_->setEnabled(false);

    // reset Alive & Cycles columns
    for (int i = 0; i < kNumRelays; ++i) {
        table_->item(i,2)->setText("—");
        table_->item(i,3)->setText("0");
    }

    // Use startTest() so BMSTest::run() sees your setup
    tester_->startTest();
}

void MainWindow::onStopClicked() {
    tester_->stopTest();
    countdownTimer_->stop();
    btnStart_->setEnabled(true);
    btnStop_ ->setEnabled(false);
    cyclesSpin_->setEnabled(true);
    timeLabel_->setText("ETA: --:--");
}

void MainWindow::onTableStateClicked(QTableWidgetItem* item) {
    if (item->column() != 0) return;
    int row = item->row();
    bool wasEnabled = (item->text() == "Enabled");
    item->setText(wasEnabled ? "Disabled" : "Enabled");

    // immediately refresh enabled list
    QVector<int> enabled;
    for (int i = 0; i < kNumRelays; ++i) {
        if (table_->item(i,0)->text() == "Enabled") {
            enabled.append(i);
        }
    }

    tester_->setEnabledRelays(enabled);
}

void MainWindow::handleRelayConnect(bool state) {
    relayConnected_ = state;
}

void MainWindow::handleDAQConnect(bool state) {
    daqConnected_= state;
}

void MainWindow::handleRelayUpdate(int id, bool alive, int count) {
    table_->item(id, 2)->setText(alive ? "Alive" : "Dead");
    table_->item(id, 3)->setText(QString::number(count));
}

void MainWindow::handleLog(const QString& msg) {
    logBox_->append(msg);
}

void MainWindow::handleFinished(bool allDead) {
    logBox_->append("Test finished");
    countdownTimer_->stop();
    btnStart_->setEnabled(true);
    btnStop_ ->setEnabled(false);
    cyclesSpin_->setEnabled(true);
    timeLabel_->setText("ETA: --:--");
}

void MainWindow::handleCyclesRemaining(int rem) {
    cyclesSpin_->setValue(rem);
}

void MainWindow::handleTimeRemaining(int seconds) {
    int m = seconds / 60;
    int s = seconds % 60;
    timeLabel_->setText(
        QString("ETA: %1:%2")
            .arg(m, 2, 10, QChar('0'))
            .arg(s, 2, 10, QChar('0'))
    );
}

void MainWindow::updateCountdown() {
    --etaSeconds_;
    
    if (etaSeconds_ <= 0) {
        countdownTimer_->stop();
        timeLabel_->setText("ETA: 00:00");
        return;
    }

    int m = etaSeconds_ / 60, s=etaSeconds_ % 60;
    timeLabel_->setText(QString("ETA: %1:%2").arg(m, 2, 10, QChar('0')).arg(s, 2, 10, QChar('0')));
}