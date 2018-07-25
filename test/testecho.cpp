#include "testecho.hpp"

void TestEcho:: initTestCase() {
    echo = new Echo;
}

void TestEcho::testAddPlayer() {
    QSignalSpy spy(echo, SIGNAL(playerAdded(QString, bool)));
    QFETCH(QString, name);
    QFETCH(QString, signal_arg_0);
    QFETCH(bool, signal_arg_1);
    echo -> addPlayer(name);
    QList<QVariant> arg = spy.takeFirst();
    QCOMPARE(arg.at(0).toString(), signal_arg_0);
    QCOMPARE(arg.at(1).toBool(), signal_arg_1);
}

void TestEcho::testAddPlayer_data() {
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("signal_arg_0");
    QTest::addColumn<bool>("signal_arg_1");
    QTest::newRow("john") << "john" << "john" << true;
    QTest::newRow("tom") << "tom" << "tom" << true;
    QTest::newRow("john") << "john" << "john" << false;
}
