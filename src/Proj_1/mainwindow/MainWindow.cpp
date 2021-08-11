#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    connect(ui->closeMainWindow, &QPushButton::clicked, this, &QMainWindow::close);
}

MainWindow::~MainWindow()
{
    delete ui;
}
