QT -= gui
QT += remoteobjects
TEMPLATE = app
CONFIG += c++11 silent
HEADERS += src/*.hpp
SOURCES += src/*.cpp
REPC_SOURCE += src/*.rep
REPC_REPLICA += src/*.rep

QT += testlib
TARGET = echo_test
HEADERS += test/*.hpp
SOURCES += test/*.cpp
CONFIG += testcase
