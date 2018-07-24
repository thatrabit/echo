#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/player.h"

class TestPlayer : public QObject {
    Q_OBJECT
private slots:
    void initTestCase();
    void testName();
    void testPnl();
private:
    Player* player;
    Player* player_with_name;
};
