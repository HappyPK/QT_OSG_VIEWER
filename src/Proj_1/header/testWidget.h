#pragma once

#include <qwidget.h>
#include "ui_testwidget.h"

class testWidget : public QWidget
{
    Q_OBJECT

public:
    testWidget(QWidget* parent = Q_NULLPTR);
    ~testWidget();
private:
    Ui::testWidget *ui;
};
