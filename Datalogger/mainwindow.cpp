#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    graphInputHandler = new GraphInputHandler(ui->temperatureVoltage, ui->temperatureBmsThrottlingOut, nullptr);
    testInput = new TestInput();
    //connect(testInput, SIGNAL(giveCanMsg(CANMessage*)), graphInputHandler, SLOT(recieveCanMsg(CANMessage*)));
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)), graphInputHandler,SLOT(recieveCanMsg(CANMessage*)));
    connect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
    connect(this,SIGNAL(startLogger()),&logger,SLOT(startFile()));
    connect(this,SIGNAL(stopLogger()),&logger,SLOT(endFile()));


    ui->tableWidget->setRowCount(14);
    ui->tableWidget->setColumnCount(1);
    QStringList tableColumnHeader;
    QStringList tableRowHeader;
    tableColumnHeader << "Value";
    tableRowHeader << "Brake" << "Throttle" << "Temp. SP 1" << "Temp. SP 2" << "Temp. SP 3" << "Temp. SP 4"
                   << "Temp. SP 5" << "Temp. SP 6" << "Current" << "Pack Voltage (mv)" << "Pack Min" << "Pack Max" <<  "Car State" << "BMS Error Flags";

    ui->tableWidget->setHorizontalHeaderLabels(tableColumnHeader);
    ui->tableWidget->setVerticalHeaderLabels(tableRowHeader);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers); //Disables user from editing table values

    emit startLogger();
}

MainWindow::~MainWindow()
{
    emit stopLogger();
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)), graphInputHandler,SLOT(recieveCanMsg(CANMessage*)));
    disconnect(&serialPort,SIGNAL(receivedPacket(CANMessage*)),&logger,SLOT(receiveCanMsg(CANMessage*)));
    delete graphInputHandler;
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
