#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QWidget>
#include <QtCharts>
#include <QtGui>
#include <QWheelEvent>
#include <QKeyEvent>
#include "testinput.h"
#include "scrollingviewtab.h"
#include "lockedviewtab.h"
#include "canmessage.h"


class LineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit LineGraph(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event); //Mousewheel or trackpad scroll

protected:


signals:

public slots:
    void receiveData (QPointF point);
    void keyPressEvent(QKeyEvent *event);
    void doApply();
    void receiveCanMsg(CANMessage *msg);
private:
    QString graphTitle;
    QChart * chart;
    QLineSeries *lineSeries;
    TestInput * testInput;

    QValueAxis *axisX;
    QValueAxis *axisY;

    QSpinBox * spinBox;
    QChartView * chartView;
    QGridLayout *gridLayout;
    QLabel * label;


    QTabWidget * viewModeTabWidget;
    int currentTabIndex;

    ScrollingViewTab * scrollingViewTab;
    LockedViewTab * lockedViewTab;
    int offSet;
    int range;
    int rangeMin;
    int rangeMax;

    void initializeClassElements();
    void graphSetUp();
    void initializeChartView();
    void initializeGridLayout();
    void updateGraph(int count);
};

#endif // LINEGRAPH_H
