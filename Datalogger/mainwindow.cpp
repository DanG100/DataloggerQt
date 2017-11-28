#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),ui->widget,SLOT(receiveCanMsg(CANMessage*)));
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
}

MainWindow::~MainWindow()
{
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),ui->widget,SLOT(receiveCanMsg(CANMessage*)));
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
