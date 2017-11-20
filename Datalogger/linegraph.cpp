#include "linegraph.h"

#include <QPainter>

LineGraph::LineGraph(QWidget *parent) : QWidget(parent)
{
    initializeClassElements();
    graphSetUp();
}

void LineGraph::graphSetUp()
{
    connect(testInput, SIGNAL (givePoint(QPointF)), this, SLOT (recieveData(QPointF)));

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


    spinBox = new QSpinBox();
        spinBox->setMaximum(1000000);
    label = new QLabel();
        label->setText("Window X Width:");
    chartView = new QChartView(chart);
        initializeChartView();
    gridLayout = new QGridLayout();
        initializeGridLayout();
}

void LineGraph::initializeChartView()
{
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setRubberBand(QChartView::HorizontalRubberBand);
    chartView->lower();
}

void LineGraph::initializeGridLayout()
{
    gridLayout->addWidget(chartView, 1, 3);
    gridLayout->addWidget(spinBox, 1, 2, 1, 1, Qt::AlignTop);
    gridLayout->addWidget(label, 1, 1, 1, 1, Qt::AlignTop);
    setLayout(gridLayout);
}


void LineGraph::updateGraph(int count)
{
    int rangeMin = count - trackingX;
    int rangeMax = count;

    if (trackingX < 5) rangeMin = count - 100;

    if (rangeMin < 0) rangeMin = 0;

    axisX->setRange(rangeMin, rangeMax);
    chart->update();
}

//---------------------Slots---------------------

void LineGraph::recieveData (QPointF point)
{
//    if (lineSeries->count() == 60) //Removes the oldest point
//        lineSeries->remove(0);
    *lineSeries << point;
    updateGraph(lineSeries->count());
}

void LineGraph::wheelEvent(QWheelEvent *event) //Zooming in/out
{
    if(event->delta() > 0) trackingX -= lineSeries->count() / 10; //Zoom in
    else if(event->delta() < 0) trackingX += lineSeries->count() / 10; //Zoom out

    event->accept();
}

void LineGraph::keyPressEvent(QKeyEvent *event) //Detect Keyboard presses
{
    if (event->key() == Qt::Key_Enter)
        trackingX = spinBox->value();
}
