QT += gui quick quickcontrols2 remoteobjects
TEMPLATE = app
CONFIG += c++11 silent
TARGET = echo

include(echo.pri)

SOURCES += src/main.cpp

REPC_SOURCE += src/*.rep
REPC_REPLICA += src/*.rep

RESOURCES += src/qml.qrc
