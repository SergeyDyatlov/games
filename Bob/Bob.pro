TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -L /usr/lib -lSDL2

SOURCES += main.cpp \
    game.cpp \
    menustate.cpp \
    playstate.cpp \
    pausestate.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    game.h \
    gamestate.h \
    menustate.h \
    playstate.h \
    pausestate.h

