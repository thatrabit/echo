#include "testamount.hpp"

void TestAmount::initTestCase() {
    amount = new Amount();
}

void TestAmount::testValue() {
    QSignalSpy spy(amount, SIGNAL(valueUpdated(qint64)));
    QFETCH(qint64, value);
    QFETCH(qint64, result_value);
    QFETCH(int, signal_count);
    amount->updateValue(value);
    QCOMPARE(amount->value(), result_value);
    QCOMPARE(spy.count(), signal_count);
    if (spy.count() == 1) {
        QList<QVariant> arg = spy.takeFirst();
        QCOMPARE(arg.at(0).toLongLong(), result_value);
    }
}

void TestAmount::testValue_data() {
    QTest::addColumn<qint64>("value");
    QTest::addColumn<qint64>("result_value");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("value 42") << qint64(42) << qint64(42) << 1;
    QTest::newRow("value 42") << qint64(42) << qint64(42) << 1;
    QTest::newRow("value 420") << qint64(42) << qint64(42) << 1;
}
