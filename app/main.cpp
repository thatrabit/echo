#include <QtGui/QGuiApplication>
#include <QtQml/QQmlApplicationEngine>

#include "src/echo.hpp"

int main(int argc, char** argv) {
    QGuiApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    qmlRegisterType<Echo>("Echo.Echo", 0, 1, "Echo");
    engine.load(QUrl(QStringLiteral("qrc:/MainWindow.qml")));
    return app.exec();
}
