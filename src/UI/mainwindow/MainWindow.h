#pragma once
#pragma execution_character_set("utf-8") 

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include "utils.h"
#include <Qdebug>
#include <QTime>
#include <QTimer>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QProgressbar>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private slots:
    
private:
    void exitApp();
    void openFile();

private:
    std::unique_ptr<Ui::MainWindow> pUi;
};
