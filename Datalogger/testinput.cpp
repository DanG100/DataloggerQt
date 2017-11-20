#include "testinput.h"

TestInput::TestInput(QWidget *parent) : QWidget(parent)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(tick()));
    timer->start(100); //Change this number to delay point transmission
}


void TestInput::tick()
{
    emit givePoint(QPointF (time++, rand() % 100));
}
