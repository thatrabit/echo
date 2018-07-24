#include "testecho.h"

void TestEcho:: initTestCase() {
    echo = new Echo;
}

void TestEcho::testAddPlayer() {
    echo->addPlayer("john");
}
