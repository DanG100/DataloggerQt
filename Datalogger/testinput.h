#ifndef TESTINPUT_H
#define TESTINPUT_H

#include <QWidget>
#include <QTimer>
#include "canmessage.h"

class TestInput : public QWidget
{
    Q_OBJECT
public:
    explicit TestInput(QWidget *parent = nullptr);
    QTimer *timer;

signals:
    void giveCanMsg(CANMessage * msg);
public slots:
    void tick(); //Every tick emit givePoint()

private:
    int time = 0;
    CANMessage * msg;
};

#endif // TESTINPUT_H
