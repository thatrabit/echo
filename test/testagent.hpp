#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/agent.hpp"

class TestAgent : public QObject {
    Q_OBJECT
private:
    Agent* agent;
private slots:
    void initTestCase();
    void testId();
    void testId_data();
    void testStartStop();
    void testStartStop_data();
    void testAddOrder_slot();
    void testAddOrder_slot_data();
};
