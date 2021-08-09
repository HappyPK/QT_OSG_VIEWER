#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_my_qt.h"

class Project_1 : public QMainWindow
{
    Q_OBJECT

public:
    Project_1(QWidget *parent = Q_NULLPTR);

private:
    Ui::myQtClass ui;
};
