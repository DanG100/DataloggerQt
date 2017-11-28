#include "linegraph.h"

#include <QPainter>

LineGraph::LineGraph(QWidget *parent) : QWidget(parent)
{
    initializeClassElements();
    graphSetUp();
}

void LineGraph::graphSetUp()
{
    connect(testInput, SIGNAL (givePoint(QPointF)), this, SLOT (receiveData(QPointF)));

    chart->legend()->hide();
    chart->setTitle(graphTitle); //Whole Chart setup
    chart->addSeries(lineSeries);

    axisX->setTitleText("Time (Seconds)");
    chart->addAxis(axisX, Qt::AlignBottom); //axisX setup
    lineSeries->attachAxis(axisX);
    axisX->setTickCount(1);

    axisY->setTitleText("Percent Usage");
    axisY->setRange(0,100);
    chart->addAxis(axisY, Qt::AlignLeft); //axisY setup
    lineSeries->attachAxis(axisY);
}

void LineGraph::initializeClassElements()
{

    graphTitle = "No Title";
    chart = new QChart();
    lineSeries = new QLineSeries();
    testInput = new TestInput();

    axisX = new QValueAxis();
    axisY = new QValueAxis();
    offSet = 20;
    range = 40;

    scrollingViewTab = new ScrollingViewTab();
    lockedViewTab = new LockedViewTab();

    viewModeTabWidget = new QTabWidget();
        viewModeTabWidget->addTab(scrollingViewTab, "Scrolling View");
        viewModeTabWidget->addTab(lockedViewTab, "Locked View");
        connect(scrollingViewTab, SIGNAL(signalApplyPressed()), this, SLOT(doApply())); //THESE CONNECTS DON'T WORK YET
        connect(lockedViewTab, SIGNAL(signalApplyPressed()), this, SLOT(doApply())); //SO NO APPLY BUTTON FUNCTIONALITY

    chartView = new QChartView(chart);
        initializeChartView();
    gridLayout = new QGridLayout();
        initializeGridLayout();
}

void LineGraph::initializeChartView()
{
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumHeight(800);
    chartView->setMinimumWidth(800);
}

void LineGraph::initializeGridLayout()
{
    gridLayout->addWidget(chartView, 1, 2, 1, 1, Qt::AlignCenter);
    gridLayout->addWidget(viewModeTabWidget, 1, 1, 1, 1, Qt::AlignCenter);
    gridLayout->setColumnMinimumWidth(2, 400);
    gridLayout->setColumnStretch(2, 1000);
    setLayout(gridLayout);
}


void LineGraph::updateGraph(int count)
{

    if (currentTabIndex == 0) //Scrolling
    {
        rangeMin = count - offSet;
        rangeMax = rangeMin + range;
    }

    //if (rangeMin < 0) rangeMin = 0;
    if (rangeMin == rangeMax) rangeMax++;

    axisX->setRange(rangeMin, rangeMax);
    chart->update();
}

//---------------------Slots---------------------

void LineGraph::receiveData (QPointF point)
{
    *lineSeries << point;
    updateGraph(lineSeries->count());
}

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

void LineGraph::receiveCanMsg(CANMessage *msg)
{
/*
 *
 * do the stuff here
 */
}
