#ifndef TESTINPUT_H
#define TESTINPUT_H

#include <QWidget>
#include <QTimer>

class TestInput : public QWidget
{
    Q_OBJECT
public:
    explicit TestInput(QWidget *parent = nullptr);
    QTimer *timer;

signals:
    void givePoint(QPointF);
public slots:
    void tick(); //Every tick emit givePoint()

private:
    int time = 0;
};

#endif // TESTINPUT_H
