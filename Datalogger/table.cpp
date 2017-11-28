#include "table.h"

Table::Table(QWidget *parent) : QWidget(parent)
{
    gridLayout = new QGridLayout(this);

    tableView = new QTableView();
    table = new QTableWidget(tableView);


    table->setRowCount(3);
    table->setColumnCount(1);
    tableColumnHeader << "Value";
    tableRowHeader << "Temperature" << "Voltage" << "Current";
    table->setHorizontalHeaderLabels(tableColumnHeader);
    table->setVerticalHeaderLabels(tableRowHeader);
    gridLayout->addWidget(tableView, 1, 1, 1, 1, Qt::AlignCenter);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //Disables user from editing table values
}
