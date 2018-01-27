#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <canmessage.h>
#include <QFile>
#include <QDateTime>

class Logger : public QObject
{
    Q_OBJECT
public:
    QFile file;
    Logger();
public slots:
    void startFile();//make file named the date/time of start of program
    void endFile();//close file
    void receiveCanMsg(CANMessage* msg);
};

#endif // LOGGER_H
