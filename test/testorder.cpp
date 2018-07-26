#include "testorder.hpp"

void TestOrder::initTestCase() {
    order = new Order;
}

void TestOrder::testQuantity() {
    QSignalSpy spy(order, SIGNAL(quantityUpdated(qint64)));
    QFETCH(qint64, quantity);
    QFETCH(qint64, result_quantity);
    QFETCH(int, signal_count);
    order->updateQuantity(quantity);
    QCOMPARE(order->quantity(), result_quantity);
    QCOMPARE(spy.count(), signal_count);
    if (spy.count() == 1) {
        QList<QVariant> arg = spy.takeFirst();
        QCOMPARE(arg.at(0).toLongLong(), result_quantity);
    }
}

void TestOrder::testQuantity_data() {
    QTest::addColumn<qint64>("quantity");
    QTest::addColumn<qint64>("result_quantity");
    QTest::addColumn<int>("signal_count");
    QTest::newRow("quantity 42") << qint64(42) << qint64(42) << 1;
    QTest::newRow("quantity 42") << qint64(42) << qint64(42) << 0;
    QTest::newRow("quantity 420") << qint64(420) << qint64(420) << 1;
}
