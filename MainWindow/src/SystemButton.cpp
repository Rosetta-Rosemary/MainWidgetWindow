#define UNTITLED_LIBRARY

#include "SystemButton.h"
#include "ClassTool.hpp"

WidgetExitButton::WidgetExitButton(QWidget *parent) : QPushButton(parent)
{
    this -> raise();
    int iPos_x;
    int iPos_y;
    GetExitButtonPos(parent, iPos_x, iPos_y);
    this -> setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);
    // 设置按钮初始样式
    this->setStyleSheet("QPushButton{"
                "color:#FF6347;background-color:#FF6347;border-style:outset;"
                "border-width:2px;border-color:#FF4500;border-radius:11px;padding:4px;}"
                "QPushButton:hover{"
                "color:#FF0000;background-color:#FF0000;border-style:outset;"
                "border-width:2px;border-color:#FF4500;border-radius:11px;padding:4px;}"
                "QPushButton:checked{"
                "color:#F08080;background-color:#F08080;border-style:outset;"
                "border-width:2px;border-color:#FF4500;border-radius:11px;padding:4px;}");
    
    QPixmap closePix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);

    this->setIcon(closePix);
    this->setToolTip(tr("CLOSE"));
    this->setIconSize(QSize(20,20));
    this->show();
}
 
WidgetExitButton::~WidgetExitButton()
{
    
}

WidgetMinimizationButton::WidgetMinimizationButton(QWidget *parent) : QPushButton(parent)
{
    this -> raise();
    int iPos_x;
    int iPos_y;
    GetMinButtonPos(parent, iPos_x, iPos_y);
    this -> setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);

    // 设置按钮初始样式
    this->setStyleSheet("QPushButton{"
                "color:#BEBEBE;background-color:#BEBEBE;border-style:outset;"
                "border-width:2px;border-color:#D3D3D3;border-radius:11px;padding:4px;}"
                "QPushButton:hover{"
                "color:#778899;background-color:#778899;border-style:outset;"
                "border-width:2px;border-color:#D3D3D3;border-radius:11px;padding:4px;}"
                "QPushButton:checked{"
                "color:#696969;background-color:#696969;border-style:outset;"
                "border-width:2px;border-color:#D3D3D3;border-radius:11px;padding:4px;}");
    QPixmap MinPix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);

    this->setIcon(MinPix);
    this->setToolTip(tr("Min"));
    this->setIconSize(QSize(20,20));
    this->show();
}
 
WidgetMinimizationButton::~WidgetMinimizationButton()
{
    
}