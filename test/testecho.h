#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/echo.h"

class TestEcho : public QObject {
    Q_OBJECT
private slots:
    void initTestCase();
    void testAddPlayer();
    void testAddPlayer_data();
private:
    Echo* echo;
};
