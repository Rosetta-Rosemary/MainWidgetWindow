#define UNTITLED_LIBRARY

#include "MainToolWidget.h"
#include "ClassTool.hpp"


MainToolWidget::MainToolWidget(QWidget* parent)
    : QWidget(parent)
{
    Init(parent);
}

MainToolWidget::~MainToolWidget()
{

}

void MainToolWidget::Init(const QWidget* pParent)
{
    InitMainWidget(pParent);
}
