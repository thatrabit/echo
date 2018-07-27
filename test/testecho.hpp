#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/echo.hpp"

class TestEcho : public QObject {
private:
    Echo* echo;
private slots:
    void initTestCase();
    void testAgentId();
    void testAgentId_data();
    void testOnOrderReceived();
    void testOnOrderReceived_data();
    void testOnAgentActivated();
    void testOnAgentActivated_data();
};
