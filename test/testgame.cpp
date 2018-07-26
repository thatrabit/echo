#include "testgame.hpp"

void TestGame::initTestCase() {
    game = new Game;
}

void TestGame::testAddPlayer() {
    QSignalSpy spy(game, SIGNAL(playerAdded(QString, bool)));
    QFETCH(QString, name);
    QFETCH(QString, signal_arg_0);
    QFETCH(bool, signal_arg_1);
    Player* player = new Player(name);
    game->addPlayer(player);
    QList<QVariant> arg = spy.takeFirst();
    QCOMPARE(arg.at(0).toString(), signal_arg_0);
    QCOMPARE(arg.at(1).toBool(), signal_arg_1);
}

void TestGame::testAddPlayer_data() {
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("signal_arg_0");
    QTest::addColumn<bool>("signal_arg_1");
    QTest::newRow("john") << "john" << "john" << true;
    QTest::newRow("tom") << "tom" << "tom" << true;
    QTest::newRow("john") << "john" << "john" << false;
}
