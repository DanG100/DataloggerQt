#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QWidget>
#include <QtCharts>
#include <QtGui>
#include <QWheelEvent>
#include <QKeyEvent>
#include "testinput.h"


class LineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit LineGraph(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event); //Mousewheel or trackpad scroll

protected:


signals:

public slots:
    void recieveData (QPointF point);
    void keyPressEvent(QKeyEvent *event);

private:
    QString graphTitle;
    QChart * chart;
    QLineSeries *lineSeries;
    TestInput * testInput;
    QValueAxis *axisX;
    QValueAxis *axisY;
    int trackingX = 0;
    QSpinBox * spinBox;
    QChartView * chartView;
    QGridLayout *gridLayout;
    QLabel * label;

    void initializeClassElements();
    void graphSetUp();
    void initializeChartView();
    void initializeGridLayout();
    void updateGraph(int count);
};

#endif // LINEGRAPH_H
