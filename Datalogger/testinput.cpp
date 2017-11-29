#include "testinput.h"

TestInput::TestInput(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(25); //Change this number to delay point transmission
}


void TestInput::tick()
{

    if (rand() % 30 > 20)
    {
        Throttle * throttle = new Throttle();
        throttle->throttleScale = rand() % 100;
        msg = dynamic_cast <CANMessage*> (throttle);
    }
    else if(rand() % 30 < 10)
    {
        Voltage * voltage = new Voltage();
        voltage->packVolt = rand() % 500;
        msg = dynamic_cast <CANMessage*> (voltage);
    }
    else
    {
        Temperature * temperature = new Temperature();
        temperature->nodeFive = rand() % 300;
        msg = dynamic_cast <CANMessage*> (temperature);
    }
    msg->timeStamp = time++;
    emit giveCanMsg(msg);
}
