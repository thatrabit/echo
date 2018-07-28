QT += testlib remoteobjects
TEMPLATE = app
CONFIG += c++11 silent testcase
TARGET = echo_test

include(echo.pri)
include(echo_test.pri)

SOURCES += test/main.cpp

REPC_SOURCE += src/*.rep
REPC_REPLICA += src/*.rep

RESOURCES += src/qml.qrc
