QT -= gui
QT += remoteobjects
CONFIG += c++11 silent
HEADERS += lib/*.hpp
SOURCES += lib/*.cpp

test {
    TEMPLATE = app
    TARGET = echo_test
    QT += testlib
    CONFIG += testcase
    HEADERS += test/*.hpp
    SOURCES += test/*.cpp
} else {
    DEFINES += ECHO_LIBRARY
    TEMPLATE = lib
    TARGET = echo
}

gui {
    DEFINES -= ECHO_LIBRARY
    TEMPLATE = app
    TARGET = echo_gui
    QT += gui quick quickcontrols2
    HEADERS += gui/*.hpp
    SOURCES += gui/*.cpp
    RESOURCES += gui/qml.qrc
}
