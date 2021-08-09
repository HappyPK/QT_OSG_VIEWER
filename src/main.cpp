#include <QtWidgets/QApplication>
#include <QtWidgets/qlabel.h>
#include "project_1.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);
	Project_1 w;
	w.show();
	return app.exec();
}