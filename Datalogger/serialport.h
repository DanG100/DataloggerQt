#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "parser.h"

#define PACKET_LE


class SerialPort: public QObject
{
    Q_OBJECT
public:
    QSerialPort *serial;
    char data[14]; //CAN message held in sections of 8 bits (a char)

    SerialPort();
    ~SerialPort();
    void readPort();
    int getCanId(char* fakeData);
    //char* getDataAddress();
    Parser* getParsedObject(char* str);

private slots:
    void readDataFromPort();
signals:
    void receivedPacket(Parse* packet);
};

#endif // SERIALPORT_H
