#include "mainwindow.h"
#include "serialport.h"
#include "parser.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    SerialPort serial = SerialPort();
    serial.readPort(); //figure out how to make sure its connected/open
    QByteArrray canId = serial.getCanId(); //get CAN ID
    char* data = serial.getDataAddress(); //Gets the address of the char array of message

    //time to parse
    if (canId == 0x200)
        Throttle currObject = Throttle();
    else if (canId == 0x201)
        Brake currObject = Brake();
    else if (canId == 0x188)
        Pack currObject = Pack();
    else if (canId == 0x388)
        Voltage currObject = Voltage();
    else if (canId == 0x488)
        Temperature currObject = Temperature();
    else if (canId == 0x288)
        CurrentRead currObject = CurrentRead();
    else if (canId == 0x626)
        DashBoard currObject = DashBoard();
    else if (canId == 0x466)
        CurtisDebug currObject = CurtisDebug();
    else if (canId == 0x566)
        CurtisStatus currObject = CurtisStatus();
    else if (canId == 0x666)
        CurtisRecvAcknowledge currObject = CurtisRecvAcknowledge();
    else if (canId == 0x766)
        CurtisRecv currObject = CurtisRecv();
    else if (canId == 0x223)
        DLHeartbeat currObject = DLHeartbeat();
    else if (canId == 0x123)
        DLTime currObject = DLTime();
    else if (canId == 0x247)
        SensorStatus currObject = SensorStatus();
    else
        std::cout << "Error: No matching CAN ID" << std::endl;


    currObject.parse(&data); // parse the message based on the id

    return a.exec();
}
