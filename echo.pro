QT -= gui

CONFIG += c++11 silent

HEADERS += \
    src/*.hpp \

SOURCES += \
    src/*.cpp \

test {
    TEMPLATE = app
    TARGET = echo_test
    QT += testlib
    CONFIG += testcase

    HEADERS += \
        test/*.hpp

    SOURCES += \
        test/*.cpp
} else {
    DEFINES += ECHO_LIBRARY
    TEMPLATE = lib
    TARGET = echo
}
