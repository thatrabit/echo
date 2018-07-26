#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "lib/amount.hpp"

class TestAmount : public QObject {
    Q_OBJECT
private:
    Amount* amount;
private slots:
    void initTestCase();
    void testValue();
    void testValue_data();
};
