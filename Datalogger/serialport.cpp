#include "serialport.h"

SerialPort::SerialPort()
{
    *serial = new QSerialPort();
    serial->setPortName("ttyUSB0");
    serial->setParity(QSerialPort::NoParity);
    serial->setBaudRate(QSerialPort::Baud9600, QSerialPort::AllDirections);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    serial->open(QIODevice::ReadOnly);
}

SerialPort::~SerialPort()
{

}

void SerialPort::readPort()
{
    this->serial->readLine(data, 14); //reads port until 14 chunks of 8 bits read, or newline

}

QByteArray SerialPort::getCanId()
{
    QByteArray canId = data[0] + data[1];
    return canId.toUTF8();
}

char* SerialPort::getDataAddress()
{
    return &data;
}
