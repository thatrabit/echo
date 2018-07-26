#include <QtTest/QTest>
#include <QtTest/QSignalSpy>

#include "src/game.hpp"

class TestGame : public QObject {
    Q_OBJECT
private:
    Game* game;
private slots:
    void initTestCase();
    void testAddPlayer();
    void testAddPlayer_data();
};
