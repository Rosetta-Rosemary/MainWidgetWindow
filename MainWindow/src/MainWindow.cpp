#define UNTITLED_LIBRARY

#include "MainWindow.h"
#include "MainToolWidget.h"
#include "ClassTool.hpp"
#include <iostream>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    setFixedSize(800,600);
    this->setStyleSheet("background-color:#DCDCDC;border-radius:12px");
    Init();
}

MainWindow::~MainWindow()
{
    m_Exit->deleteLater();
    m_Minimization->deleteLater();
    m_Main->deleteLater();
}

void MainWindow::Init()
{
    mouse_press_to_mov = false;
    mouse_press_to_resize = false;
    m_Exit = new WidgetExitButton(this);
    m_Minimization = new WidgetMinimizationButton(this);

    connect(m_Exit,         &QPushButton::clicked, this,   [=](){this->close();});
    connect(m_Minimization, &QPushButton::clicked, this,   [=](){this->showMinimized();});

    m_Main = new MainToolWidget(this);
    m_Main->raise();
    m_Main->raise();
    m_Main->show();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    //绘制样式
    QStyleOption opt;
    opt.initFrom(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);//绘制样式
 
    QBitmap bmp(this->size());
    bmp.fill();
    QPainter painter(&bmp);
 
    painter.setPen(Qt::NoPen);
    painter.setBrush(Qt::black);
    painter.setRenderHint(QPainter::Antialiasing);
    //设置边框为圆角12px
    painter.drawRoundedRect(bmp.rect(), 12, 12);
    setMask(bmp);
    QWidget::paintEvent(event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
 
    if( (event->button() == Qt::LeftButton))
    {
        QPoint pos = event->pos();
        int PosX = pos.x();
        int PosY = pos.y();
        if (PosY >=0 && PosY <= 27)
        {
            std::cout << "mouse_press_to_mov Event" << std::endl;
            mouse_press_to_mov = true;
            mousePoint = event->globalPos() - this->pos();
        } 
        // event->accept();
        if ((PosX >= (this->width() - 30) && PosX <= (this->width()))
        && (PosY >= (this->height() - 30) && PosY <= (this->height())))
        {
            std::cout << "mouse_press_to_resize Event" << std::endl;
            mouse_press_to_resize = true;
            mousePoint = event->globalPos() - this->pos();
        }
    }
}
void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if(mouse_press_to_mov)
    {
        move(event->globalPos() - mousePoint);
    }
    if (mouse_press_to_resize)
    {
        ResizeWidget(event->globalPos());
    }
}
void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    mouse_press_to_mov = false;
    mouse_press_to_resize = false;
}

void MainWindow::ResizeWidget(const QPoint &NewEndPos)
{
    // ResizeWidget
    int iWidth = NewEndPos.x() - this->x();
    int iHight = NewEndPos.y() - this->y();
    if (iWidth >= 400 || iHight >= 300)
    {
        if (iWidth <= 400)
        {
            iWidth = 400;
        }
        if (iHight <= 300)
        {
            iHight = 300;
        }

        std::cout << "mouse_press_to_resize Event [" << iWidth << "] [" << iHight << "]"<< std::endl;
        setFixedSize(iWidth, iHight);

        int iPos_x = 0;
        int iPos_y = 0;
        int ix = 0;
        int iy = 0;
        GetMainWidgetGeometry(this, iPos_x, iPos_y, ix, iy);
        std::cout << "GetMainWidgetGeometry[" << iWidth << "] [" << iHight << "]"<< std::endl;
        m_Main->setFixedSize(ix, iy);
        m_Main->setGeometry(iPos_x, iPos_y, ix, iy);  

        GetExitButtonPos(this, iPos_x, iPos_y);
        m_Exit->setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);

        GetMinButtonPos(this, iPos_x, iPos_y);
        m_Minimization -> setGeometry(iPos_x, iPos_y, SYSTEMBUTTONSIZE, SYSTEMBUTTONSIZE);
    }
}
