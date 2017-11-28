#ifndef LOCKEDVIEWTAB_H
#define LOCKEDVIEWTAB_H

#include <QWidget>
#include <QtCharts>

class LockedViewTab : public QWidget
{
    Q_OBJECT
public:
    explicit LockedViewTab(QWidget *parent = nullptr);
    int getMinX();
    int getMaxX();

signals:
    void signalApplyPressed();
public slots:
    void slotApplyPressed();
private:
    QLabel * xRangeMinLabel;
    QLabel * xRangeMaxLabel;
    QSpinBox * xRangeMinSpinBox;
    QSpinBox * xRangeMaxSpinBox;
    QPushButton * applyPushButton;


    QGridLayout * layout;

    void intialization();
    void initializeLabel(QLabel *labelPtr, QString labelTitle);
    void initializeSpinBox(QSpinBox *spinBoxPtr, int max);
    void initializePushButton(QPushButton * pushButtonPtr, QString pushButtonTitle);
};

#endif // LOCKEDVIEWTAB_H
