#include "testplayer.h"

void TestPlayer::initTestCase() {
    player = new Player;
    player_with_name = new Player("john");
}

void TestPlayer::testName() {
    QSignalSpy spy(player, SIGNAL(nameUpdated()));
    player->updateName("john");
    QVERIFY(player->name() == "john");
    QCOMPARE(spy.count(), 1);
    QVERIFY(player_with_name->name() == "john");
}

void TestPlayer::testPnl() {
    QSignalSpy spy(player, SIGNAL(pnlUpdated(qint64)));
    player->updatePnl(42);
    QVERIFY(player->pnl() == 42);
    QCOMPARE(spy.count(), 1);
    QList<QVariant> arg = spy.takeFirst();
    QVERIFY(arg.at(0).toInt() == 42);
}
