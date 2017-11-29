#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphInputHander = new GraphInputHandler(ui->temperatureVoltage, ui->temperatureBmsThrottlingOut, nullptr);
    testInput = new TestInput();
    connect(testInput, SIGNAL(giveCanMsg(CANMessage*)), graphInputHander, SLOT(recieveCanMsg(CANMessage*)));
    //connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)), graphInputHander,SLOT(recieveCanMsg(CANMessage*)));
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
}

MainWindow::~MainWindow()
{
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)), graphInputHander,SLOT(recieveCanMsg(CANMessage*)));
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
    delete graphInputHander;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
