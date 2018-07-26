#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "lib/player.hpp"

class TestPlayer : public QObject {
    Q_OBJECT
private:
    Player* player;
private slots:
    void initTestCase();
    void testName();
    void testName_data();
    void testPnl();
    void testPnl_data();
};
