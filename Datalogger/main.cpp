#include "mainwindow.h"
#include "serialport.h"
#include "parser.h"
#include <iostream>

#include <QApplication>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    char example[14];
    example[0] = 'a';
    example[1] = 'b';
    example[2] = 'c';
    example[3] = 'd';
    example[4] = 'e';
    example[5] = 'f';
    example[6] = 'g';
    example[7] = 'h';
    example[8] = 'i';
    example[9] = 'j';
    example[10] = 'k';
    example[11] = 'l';
    example[12] = 'm';
    example[13] = 'n';

    SerialPort serial;
    Parser* obj = serial.getParsedObject(example);
    cout << ((Throttle*)obj)->throttleScale << endl;

    return a.exec();
}
