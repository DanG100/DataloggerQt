#include "scrollingviewtab.h"

ScrollingViewTab::ScrollingViewTab(QWidget *parent) : QWidget(parent)
{
    intialization();
}

void ScrollingViewTab::intialization()
{
    xOffsetLabel = new QLabel();
        initializeLabel(xOffsetLabel, "Offset:");
    xRangeLabel = new QLabel();
        initializeLabel(xRangeLabel, "Range:");
    xOffsetSpinBox = new QSpinBox();
        initializeSpinBox(xOffsetSpinBox, 999999999); //----------------------Pretty sure this is bad programming, fix later
        xOffsetSpinBox->setToolTip("The offset from the newest point");
    xRangeSpinBox = new QSpinBox();
        initializeSpinBox(xRangeSpinBox, 999999999);//----------------------Pretty sure this is bad programming, fix later
        xRangeSpinBox->setToolTip("The range of the view starting at the offset");
    applyPushButton = new QPushButton();
        initializePushButton(applyPushButton, "Apply");
    layout = new QGridLayout();
        layout->addWidget(xOffsetLabel, 1, 1, 1, 1, Qt::AlignCenter);
        layout->addWidget(xOffsetSpinBox, 1, 2, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeLabel, 2, 1, 1, 1, Qt::AlignCenter);
        layout->addWidget(xRangeSpinBox, 2, 2, 1, 1, Qt::AlignCenter);
        layout->addWidget(applyPushButton, 3, 1, 1, 2, Qt::AlignCenter);
    this->setLayout(layout);

    connect(applyPushButton, SIGNAL (pressed()), this, SLOT(slotApplyPressed()));
}

void ScrollingViewTab::initializeLabel(QLabel * labelPtr, QString labelTitle)
{
    labelPtr->setText(labelTitle);
}

void ScrollingViewTab::initializeSpinBox(QSpinBox * spinBoxPtr, int max)
{
    spinBoxPtr->setMaximum(max);
}

void ScrollingViewTab::initializePushButton(QPushButton *pushButtonPtr, QString pushButtonTitle)
{
    pushButtonPtr->setText(pushButtonTitle);
}

int ScrollingViewTab::getOffset()
{
    return xOffsetSpinBox->value();
}

int ScrollingViewTab::getRange()
{
    return xRangeSpinBox->value();
}

void ScrollingViewTab::slotApplyPressed()
{
    emit signalApplyPressed();
}
