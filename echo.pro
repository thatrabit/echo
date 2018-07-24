QT -= gui

CONFIG += c++11

HEADERS += \
    src/*.h \

SOURCES += \
    src/*.cpp \

test {
    TEMPLATE = app
    TARGET = echo_test
    QT += testlib
    CONFIG += testcase

    HEADERS += \
        test/*.h

    SOURCES += \
        test/*.cpp
} else {
    DEFINES += ECHO_LIBRARY
    TEMPLATE = lib
    TARGET = echo
}
