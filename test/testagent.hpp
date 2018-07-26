#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/agent.hpp"

class TestAgent : public QObject {
    Q_OBJECT
private:
    Agent* agent;
private slots:
    void initTestCase();
};
