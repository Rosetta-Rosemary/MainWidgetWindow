#define UNTITLED_LIBRARY

#include "MainToolWidget.h"
#include "ClassTool.hpp"
#include <QRegularExpressionValidator>


void MainToolWidget::InitMainWidget(const QWidget* pParent)
{
    int iPos_x = 0;
    int iPos_y = 0;
    int ix = 0;
    int iy = 0;
    GetMainWidgetGeometry(pParent, iPos_x, iPos_y, ix, iy);

    setFixedSize(ix, iy);
    setGeometry(iPos_x, iPos_y, ix, iy);
    this->setStyleSheet("background-color:#F0F8FF;border-radius:9px");
}

void MainToolWidget::paintEvent(QPaintEvent *event)
{
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}