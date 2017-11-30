#include "table.h"

Table::Table(QWidget *parent) : QWidget(parent)
{
    gridLayout = new QGridLayout(this);

    tableView = new QTableView();
    table = new QTableWidget(tableView);


    table->setFixedHeight(480);
    tableView->setFixedHeight(480); //This is awful programming, fix


    table->setRowCount(15);
    table->setColumnCount(1);
    tableColumnHeader << "Value";
    tableRowHeader << "Brake" << "Throttle" << "Temp. SP 1" << "Temp. SP 2" << "Temp. SP 3" << "Temp. SP 4"
                   << "Temp. SP 5" << "Temp. SP 6" << "Current" << "Pack Voltage (mv)" << "Pack Min" << "Pack Max" <<  "Car State" << "BMS Error Flags";
    table->setHorizontalHeaderLabels(tableColumnHeader);
    table->setVerticalHeaderLabels(tableRowHeader);

    gridLayout->addWidget(tableView, 1, 1, 1, 1, Qt::AlignCenter);

    table->setEditTriggers(QAbstractItemView::NoEditTriggers); //Disables user from editing table values
}
