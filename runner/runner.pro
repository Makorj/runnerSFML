TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

SOURCES += main.cpp \
    Model.cpp \
    View.cpp \
    balle.cpp \
    character.cpp \
    graphicelement.cpp \
    slidingbackground.cpp
LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Model.h \
    View.h \
    balle.h \
    character.h \
    graphicelement.h \
    slidingbackground.h

