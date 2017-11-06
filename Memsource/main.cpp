#include "ProjectListWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	ProjectListWindow w;
	w.show();
	return a.exec();
}
