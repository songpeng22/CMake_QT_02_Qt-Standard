#include "mainwindow.h"
#include <QApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

int main(int argc, char *argv[])
{
#if 0
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	QQmlApplicationEngine engine;
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
#else
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
#endif
}
