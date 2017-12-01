#include "serialport.h"
#include "canmessage.h"

#include <iostream>

using namespace std;

SerialPort::SerialPort()
{
    setupSerialPort();
    connect(serial,SIGNAL(readyRead()),this,SLOT(readDataFromPort()));
}

SerialPort::~SerialPort(){
    disconnect(serial,SIGNAL(readyRead()),this,SLOT(readDataFromPort()));
}

int SerialPort::getCanId(char* data)//for testing rn
{
    int canId = (data[0] << 8) + data[1];
    return canId;
}

CANMessage* SerialPort::getParsedObject(char* data)
{
    CANMessage* currObject = new CANMessage;
    int canId = getCanId(data);
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
        cout << "Error: No matching CAN ID" << canId << endl;


    currObject->parse(data); // parse the message based on the id
    return currObject;
}
void SerialPort::readDataFromPort()
{
    if(!serial->canReadLine() || serial->bytesAvailable() < PACKET_LEN)
        return;
    QByteArray packet;
    bool validEnd = false;
    char c;
    while(!validEnd && serial->read(&c,1))
    {
        if(c == '\n' && packet.at(packet.size()-1)==(char)0xFF)
        {
            validEnd = true;
        }
        packet.append(c);
    }

    if(packet.size() == PACKET_LEN)
    {
        //cout << "valid packet" << endl;

        CANMessage* msg = getParsedObject(packet.data());
        emit receivedPacket(msg);
    }
    else
    {
        //handle imcomplete packets
        cout << "invalid packet " << endl;
    }

}
int SerialPort::setupSerialPort()
{
    serial = new QSerialPort();


    QSerialPortInfo portToUse;
    foreach (const QSerialPortInfo &port, QSerialPortInfo::availablePorts())
    {
        if(!port.isBusy() && (port.description().contains("Arduino") || port.manufacturer().contains("Arduino")))
                portToUse = port;
    }
    if(portToUse.isNull())
    {
        qDebug() << "Invalid Port" << portToUse.portName();
        return NO_SERIAL_PORT;
    }
    this->serial->setPort(portToUse);

    this->serial->setBaudRate(QSerialPort::Baud115200);
    this->serial->setDataBits(QSerialPort::Data8);
    this->serial->setParity(QSerialPort::NoParity);
    this->serial->setStopBits(QSerialPort::OneStop);
    this->serial->setFlowControl(QSerialPort::NoFlowControl);


    if (this->serial->open(QIODevice::ReadWrite))
    {
        qDebug() << "Connected to: " << portToUse.portName();
    }
    else
    {
        qDebug() << "Open error";
        return OPEN_ERROR;
    }
    return NO_ERROR;
}
