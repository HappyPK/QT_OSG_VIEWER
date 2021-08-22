#pragma once
#include "ui_testDialog.h"
#include <QDialog>
#include <QWidget>

class TestDialog:public QDialog
{
	Q_OBJECT
public:
	TestDialog(QWidget* parent = Q_NULLPTR);
	~TestDialog();

private:
	Ui::Dialog* ui;

private slots:
	void on_AcceptButton_clicked();
	void on_RejectButton_clicked();
	void on_DoneButton_clicked();
};