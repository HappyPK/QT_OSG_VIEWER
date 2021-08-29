#include "MainWindow.h"
#include <Qdebug>
#include <QTime>
#include <QAction>
#include <QMessageBox>
#include <QFileDialog>
#include <QProgressbar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->actionexit, &QAction::triggered, this, &MainWindow::exitApp);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::exitApp()
{
    close();
}
