#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <canmessage.h>

class Logger : public QObject
{
    Q_OBJECT
public:
    Logger();
public slots:
    void receiveCanMsg(CANMessage* msg);
};

#endif // LOGGER_H
