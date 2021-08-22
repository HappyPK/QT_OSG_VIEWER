#include "MainWindow.h"
#include <Qdebug>
#include <QTime>
#include <QMessageBox>
#include <QFileDialog>
#include "TestDialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->closeMainWindow, &QPushButton::clicked, this, &QMainWindow::close);
    /*--------��ʱ��---------*/
    m_timer = new QTimer();
    connect(ui->loopBtn, &QPushButton::clicked,this ,&MainWindow::timeSlot );
    connect(m_timer, &QTimer::timeout, this, &MainWindow::showTime);

    /*--------���ô���---------*/
    //setMaximumSize(600, 600);
    //setMinimumSize(200, 200);
    //setFixedSize(500,500);
    setWindowTitle(QString::fromLocal8Bit("��ã�qt"));
    setWindowIcon(QIcon("../../../../res/1.jpeg"));

    /*-----------�Ҽ��˵�-----------*/
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this,&MainWindow::customContextMenuRequested,this,&MainWindow::customContextMenuRequestedSlot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::customContextMenuRequestedSlot(const QPoint &pos)
{
    QMenu menu;
    menu.addAction(QString::fromLocal8Bit("������"));
    menu.addAction(QString::fromLocal8Bit("�ƹ�"));
    menu.addAction(QString::fromLocal8Bit("����"));
    menu.exec(QCursor::pos());
}

void MainWindow::timeSlot()
{
    if (m_timer->isActive())
    {
        m_timer->stop();
        ui->loopBtn->setText(QString::fromLocal8Bit("��ʼ"));
    }
    else
    {
        ui->loopBtn->setText(QString::fromLocal8Bit("�ر�"));
        m_timer->start(1);
    }
}

void MainWindow::showTime()
{
    QTime time = QTime::currentTime();
    QString strTime = time.toString(QString::fromLocal8Bit("hh:mm:ss.zzz"));
    ui->curTime->setText(strTime);
}

void MainWindow::on_moveWinButton_clicked()
{
    QRect rect = this->frameGeometry();

    move(rect.topLeft() + QPoint(10, 50));
}

void MainWindow::on_getWinPosBtn_clicked()
{
    QRect rect = this->frameGeometry();
    qDebug() << QString::fromLocal8Bit("���Ͻǣ� ") << rect.topLeft()
        << QString::fromLocal8Bit("���½ǣ� ") << rect.bottomRight()
        << QString::fromLocal8Bit("��ȣ� ") << rect.width()
        << QString::fromLocal8Bit("�߶ȣ� ") << rect.height();
}

void MainWindow::on_setWinPosBtn_clicked()
{
    int x = 100 + rand() % 500;
    int y = 100 + rand() % 500;
    int w = this->width() + 10;
    int h = this->height() + 10;
    setGeometry(x, y, w, h);
}

void MainWindow::on_ModeDialog_clicked()
{
    TestDialog testDialog;
    auto ret = testDialog.exec();
    if (ret == QDialog::Accepted)
    {
        qDebug() << "accept button clicked......";
    }
    else if (ret == QDialog::Rejected)
    {
        qDebug() << "rejected button clicked......";
    }
    else
    {
        qDebug() << "done button clicked......";
    }
}

void MainWindow::on_msgBtn_clicked()
{
    QMessageBox::about(this, "about", QString::fromLocal8Bit("����һ��������Ϣ��ʾ�򣡣�"));
    QMessageBox::critical(this, "Error", QString::fromLocal8Bit("������ʾ��"));
    int ret = QMessageBox::question(this, QString::fromLocal8Bit("����"),
        QString::fromLocal8Bit("�Ƿ񱣴��ļ���"), QMessageBox::Save | QMessageBox::Cancel,
        QMessageBox::Cancel);
    if (ret == QMessageBox::Save)
    {
        QMessageBox::information(this,"information", QString::fromLocal8Bit("�ɹ����棡��"));
    }
    else if (ret == QMessageBox::Cancel)
    {
        QMessageBox::information(this, "warning", QString::fromLocal8Bit("�������棡��"));
    }
}

void MainWindow::on_fileDialogBtn_clicked()
{
    QString dirName = QFileDialog::getExistingDirectory(this, QString::fromLocal8Bit("Ŀ¼"),"../../../../");
    QMessageBox::information
    (
        this, 
        QString::fromLocal8Bit("��Ŀ¼"),
        QString::fromLocal8Bit("ѡ���Ŀ¼�ǣ�") + dirName
    );

    QString arg("text files (*.cpp)");
    QString fileName = QFileDialog::getOpenFileName
    (
        this,
        tr("Open File"),
        "../../../../",
        tr("Images (*.jpeg);;Text files (*.cpp *.h)"),
        &arg  
    ); 
    QMessageBox::information
    (
        this,
        QString::fromLocal8Bit("���ļ�"),
        QString::fromLocal8Bit("ѡ����ļ��ǣ�") + fileName
    );
}



