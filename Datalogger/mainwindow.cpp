#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),ui->chart1,SLOT(receiveCanMsg(CANMessage*)));
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
}

MainWindow::~MainWindow()
{
    delete ui;
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),ui->chart1,SLOT(receiveCanMsg(CANMessage*)));
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
