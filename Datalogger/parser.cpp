#include "parser.h"

parser::parser(){}

parser::~parser(){}

virtual void parser::parse(){}

Throttle::Throttle(){}

Throttle::~Throttle(){}

Throttle::parser(char* data)
{
    checkBit = data[6];
    throttleScale = (data[7] << 8) + data[8];
}
Brake::Brake(){}

Brake::~Brake(){}

void Brake::parse(char* data)
{
    checkBit = data[6]; //difference check bit
    scaledBrake = (data[7] << 8) + data[8]; //scaled brake value with 15% deadzone
    //zeroPadded = (data[]) >> 16; //zero-padded
    rawBrakeVal = (data[12] << 8) + data[13]; //raw brake value
}


Pack::Pack(){}

Pack::~Pack(){}

void Pack::parse(char* data)
{
    carName = data[6]; //Car name
    soc = data[7]; //SOC in percent
    bmsStat = (data[8] << 8) + data[9]; //BMS status bits
}

Voltage::Voltage(){}

Voltage::~Voltage(){}

void Voltage::parse()
{
    minVolt = (data[6] << 8) + data[7]; //Minimum cell voltage in mv (HEX)
    maxVolt = (data[8] << 8) + data[9]; //Maximum cell voltage in mv (HEX)
    packVolt = (data[10] << 24) + (data[11] << 16) + (data[12] << 8) + data[13]; //Pack voltage mV (HEX)
}

Temperature::Temperature(){}

Temperature::~Temperature(){}

void Temperature::parse(char* data)
{
    nodeZero = data[6]; //Highest temp value of Node 0 (DEC degree)
    nodeOne = data[7]; //Highest temp value of Node 1 (DEC Degree)
    nodeTwo = data[8]; //Highest temp value of Node 2 (DEC Degree)
    nodeThree = data[9]; //Highest temp value of Node 3 (DEC Degree)
    nodeFour = data[10]; //Highest temp value of Node 4 (DEC Degree)
    nodeFive = data[11]; //Highest temp value of Node 5 (DEC Degree)
    highestNode = data[12]; //Index of node with highest temperature
    highestTemp = data[13]; //Highest temp of Battery Pack (DEC Degree)
}

CurrentRead::CurrentRead(){}

CurrentRead::~CurrentRead(){}

void CurrentRead::parse(char* data)
{
    currDirection = data[6]; //Current direction(0 for discharging 1 for charging)
    rawCurr = (data[7] << 8) + data[8]; //Raw Current flow in Amper (HEX)
    currDirectionTwo = data[11]; //Current direction (0 for discharging)
    currFlow = (data[12] << 8) + data[13]; //Current flow in Amper (DEC)
}

DashBoard::DashBoard(){}

DashBoard::~DashBoard(){}

void DashBoard::parse(char *data)
{
    state = data[6]; //State
    errorState = data[7]; //error state
}

CurtisDebug::CurtisDebug(){}

CurtisDebug::~CurtisDebug(){}

void CurtisDebug::parse(char *data)
{
    setInterlock = data[6]; //SetInterlock
    hvRequest = data[7]; //HVRequest
    state = data[8]; //state
    pmwOne = data[9]; //PMW1_Output
    pmwTwo = data[10]; //PMW2_Output
    pmwThree = data[11]; //PMW3_Output
    vclThrottle = data[12]; //VCL_Throttle
    vclBrake = data[13]; //VCL_Brake
}

CurtisStatus::CurtisStatus(){}

CurtisStatus::~CurtisStatus(){}

void CurtisStatus::parse(char *data)
{
    capacitorHighVolt = data[6]; //Capacitor Voltage High
    capacitorLowVolt = data[7]; //Capacitor Voltage Low
    rpmHigh = data[8]; //ABS_Motor_RPM High (High+low = 0 to 7FFF)
    rpmLow = data[9]; //ABS_Motor_RPM Low
    tempHigh = data[10]; //Motor_Temperature High(high+low = 0 to 3E8(0 to 1000))
    tempLow = data[11]; //Motor_Temperature LOW
    throttleHigh = data[12]; //ABS_Mapped_Throttle High
    throttleLow = data[13]; //ABS_Mapped_Throttle LOW
}

CurtisRecvAcknowledge::CurtisRecvAcknowledge(){}

CurtisRecvAcknowledge::CurtisRecvAcknowledge(){}

void CurtisRecvAcknowledge::parse(char *data)
{
    ff = data[6]; //FF
    highVolt = data[7]; //Kewswitch Voltage High (LV Battery)
    lowVolt = data[8]; //Keyswitch Voltage Low (LV Battery)
    highCurrent = data[9]; //Battery Current High
    lowCurrent = data[10]; //Battery Current Low
    currentDisplay = data[11]; //Battery Current Display
    controllerTempHigh = data[12]; //Controller Temperature High
    controllerTempLow = data[13]; //Controller Temperature Low
}

CurtisRecv::CurtisRecv(){}

CurtisRecv::~CurtisRecv(){}

void CurtisRecv::parse(char *data)
{
    setInterlock = data[6]; //SetInterlock
    throttleHigh = data[7]; //throttle_HI
    throttleLow = data[8]; //throttle_LO
}

DLHeartbeat::DLHeartbeat(){}

DLHeartbeat::~DLHeartbeat(){}

DLHeartbeat::parse(char* data)
{
    heartBeat = data[6]; //0x01
}

DLTime::DLTime(){}

DLTime::~DLTime(){}

void DLTime::parse(char *data)
{
    yearHigh = data[7]; //Year High(HEX)
    yearLow = data[8]; //Year Low(HEX)
    month = data[9]; //Month(HEX)
    day = data[10]; //Day(HEX)
    hour = data[11]; //Hour(HEX)
    minute = data[12]; //Minute(HEX)
    second = data[13]; //Second(HEX)
}

SensorStatus::SensorStatus(){}

SensorStatus::~SensorStatus(){}

void SensorStatus::parse(char *data)
{
    wheelSpeedOne = data[6]; //front left
    wheelSpeedTwo = data[7]; //front right
    wheelSpeedThree = data[8]; //rear left
    wheelSpeedFour = data[9]; //rear right
    socPercent = data[12]; //SoC Percent(0 - 100)
}
