#include "testmarket.hpp"

void TestMarket::initTestCase() {
    market = new Market;
}

void TestMarket::testMic() {
    QSignalSpy spy(market, SIGNAL(micUpdated()));
    QFETCH(QString, mic);
    QFETCH(QString, result_mic);
    QFETCH(int, signal_count);
    market->updateMic(mic);
    QCOMPARE(market->mic(), result_mic);
    QCOMPARE(spy.count(), signal_count);
}

void TestMarket::testMic_data() {
    QTest::addColumn<QString>("mic");
    QTest::addColumn<QString>("result_mic");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("arcx") << "arcx" << "arcx" << 1;
    QTest::newRow("arcx") << "arcx" << "arcx" << 0;
    QTest::newRow("bato") << "bato" << "bato" << 1;
}

void TestMarket::testAddInstrument() {
    QSignalSpy spy(market, SIGNAL(instrumentAdded(QString, bool)));
    QFETCH(QString, symbol);
    QFETCH(QString, signal_arg_0);
    QFETCH(bool, signal_arg_1);
    Instrument* instrument = new Instrument(symbol);
    market->addInstrument(instrument);
    QList<QVariant> arg = spy.takeFirst();
    QCOMPARE(arg.at(0).toString(), signal_arg_0);
    QCOMPARE(arg.at(1).toBool(), signal_arg_1);
}

void TestMarket::testAddInstrument_data() {
    QTest::addColumn<QString>("symbol");
    QTest::addColumn<QString>("signal_arg_0");
    QTest::addColumn<bool>("signal_arg_1");
    QTest::newRow("aapl") << "aapl" << "aapl" << true;
    QTest::newRow("goog") << "goog" << "goog" << true;
    QTest::newRow("aapl") << "aapl" << "aapl" << false;
}
