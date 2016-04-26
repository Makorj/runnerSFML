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
    slidingbackground.cpp \
    animatedgraphicelement.cpp \
    obstacle.cpp \
    movableelement.cpp \
    TU/TU_ball.cpp \
    bonus.cpp \
    clock.cpp \
    menu.cpp \
    heal.cpp \
    splashscreen.cpp \
    coin.cpp \
    invicibility.cpp \
    doublejump.cpp \
    scoremultiplier.cpp
LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system


include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Model.h \
    View.h \
    balle.h \
    character.h \
    graphicelement.h \
    slidingbackground.h \
    animatedgraphicelement.h \
    obstacle.h \
    movableelement.h \
    bonus.h \
    clock.h \
    menu.h \
    heal.h \
    splashscreen.h \
    coin.h \
    invicibility.h \
    doublejump.h \
    scoremultiplier.h

OTHER_FILES += \
    ../Images/flocon.png \
    ../Images/iceblock.png \
    ../Images/iceclimber.png \
    ../Images/menuitems.png \
    ../Images/moutain_background.png \
    ../Images/popo_sprite_sheet.png \
    ../Images/sapin_background.png \
    ../Images/sun.png

