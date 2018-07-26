QT -= gui
TEMPLATE = app
CONFIG += c++11 silent
HEADERS += src/*.hpp
SOURCES += src/*.cpp

QT += testlib
TARGET = echo_test
HEADERS += test/*.hpp
SOURCES += test/*.cpp
CONFIG += testcase
