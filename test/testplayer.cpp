#include "testplayer.hpp"

void TestPlayer::initTestCase() {
    player = new Player;
}

void TestPlayer::testName() {
    QSignalSpy spy(player, SIGNAL(nameUpdated()));
    QFETCH(QString, name);
    QFETCH(QString, result_name);
    QFETCH(int, signal_count);
    player->updateName(name);
    QCOMPARE(player->name(), result_name);
    QCOMPARE(spy.count(), signal_count);
}

void TestPlayer::testName_data() {
    QTest::addColumn<QString>("name");
    QTest::addColumn<QString>("result_name");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("john") << "john" << "john" << 1;
    QTest::newRow("john") << "john" << "john" << 0;
    QTest::addRow("tom") << "tom" << "tom" << 1;
}

void TestPlayer::testPnl() {
    QSignalSpy spy(player, SIGNAL(pnlUpdated(qint64)));
    QFETCH(qint64, pnl);
    QFETCH(qint64, result_pnl);
    QFETCH(int, signal_count);
    player->updatePnl(pnl);
    QCOMPARE(player->pnl(), result_pnl);
    QCOMPARE(spy.count(), signal_count);
    if (spy.count() == 1) {
        QList<QVariant> arg = spy.takeFirst();
        QCOMPARE(arg.at(0).toLongLong(), result_pnl);
    }
}

void TestPlayer::testPnl_data() {
    QTest::addColumn<qint64>("pnl");
    QTest::addColumn<qint64>("result_pnl");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("pnl 42") << qint64(42) << qint64(42) << 1;
    QTest::newRow("pnl 42") << qint64(42) << qint64(42) << 0;
    QTest::newRow("pnl 420") << qint64(420) << qint64(420) << 1;
}
