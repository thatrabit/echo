#include <QtTest/QTest>

#include "testamount.hpp"
#include "testinstrument.hpp"
#include "testorder.hpp"
#include "testplayer.hpp"
#include "testmarket.hpp"
#include "testagent.hpp"
#include "testgame.hpp"

int main(int argc, char** argv) {
    int status = 0;
    auto run = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    run(new TestAmount);
    run(new TestInstrument);
    run(new TestOrder);
    run(new TestPlayer);
    run(new TestMarket);
    run(new TestAgent);
    run(new TestGame);

    return status;
}
