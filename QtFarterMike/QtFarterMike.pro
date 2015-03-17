TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += /usr/include/SDL2
LIBS += -L /usr/lib -lSDL2

SOURCES += main.cpp \
    game.cpp \
    menuscreen.cpp \
    button.cpp \
    level1screen.cpp \
    level1spritesheet.cpp \
    hero.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    game.h \
    screen.h \
    menuscreen.h \
    button.h \
    level1screen.h \
    level1spritesheet.h \
    hero.h

