#pragma once

#include "MainWindows_global.h"

class MainToolWidget : public QWidget 
{
    Q_OBJECT

public:
    MainToolWidget(QWidget* parent = nullptr);
    void paintEvent(QPaintEvent *event);
    ~MainToolWidget();

private:
    void Init(const QWidget* pParent);

    void InitMainWidget(const QWidget* pParent);

private:

};