#ifndef TEST_WINDOWS_2
#define TEST_WINDOWS_2
#include <QObject>
class Me : public QObject
{
	Q_OBJECT
public:
	explicit Me(QObject* parent = nullptr);

public:
	void eat(); 
	void eat(QString msg);
};


#endif // !TEST_WINDOWS_1
