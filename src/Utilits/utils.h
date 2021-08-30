#pragma once

#include <QString>

class utils
{
public:
	static utils& get_instance();

public:
	QString toUtf8(QString str);

private:
	utils() {}
	~utils() {}
};