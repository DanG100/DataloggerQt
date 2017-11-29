#ifndef GRAPHINPUTHANDLER_H
#define GRAPHINPUTHANDLER_H

#include <QObject>
#include "serialport.h"
#include "linegraph.h"

class GraphInputHandler : public QObject
{
    Q_OBJECT
public:
    explicit GraphInputHandler(LineGraph *lineGraph1, LineGraph *lineGraph2, QObject *parent = nullptr);

    LineGraph * lineGraph1;
    LineGraph * lineGraph2;
    LineGraph * lineGraph3;
    LineGraph * lineGraph4;

signals:
    void newThrottle(float timeStamp, float value);
    void newBrake(float timeStamp, float value);
    void newVoltage(float timeStamp, float value);
    void newTemperature(float timeStamp, float value);
    void newCurrentRead(float timeStamp, float value);

public slots:
    void recieveCanMsg(CANMessage * msg);
};

#endif // GRAPHINPUTHANDLER_H
