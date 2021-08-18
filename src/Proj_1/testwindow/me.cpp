#include "me.h"
#include <Qdebug>

Me::Me(QObject* parent):QObject(parent)
{

}

void Me::eat()
{
	QString outstr = QString::fromLocal8Bit("Me::eat()");
	qDebug() << outstr;
}

void Me::eat(QString msg)
{
	QString outstr = QString::fromLocal8Bit(msg.toStdString().c_str());
	qDebug() << outstr;
}