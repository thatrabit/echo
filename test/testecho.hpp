#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "lib/echo.hpp"

class TestEcho : public QObject {
    Q_OBJECT
private:
    Echo* echo;
private slots:
    void initTestCase();
    void testAddPlayer();
    void testAddPlayer_data();
};
