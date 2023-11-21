#ifndef UNTITLED_GLOBAL_H
#define UNTITLED_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QWidget>
#include <QGuiApplication>
#include <QLineEdit>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPushButton>

#if defined(UNTITLED_LIBRARY)
#  define UNTITLED_EXPORT Q_DECL_EXPORT
#else
#  define UNTITLED_EXPORT Q_DECL_IMPORT
#endif

#endif // UNTITLED_GLOBAL_H
