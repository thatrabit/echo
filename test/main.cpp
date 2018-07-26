#include <QtTest/QTest>

#include "testamount.hpp"
#include "testplayer.hpp"
#include "testinstrument.hpp"
#include "testmarket.hpp"
#include "testgame.hpp"
#include "testecho.hpp"

int main(int argc, char** argv) {
    int status = 0;
    auto run = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    run(new TestAmount);
    run(new TestPlayer);
    run(new TestInstrument);
    run(new TestMarket);
    run(new TestGame);
    run(new TestEcho);

    return status;
}
