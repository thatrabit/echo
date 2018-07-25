#include <QtTest/QTest>

#include "testplayer.hpp"
#include "testecho.hpp"

int main(int argc, char** argv) {
    int status = 0;
    auto run = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    run(new TestPlayer);
    run(new TestEcho);

    return status;
}
