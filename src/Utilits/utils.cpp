#include "utils.h"
#pragma execution_character_set("utf-8") 

utils& utils::get_instance()
{
	static utils instance;
	return instance;
}

QString utils::toUtf8(QString str)
{
	return str;
}