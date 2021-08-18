#ifndef TEST_WINDOWS_1
#define TEST_WINDOWS_1
#include <QObject>
class testWindow : public QObject
{
	Q_OBJECT
public:
	explicit testWindow(QObject* parent = nullptr);

signals:
	void hungry();
	void hungry(QString msg);
};


#endif // !TEST_WINDOWS_1
