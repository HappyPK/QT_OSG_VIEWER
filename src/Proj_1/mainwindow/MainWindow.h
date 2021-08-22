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

    void timeSlot();
    void showTime();

private slots:
    void on_moveWinButton_clicked();
    void on_getWinPosBtn_clicked();
    void on_setWinPosBtn_clicked();
    void on_ModeDialog_clicked();
    void on_msgBtn_clicked();
    void on_fileDialogBtn_clicked();

    void customContextMenuRequestedSlot(const QPoint& pos);
private:
    Ui::MainWindow *ui;
    QTimer* m_timer;

};
