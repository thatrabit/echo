#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/echo.hpp"

class TestEcho : public QObject {
    Q_OBJECT
private:
    Echo* data;
private slots:
    void initTestCase();
};
