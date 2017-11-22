#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "canmessage.h"
#include <QDebug>

#define PACKET_LEN 14
#define NO_SERIAL_PORT 2
#define OPEN_ERROR 1
#define NO_ERROR 0


class SerialPort: public QObject
{
    Q_OBJECT
public:
    QSerialPort *serial;
    char data[14]; //CAN message held in sections of 8 bits (a char)

    SerialPort();
    ~SerialPort();
    int getCanId(char* data);
    CANMessage* getParsedObject(char* data);

private:
    int setupSerialPort();
private slots:
    void readDataFromPort();
signals:
    void receivedPacket(CANMessage* packet);
};

#endif // SERIALPORT_H
