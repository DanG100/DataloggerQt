#ifndef GRAPHINPUTHANDLER_H
#define GRAPHINPUTHANDLER_H

#include <QObject>
#include "serialport.h"
#include "linegraph.h"
#include "table.h"

class GraphInputHandler : public QObject            //This is going to be used to handle the flow of data into the table also
{
    Q_OBJECT
public:
    explicit GraphInputHandler(LineGraph *lineGraph1, LineGraph *lineGraph2, Table * table ,QObject *parent = nullptr);
    LineGraph * lineGraph1;
    LineGraph * lineGraph2;
    Table * table;

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
