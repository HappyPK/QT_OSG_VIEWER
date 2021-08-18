#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "testWindow.h"
#include "me.h"

#include <Qtimer>
#include <Qtime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

    void hungrySlot();

    void eatSlot();

    void timeSlot();

private:
    Ui::MainWindow *ui;
    Me* m_me;
    testWindow* m_girlfriend;
    QTimer* m_timer;

};
