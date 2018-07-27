QT -= gui
QT += remoteobjects
TEMPLATE = app
CONFIG += c++11 silent
HEADERS += src/*.hpp
SOURCES += src/*.cpp
REPC_SOURCE += src/*.rep
REPC_REPLICA += src/*.rep

QT += gui quick quickcontrols2
TARGET = echo_app
HEADERS += app/*.hpp
SOURCES += app/*.cpp
RESOURCES += app/qml.qrc
