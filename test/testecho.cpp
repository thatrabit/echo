#include "testecho.h"

void TestEcho:: initTestCase() {
    echo = new Echo;
}

void TestEcho::testAddPlayer() {
    QSignalSpy spy(echo, SIGNAL(playerAdded(QString, bool)));
    echo->addPlayer("john");
    QCOMPARE(spy.count(), 1);
    QList<QVariant> arg = spy.takeFirst();
    QVERIFY(arg.at(0).toString() == "john");
    QVERIFY(arg.at(1).toBool() == true);
}
