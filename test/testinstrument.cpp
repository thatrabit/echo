#include "testinstrument.hpp"

void TestInstrument::initTestCase() {
}

void TestInstrument::testSymbol() {
    QFETCH(QString, symbol);
    QFETCH(QString, result_symbol);
    data = new Instrument(symbol);
    QCOMPARE(data->symbol(), result_symbol);
}

void TestInstrument::testSymbol_data() {
    QTest::addColumn<QString>("symbol");
    QTest::addColumn<QString>("result_symbol");
    QTest::newRow("AAPL") << "AAPL" << "AAPL";
}
