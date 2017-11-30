#include "graphinputhandler.h"



GraphInputHandler::GraphInputHandler(LineGraph *lineGraph1, LineGraph *lineGraph2, Table * table, QObject *parent) : QObject(parent) ,
    lineGraph1(lineGraph1) , lineGraph2(lineGraph2) , table(table)
{
    lineGraph1->setYAxisName(1, "Temperature");
    lineGraph1->setYAxisName(2, "Voltage");
    lineGraph2->setYAxisName(1, "Temperature");
    lineGraph2->setYAxisName(2, "Throttle %");
}

void GraphInputHandler::recieveCanMsg(CANMessage * msg)
{
    float timeStamp = msg->timeStamp;
    float value = 0;
    if (typeid(*msg) == typeid(Throttle)) //Throttle
    {
        value = dynamic_cast<Throttle*> (msg)->throttleScale;
        lineGraph2->updateLine2(timeStamp, value);
    }
    else if (typeid(*msg) == typeid(Brake)) //Brake
    {
        value = dynamic_cast<Brake*> (msg)->scaledBrake;
    }
    else if (typeid(*msg) == typeid(Voltage)) //Voltage
    {
        value = dynamic_cast<Voltage*> (msg)->packVolt;
        lineGraph1->updateLine2(timeStamp, value);
    }
    else if (typeid(*msg) == typeid(Temperature)) //Temperature
    {
        value = dynamic_cast <Temperature*> (msg)->highestTemp;
        lineGraph1->updateLine1(timeStamp, value);
        lineGraph2->updateLine1(timeStamp, value);
    }
    else if (typeid(*msg) == typeid(CurrentRead)) //Current
    {
        value = dynamic_cast <CurrentRead*> (msg)->rawCurr;
    }
    else
    {
        qDebug("Something is wrong");
        //Something is probably wrong

    }
}
