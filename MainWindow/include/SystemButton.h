#pragma once

#include "MainWindows_global.h"

class WidgetExitButton : public QPushButton
{
    Q_OBJECT

public:
    explicit WidgetExitButton(QWidget *parent = nullptr);
    ~WidgetExitButton();
};

class WidgetMinimizationButton : public QPushButton
{
    Q_OBJECT

public:
    explicit WidgetMinimizationButton(QWidget *parent = nullptr);
    ~WidgetMinimizationButton();
};