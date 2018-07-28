#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/agent.hpp"

class TestAgent : public QObject {
    Q_OBJECT
private:
    Agent* data;
private slots:
    void initTestCase();
};
