#ifndef PARSER_H
#define PARSER_H


class Parser
{
public:
    Parser();
    ~Parser();
    virtual void parse(char data[14]);
};

class Throttle: public Parser
{
public:
    int checkBit      = 0;
    int throttleScale = 0;
    int zeroPadded    = 0; //ask if zero padded is something

    Throttle();
    ~Throttle();

    void parse(char data[14]);

};

class Brake: public Parser
{
public:
    int checkBit    = 0;
    int scaledBrake = 0;
    int zeroPadded  = 0;
    int rawBrakeVal = 0;

    Brake();
    ~Brake();

    void parse(char data[14]);
};

class Pack: public Parser
{
public:
    int carName = 0;
    int soc     = 0;
    int bmsStat = 0;

    Pack();
    ~Pack();

    void parse(char data[14]);
};

class Voltage: public Parser
{
public:
    int minVolt  = 0;
    int maxVolt  = 0;
    int packVolt = 0;

    Voltage();
    ~Voltage();

    void parse(char data[14]);
};

class Temperature: public Parser
{
public:
    int nodeZero    = 0;
    int nodeOne     = 0;
    int nodeTwo     = 0;
    int nodeThree   = 0;
    int nodeFour    = 0;
    int nodeFive    = 0;
    int highestNode = 0;
    int highestTemp = 0;

    Temperature();
    ~Temperature();

    void parse(char data[14]);
};

class CurrentRead: public Parser
{
public:
    int currDirection    = 0;
    int rawCurr          = 0;
    int currDirectionTwo = 0;
    int currFlow         = 0;

    CurrentRead();
    ~CurrentRead();

    void parse(char data[14]);
};

class DashBoard: public Parser
{
public:
    int state      = 0;
    int errorState = 0;

    DashBoard();
    ~DashBoard();

    void parse(char data[14]);
};

class CurtisDebug: public Parser
{
public:
    int setInterlock = 0;
    int hvRequest    = 0;
    int state        = 0;
    int pmwOne       = 0;
    int pmwTwo       = 0;
    int pmwThree     = 0;
    int vclThrottle  = 0;
    int vclBrake     = 0;

    CurtisDebug();
    ~CurtisDebug();

    void parse(char data[14]);
};

class CurtisStatus: public Parser
{
public:
    int capacitorHighVolt = 0;
    int capacitorLowVolt  = 0;
    int rpmHigh           = 0;
    int rpmLow            = 0;
    int tempHigh          = 0;
    int tempLow           = 0;
    int throttleHigh      = 0;
    int throttleLow       = 0;

    CurtisStatus();
    ~CurtisStatus();

    void parse(char data[14]);
};

class CurtisRecvAcknowledge: public Parser
{
public:
    int ff                 = 0;
    int highVolt           = 0;
    int lowVolt            = 0;
    int highCurrent        = 0;
    int lowCurrent         = 0;
    int currentDisplay     = 0;
    int controllerTempHigh = 0;
    int controllerTempLow  = 0;

    CurtisRecvAcknowledge();
    ~CurtisRecvAcknowledge();

    void parse(char data[14]);
};

class CurtisRecv: public Parser
{
public:
    int setInterlock = 0;
    int throttleHigh = 0;
    int throttleLow  = 0;

    CurtisRecv();
    ~CurtisRecv();

    void parse(char data[14]);
};

class DLHeartbeat: public Parser
{
public:
    int heartBeat = 0;

    DLHeartbeat();
    ~DLHeartbeat();

    void parse(char data[14]);

};

class DLTime: public Parser
{
public:
    int yearHigh = 0;
    int yearLow  = 0;
    int month    = 0;
    int day      = 0;
    int hour     = 0;
    int minute   = 0;
    int second   = 0;

    DLTime();
    ~DLTime();

    void parse(char data[14]);
};

class SensorStatus: public Parser
{
public:
    int wheelSpeedOne   = 0;
    int wheelSpeedTwo   = 0;
    int wheelSpeedThree = 0;
    int wheelSpeedFour  = 0;
    int socPercent      = 0;

    SensorStatus();
    ~SensorStatus();

    void parse(char data[14]);
};

#endif // PARSER_H
