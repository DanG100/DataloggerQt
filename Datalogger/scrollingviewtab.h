#ifndef SCROLLINGVIEWTAB_H
#define SCROLLINGVIEWTAB_H

#include <QWidget>
#include <QtGui>
#include <QtCharts>

class ScrollingViewTab : public QWidget
{
    Q_OBJECT
public:
    explicit ScrollingViewTab(QWidget *parent = nullptr);
    int getOffset();
    int getRange();

signals:
    void signalApplyPressed();
public slots:
    void slotApplyPressed();
private:
    QLabel * xOffsetLabel;
    QLabel * xRangeLabel;
    QSpinBox * xOffsetSpinBox;
    QSpinBox * xRangeSpinBox;
    QPushButton * applyPushButton;


    QGridLayout * layout;

    void intialization();
    void initializeLabel(QLabel *labelPtr, QString labelTitle);
    void initializeSpinBox(QSpinBox *spinBoxPtr, int max);
    void initializePushButton(QPushButton * pushButtonPtr, QString pushButtonTitle);
};

#endif // SCROLLINGVIEWTAB_H
