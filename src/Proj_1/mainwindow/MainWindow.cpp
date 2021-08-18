#include "MainWindow.h"
#include <Qdebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    m_timer = new QTimer(this);
    if(0)
    {
        m_me = new Me();
        m_girlfriend = new testWindow();

        void (testWindow:: * girl1)() = &testWindow::hungry;
        void (testWindow:: * girl2)(QString) = &testWindow::hungry;

        void (Me:: * eat2)(QString) = &Me::eat;
        void (Me:: * eat1)() = &Me::eat;

        connect(m_girlfriend, girl1, m_me, eat1);
        connect(m_girlfriend, girl2, m_me, eat2);
        connect(m_girlfriend, girl2, this, &MainWindow::eatSlot);
        connect(ui->hungryButton, &QPushButton::clicked, this, &MainWindow::hungrySlot);
    }

    
    connect(ui->loopBtn, &QPushButton::clicked,this ,&MainWindow::timeSlot );

    connect(ui->closeMainWindow, &QPushButton::clicked, this, &QMainWindow::close);
    connect(m_timer, &QTimer::timeout, this, [&](){
        QTime time = QTime::currentTime();
        QString strTime = time.toString(QString::fromLocal8Bit("hh:mm:ss.zzz"));
        ui->curTime->setText(strTime);
        });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeSlot()
{
    if (m_timer->isActive())
    {
        m_timer->stop();
        ui->loopBtn->setText(QString::fromLocal8Bit("¿ªÊ¼"));
    }
    else
    {
        ui->loopBtn->setText(QString::fromLocal8Bit("¹Ø±Õ"));
        m_timer->start(1);
    }
}


void MainWindow::hungrySlot()
{
    qDebug() << "MainWindow::hungrySlot()";
    emit m_girlfriend->hungry();
    emit m_girlfriend->hungry("MainWindow::hungrySlot() -> m_girlfriend->hungry");
}

void MainWindow::eatSlot()
{
    QString outstr = QString::fromLocal8Bit("MainWindow::eatSlot()");
    qDebug() << outstr;
}
