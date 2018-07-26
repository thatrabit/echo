#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "lib/market.hpp"

class TestMarket : public QObject {
    Q_OBJECT
private:
    Market* market;
private slots:
    void initTestCase();
    void testMic();
    void testMic_data();
    void testAddInstrument();
    void testAddInstrument_data();
};
