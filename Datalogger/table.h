#ifndef TABLE_H
#define TABLE_H

#include <QWidget>
#include <QTableWidget>
#include <QGridLayout>

class Table : public QWidget
{
    Q_OBJECT
public:
    explicit Table(QWidget *parent = nullptr);

signals:

public slots:

private:
    QTableWidget * table;
    QTableView * tableView;
    QGridLayout * gridLayout;
    QStringList tableColumnHeader;
    QStringList tableRowHeader;

};

#endif // TABLE_H
