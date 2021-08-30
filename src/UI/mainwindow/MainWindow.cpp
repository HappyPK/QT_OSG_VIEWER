#include "MainWindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), pUi(std::make_unique<Ui::MainWindow>())
{
    pUi->setupUi(this);
    connect(pUi->actionexit, &QAction::triggered, this, &MainWindow::exitApp);
    connect(pUi->actionopen, &QAction::triggered, this, &MainWindow::openFile);
}

MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString filedir = QFileDialog::getExistingDirectory(nullptr, "��", "./");
    QMessageBox::information(nullptr, "���ļ���",filedir,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
}

void MainWindow::exitApp()
{
    close();
}
