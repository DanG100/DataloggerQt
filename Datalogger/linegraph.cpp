#include "linegraph.h"

#include <QPainter>

LineGraph::LineGraph(QWidget *parent) : QWidget(parent)
{
    initializeClassElements();
    graphSetUp();
}

void LineGraph::graphSetUp()
{
    chart->legend()->hide();
    chart->setTitle(this->accessibleName()); //Whole Chart setup
    chart->addSeries(lineSeries1);
    chart->addSeries(lineSeries2);

    axisX->setTitleText("TimeStamp");
    chart->addAxis(axisX, Qt::AlignBottom); //axisX setup
    lineSeries1->attachAxis(axisX);
    lineSeries2->attachAxis(axisX);
    axisX->setTickCount(1);

    axisY1->setTitleText("Percent Usage");
    axisY1->setRange(0,100);
    axisY2->setTitleText("Blah Blah");
    chart->addAxis(axisY1, Qt::AlignLeft); //axisY1 and axisY2 setup
    chart->addAxis(axisY2, Qt::AlignRight);
    lineSeries1->attachAxis(axisY1);
    lineSeries2->attachAxis(axisY2);
    axisY1TitleBrush.setColor("Blue");
    axisY2TitleBrush.setColor("Green");
    axisY1->setTitleBrush(axisY1TitleBrush);
    axisY2->setTitleBrush(axisY2TitleBrush);

    lineSeries1->setColor(lineSeries1Color);
    lineSeries2->setColor(lineSeries2Color);
    lineSeries1->setUseOpenGL(true);
    lineSeries2->setUseOpenGL(true);
}

void LineGraph::initializeClassElements()
{

    graphTitle = "No Title";
    chart = new QChart();
    lineSeries1 = new QLineSeries();
    lineSeries2 = new QLineSeries();

    axisX = new QValueAxis();
    axisY1 = new QValueAxis();
    axisY2 = new QValueAxis();
    offSet = 20;
    range = 40;

    scrollingViewTab = new ScrollingViewTab();
    lockedViewTab = new LockedViewTab();

    viewModeTabWidget = new QTabWidget();
    viewModeTabWidget->addTab(scrollingViewTab, "Scrolling View");
    viewModeTabWidget->addTab(lockedViewTab, "Locked View");
    connect(scrollingViewTab, SIGNAL(signalApplyPressed()), this, SLOT(doApply()));
    connect(lockedViewTab, SIGNAL(signalApplyPressed()), this, SLOT(doApply()));
    viewModeTabWidget->setMaximumWidth(200);
    viewModeTabWidget->setMaximumHeight(150);
    chartView = new QChartView(chart);
    initializeChartView();
    gridLayout = new QGridLayout();
    initializeGridLayout();
}

void LineGraph::initializeChartView()
{
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumHeight(500);
    chartView->setMinimumWidth(500);
}

void LineGraph::initializeGridLayout()
{
    gridLayout->addWidget(chartView, 2, 1, 1, 1, Qt::AlignCenter);
    gridLayout->addWidget(viewModeTabWidget, 1, 1, 1, 1, Qt::AlignCenter);
    setLayout(gridLayout);
}


void LineGraph::updateGraph()
{

    if (currentTabIndex == 0) //Scrolling
    {
        rangeMin = maxX - offSet;
        rangeMax = rangeMin + range;
    }

    if (rangeMin == rangeMax) rangeMax++;

    axisY1->setRange(0, maxY1);
    axisY2->setRange(0, maxY2);

    axisX->setRange(rangeMin, rangeMax);
    chart->update();
}

void LineGraph::updateLine1(float timeStamp, float value)
{
    *lineSeries1 << QPointF(timeStamp, value);
    if (timeStamp > maxX) maxX = timeStamp;
    if (value > maxY1) maxY1 = value;
    updateGraph();
}

void LineGraph::updateLine2(float timeStamp, float value)
{
    *lineSeries2 << QPointF(timeStamp, value);
    if (timeStamp > maxX) maxX = timeStamp;
    if (value > maxY2) maxY2 = value;
    updateGraph();
}

void LineGraph::setYAxisName(int yAxisNum, QString name)
{
    if (yAxisNum == 1)
        axisY1->setTitleText(name);
    else if(yAxisNum == 2)
        axisY2->setTitleText(name);
}


//---------------------Slots---------------------

void LineGraph::wheelEvent(QWheelEvent *event) //Zooming in/out //Not used yet... yet
{
    event->accept();
}

void LineGraph::keyPressEvent(QKeyEvent *event) //Detect Keyboard presses
{
    if (event->key() == Qt::Key_Enter) doApply();

}

void LineGraph::doApply()
{
    if (viewModeTabWidget->currentIndex() == 0) //If scrolling view tab is open
    {
        currentTabIndex = 0;
        offSet = scrollingViewTab->getOffset();
        range = scrollingViewTab->getRange();

    }
    if (viewModeTabWidget->currentIndex() == 1) //If locked view tab is open
    {
        currentTabIndex = 1;
        rangeMin = lockedViewTab->getMinX();
        rangeMax = lockedViewTab->getMaxX();
    }
}
