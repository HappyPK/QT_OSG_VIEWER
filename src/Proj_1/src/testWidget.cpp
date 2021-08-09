#include "testWidget.h"

testWidget::testWidget(QWidget* parent)
    : QWidget(parent),ui(new Ui::testWidget)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    connect(ui->closeButton,&QPushButton::clicked,this,&QWidget::close); 
}

testWidget::~testWidget()
{
    delete ui;
}