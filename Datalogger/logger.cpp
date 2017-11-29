#include "logger.h"
#include <iostream>
#include <QFile>
#include <QTextStream>

//using namespace std;

Logger::Logger()
{

}

//USE QFILE
void Logger::startFile() //make file named the date/time of start of program
{
    time_t now = time(0);
    tm* namePtr = localtime(&now);
    QString name = asctime(namePtr);
    file.setFileName(name + ".csv");
    file.open(QIODevice::WriteOnly);
}

void Logger::endFile() //close file
{
    file.close();
}

void Logger::receiveCanMsg(CANMessage *msg)
{
    QTextStream fileStream(&file);

    int canId = msg->canId;
    int timeStamp = msg->timeStamp;
    fileStream << canId << "," << timeStamp << "," ;

    if(canId == 0x200)
        fileStream << ((Throttle*)msg)->checkBit << "," << ((Throttle*)msg)->throttleScale << endl;
    else if(canId == 0x201)
        fileStream << ((Brake*)msg)->checkBit << "," << ((Brake*)msg)->scaledBrake << "," << ((Brake*)msg)->rawBrakeVal << endl;
    else if(canId == 0x188)
        fileStream << ((Pack*)msg)->carName << "," << ((Pack*)msg)->soc << "," << ((Pack*)msg)->bmsStat << endl;
    else if(canId == 0x388)
        fileStream << ((Voltage*)msg)->minVolt << "," << ((Voltage*)msg)->maxVolt << "," << ((Voltage*)msg)->packVolt << endl;
    else if(canId == 0x488)
        fileStream << ((Temperature*)msg)->nodeZero << "," << ((Temperature*)msg)->nodeOne << "," << ((Temperature*)msg)->nodeTwo << "," << ((Temperature*)msg)->nodeThree << "," <<((Temperature*)msg)->nodeFour << "," << ((Temperature*)msg)->nodeFive << "," << ((Temperature*)msg)->highestNode << "," << ((Temperature*)msg)->highestTemp << endl;
    else if(canId == 0x288)
        fileStream << ((CurrentRead*)msg)->currDirection << "," << ((CurrentRead*)msg)->rawCurr << "," << ((CurrentRead*)msg)->currDirectionTwo << "," << ((CurrentRead*)msg)->currFlow << endl;
    else if(canId == 0x626)
        fileStream << ((DashBoard*)msg)->state << "," << ((DashBoard*)msg)->errorState << endl;
    else if(canId == 0x466)
        fileStream << ((CurtisDebug*)msg)->setInterlock << "," << ((CurtisDebug*)msg)->hvRequest << "," << ((CurtisDebug*)msg)->state << "," << ((CurtisDebug*)msg)->pmwOne << "," << ((CurtisDebug*)msg)->pmwTwo << "," << ((CurtisDebug*)msg)->pmwThree << "," << ((CurtisDebug*)msg)->vclThrottle << "," << ((CurtisDebug*)msg)->vclBrake << endl;
    else if(canId == 0x566)
        fileStream << ((CurtisStatus*)msg)->capacitorHighVolt << "," << ((CurtisStatus*)msg)->capacitorLowVolt << "," << ((CurtisStatus*)msg)->rpmHigh << "," << ((CurtisStatus*)msg)->rpmLow << "," << ((CurtisStatus*)msg)->tempHigh << "," << ((CurtisStatus*)msg)->tempLow << "," << ((CurtisStatus*)msg)->throttleHigh << "," << ((CurtisStatus*)msg)->throttleLow << endl;
    else if(canId == 0x666)
        fileStream << ((CurtisRecvAcknowledge*)msg)->ff << "," << ((CurtisRecvAcknowledge*)msg)->highVolt << "," << ((CurtisRecvAcknowledge*)msg)->lowVolt << "," << ((CurtisRecvAcknowledge*)msg)->highCurrent << "," << ((CurtisRecvAcknowledge*)msg)->lowCurrent << "," << ((CurtisRecvAcknowledge*)msg)->currentDisplay << "," << ((CurtisRecvAcknowledge*)msg)->controllerTempHigh << "," << ((CurtisRecvAcknowledge*)msg)->controllerTempLow << endl;
    else if(canId == 0x766)
        fileStream << ((CurtisRecv*)msg)->setInterlock << "," << ((CurtisRecv*)msg)->throttleHigh << "," << ((CurtisRecv*)msg)->throttleLow << "," << endl;
    else if(canId == 0x223)
        fileStream << ((DLHeartbeat*)msg)->heartBeat << endl;
    else if(canId == 0x123)
        fileStream << ((DLTime*)msg)->yearHigh << "," << ((DLTime*)msg)->yearLow << "," << ((DLTime*)msg)->month << "," << ((DLTime*)msg)->day << "," << ((DLTime*)msg)->hour << "," << ((DLTime*)msg)->minute << "," << ((DLTime*)msg)->second << endl;
    else if(canId == 0x247)
        fileStream << ((SensorStatus*)msg)->wheelSpeedOne << "," << ((SensorStatus*)msg)->wheelSpeedTwo << "," << ((SensorStatus*)msg)->wheelSpeedThree << "," << ((SensorStatus*)msg)->wheelSpeedFour << "," << ((SensorStatus*)msg)->socPercent << endl;
}
