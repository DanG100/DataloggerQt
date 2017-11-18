#include "serialport.h"
#include "parser.h"

#include <iostream>

using namespace std;

SerialPort::SerialPort()
{
    //*serial = new QSerialPort();
    //serial->setPortName("ttyUSB0");
    //serial->setParity(QSerialPort::NoParity);
    //serial->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
    //serial->setStopBits(QSerialPort::OneStop);
    //serial->setFlowControl(QSerialPort::NoFlowControl);
    //serial->open(QIODevice::ReadOnly);
}

SerialPort::~SerialPort(){}

void SerialPort::readPort()
{
    //this->serial->readLine(data, 14); //reads port until 14 chunks of 8 bits read, or newlines
}

int SerialPort::getCanId(char* fakeData)//for testing rn
{
    //int canId = data[0] + data[1];
    int canId = fakeData[0] + fakeData[1];
    return canId;
}

/*char* SerialPort::getDataAddress()
{
    return &data;
}*/

Parser* SerialPort::getParsedObject(char* str)
{
    Parser* currObject = new Parser;
    readPort();
    int canId = getCanId(str);
    //time to parse
    if (canId == 0x200)
        currObject = new Throttle();
    else if (canId == 0x201)
        currObject = new Brake();
    else if (canId == 0x188)
        currObject = new Pack();
    else if (canId == 0x388)
        currObject = new Voltage();
    else if (canId == 0x488)
        currObject = new Temperature();
    else if (canId == 0x288)
        currObject = new CurrentRead();
    else if (canId == 0x626)
        currObject = new DashBoard();
    else if (canId == 0x466)
        currObject = new CurtisDebug();
    else if (canId == 0x566)
        currObject = new CurtisStatus();
    else if (canId == 0x666)
        currObject = new CurtisRecvAcknowledge();
    else if (canId == 0x766)
        currObject = new CurtisRecv();
    else if (canId == 0x223)
        currObject = new DLHeartbeat();
    else if (canId == 0x123)
        currObject = new DLTime();
    else if (canId == 0x247)
        currObject = new SensorStatus();
    else
        cout << "Error: No matching CAN ID" << endl;


    currObject->parse(str); // parse the message based on the id
    return currObject;
}

void SerialPort::readDataFromPort()
{
    char data[15];
    int bytesRead = this->serial->readLine(data,PACKET_LEN+1);
    if(bytesRead == PACKET_LEN);
    {
        Parser* msg = getParsedObject(data);
        emit receivedPacket(msg);
    }
    else
    {
        //handle imcomplete packets
    }

}
