#include "testinstrument.hpp"

void TestInstrument::initTestCase() {
    instrument = new Instrument;
}

void TestInstrument::testSymbol() {
    QSignalSpy spy(instrument, SIGNAL(symbolUpdated()));
    QFETCH(QString, symbol);
    QFETCH(QString, result_symbol);
    QFETCH(int, signal_count);
    instrument->updateSymbol(symbol);
    QCOMPARE(instrument->symbol(), result_symbol);
    QCOMPARE(spy.count(), signal_count);
}

void TestInstrument::testSymbol_data() {
    QTest::addColumn<QString>("symbol");
    QTest::addColumn<QString>("result_symbol");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("aapl") << "aapl" << "aapl" << 1;
    QTest::newRow("aapl") << "aapl" << "aapl" << 0;
    QTest::newRow("goog") << "goog" << "goog" << 1;
}
