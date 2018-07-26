#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/order.hpp"

class TestOrder : public QObject {
    Q_OBJECT
private:
    Order* order;
private slots:
    void initTestCase();
    void testQuantity();
    void testQuantity_data();
};
