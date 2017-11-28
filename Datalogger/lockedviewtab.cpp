#include "lockedviewtab.h"

LockedViewTab::LockedViewTab(QWidget *parent) : QWidget(parent)
{
    intialization();
}

int LockedViewTab::getMinX()
{
    return xRangeMinSpinBox->value();
}

int LockedViewTab::getMaxX()
{
    return xRangeMaxSpinBox->value();
}

void LockedViewTab::intialization()
{
    xRangeMinLabel = new QLabel();
        initializeLabel(xRangeMinLabel, "Minimum X:");
    xRangeMaxLabel = new QLabel();
        initializeLabel(xRangeMaxLabel, "Maximum X:");
    xRangeMinSpinBox = new QSpinBox();
        initializeSpinBox(xRangeMinSpinBox, 999999999);//----------------------Pretty sure this is bad programming, fix later
    xRangeMaxSpinBox = new QSpinBox();
        initializeSpinBox(xRangeMaxSpinBox, 999999999);//----------------------Pretty sure this is bad programming, fix later
    applyPushButton = new QPushButton();
        initializePushButton(applyPushButton, "Apply");
    layout = new QGridLayout();
        layout->addWidget(xRangeMinLabel, 1, 1, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeMaxLabel, 1, 2, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeMinSpinBox, 2, 1, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeMaxSpinBox, 2, 2, 1, 1, Qt::AlignCenter);
        layout->addWidget(applyPushButton, 3, 1, 1, 2, Qt::AlignCenter);
    this->setLayout(layout);

    connect(applyPushButton, SIGNAL (pressed()), this, SLOT (slotApplyPressed()));
}

void LockedViewTab::initializeLabel(QLabel *labelPtr, QString labelTitle)
{
    labelPtr->setText(labelTitle);
}

void LockedViewTab::initializeSpinBox(QSpinBox *spinBoxPtr, int max)
{
    spinBoxPtr->setMaximum(max);
}

void LockedViewTab::initializePushButton(QPushButton *pushButtonPtr, QString pushButtonTitle)
{
    pushButtonPtr->setText(pushButtonTitle);
}

void LockedViewTab::slotApplyPressed()
{
    emit signalApplyPressed();
}
