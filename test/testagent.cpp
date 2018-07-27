#include "testagent.hpp"

void TestAgent::initTestCase() {
    agent = new Agent;
}

void TestAgent::testId() {
    QSignalSpy spy(agent, SIGNAL(idUpdated()));
    QFETCH(QString, id);
    QFETCH(QString, result_id);
    QFETCH(int, signal_count);
    agent->updateId(id);
    QCOMPARE(agent->id(), result_id);
    QCOMPARE(spy.count(), signal_count);
}

void TestAgent::testId_data() {
    QTest::addColumn<QString>("id");
    QTest::addColumn<QString>("result_id");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("trader0") << "trader0" << "trader0" << 1;
    QTest::newRow("trader0") << "trader0" << "trader0" << 0;
    QTest::newRow("trader1") << "trader1" << "trader1" << 1;
}

void TestAgent::testStartStop() {
    agent->stop();
    QSignalSpy spy(agent, SIGNAL(activated(bool)));
    QFETCH(bool, toggle_0);
    QFETCH(bool, toggle_1);
    QFETCH(bool, result_isActive);
    QFETCH(int, signal_count);
    if (toggle_0 == false and toggle_1 == false) {
        agent->stop();
        agent->stop();
    } else if (toggle_0 == false and toggle_1 == true) {
        agent->stop();
        agent->start();
    } else if (toggle_0 == true and toggle_1 == false) {
        agent->start();
        agent->stop();
    } else if (toggle_0 == true and toggle_1 == true) {
        agent->start();
        agent->start();
    }
    QCOMPARE(agent->isActive(), result_isActive);
    QCOMPARE(spy.count(), signal_count);
    switch (signal_count) {
        case 0:
            break;
        case 1: {
            QList<QVariant> arg = spy.takeFirst();
            QCOMPARE(arg.at(0).toBool(), toggle_1);
            break;
        }
        case 2: {
            QList<QVariant> arg = spy.takeFirst();
            QCOMPARE(arg.at(0).toBool(), toggle_0);
            arg = spy.takeFirst();
            QCOMPARE(arg.at(0).toBool(), toggle_1);
            break;
        }
        default:
            break;
    }
}

void TestAgent::testStartStop_data() {
    QTest::addColumn<bool>("toggle_0");
    QTest::addColumn<bool>("toggle_1");
    QTest::addColumn<bool>("result_isActive");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("off off") << false << false << false << 0;
    QTest::newRow("off on") << false << true << true << 1;
    QTest::newRow("on off") << true << false << false << 2;
    QTest::newRow("on on") << true << true << true << 1;
}

void TestAgent::testAddOrder_slot() {
    QSignalSpy spy(agent, SIGNAL(orderReceived(QString, qint64)));
    QFETCH(QString, symbol);
    QFETCH(qint64, quantity);
    agent->addOrder_slot(symbol, quantity);
    QList<QVariant> arg = spy.takeFirst();
    QCOMPARE(arg.at(0).toString(), symbol);
    QCOMPARE(arg.at(1).toLongLong(), quantity);
}

void TestAgent::testAddOrder_slot_data() {
    QTest::addColumn<QString>("symbol");
    QTest::addColumn<qint64>("quantity");
    QTest::newRow("aapl 42") << "aapl" << qint64(42);
    QTest::newRow("goog 420") << "goog" << qint64(420);
}
