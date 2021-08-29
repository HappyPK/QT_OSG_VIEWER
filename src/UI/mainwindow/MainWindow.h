#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

#include <Qtimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private slots:
    
private:
    void exitApp();

private:
    Ui::MainWindow *ui;
};
