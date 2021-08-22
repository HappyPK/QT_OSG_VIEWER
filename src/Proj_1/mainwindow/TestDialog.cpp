#include "TestDialog.h"

TestDialog::TestDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //connect(ui->AcceptButton,&QPushButton::clicked,this,&TestDialog::on_AcceptButton_clicked);
    //connect(ui->RejectButton, &QPushButton::clicked, this, &TestDialog::on_RejectButton_clicked);
    //connect(ui->DoneButton, &QPushButton::clicked, this, &TestDialog::on_DoneButton_clicked);
}

TestDialog::~TestDialog()
{
    delete ui;
}

void TestDialog::on_AcceptButton_clicked()
{
    this->accept();
}

void TestDialog::on_RejectButton_clicked()
{
    this->reject();
}

void TestDialog::on_DoneButton_clicked()
{
    this->done(10);
}

