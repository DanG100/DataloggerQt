#ifndef LINEGRAPH_H
#define LINEGRAPH_H

#include <QWidget>
#include <QtCharts>
#include <QtGui>
#include <QWheelEvent>
#include <QKeyEvent>
#include "scrollingviewtab.h"
#include "lockedviewtab.h"
#include "canmessage.h"


class LineGraph : public QWidget
{
    Q_OBJECT
public:
    explicit LineGraph(QWidget *parent = nullptr);
    void wheelEvent(QWheelEvent *event); //Mousewheel or trackpad scroll
    void updateLine1(float timeStamp, float value);
    void updateLine2(float timeStamp, float value);
    void setYAxisName(int yAxisNum, QString name);

protected:


signals:

public slots:
    void keyPressEvent(QKeyEvent *event);
    void doApply();
private:
    QString graphTitle;
    QChart * chart;
    QLineSeries *lineSeries1;
    QLineSeries *lineSeries2;
    QColor lineSeries1Color = "blue";
    QColor lineSeries2Color = "green";

    QValueAxis *axisX;
    QValueAxis *axisY1;
    QValueAxis *axisY2;
    QBrush axisY1TitleBrush;
    QBrush axisY2TitleBrush;
    float maxX = 0;
    float maxY1 = 0;
    float maxY2 = 0;

    QSpinBox * spinBox;
    QChartView * chartView;
    QVBoxLayout *verticalLayout;
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
    void updateGraph();
};

#endif // LINEGRAPH_H
