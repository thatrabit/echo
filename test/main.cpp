#include <QtTest/QTest>

#include "testinstrument.hpp"
#include "testagent.hpp"
#include "testecho.hpp"

int main(int argc, char** argv) {
    int status = 0;
    auto run = [&status, argc, argv](QObject* obj) {
        status |= QTest::qExec(obj, argc, argv);
    };

    run(new TestInstrument);
    run(new TestAgent);
    run(new TestEcho);

    return status;
}
