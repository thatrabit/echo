#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/instrument.hpp"

class TestInstrument : public QObject {
    Q_OBJECT
private:
    Instrument* instrument;
private slots:
    void initTestCase();
    void testSymbol();
    void testSymbol_data();
};
