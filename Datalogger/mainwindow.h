#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "serialport.h"
#include "logger.h"
#include "graphinputhandler.h"

#include "testinput.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionExit_triggered();

signals:
    void startLogger();
    void stopLogger();

private:
    Ui::MainWindow *ui;
    SerialPort serialPort;
    Logger logger;
    GraphInputHandler * graphInputHandler;

    TestInput * testInput;
};

#endif // MAINWINDOW_H
