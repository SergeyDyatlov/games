TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++1y

INCLUDEPATH += /usr/include/SDL2
LIBS += -L /usr/lib -lSDL2

SOURCES += main.cpp \
    game.cpp \
    menuscreen.cpp \
    button.cpp \
    level1screen.cpp \
    level1spritesheet.cpp \
    hero.cpp \
    enemy.cpp \
    selectlevelscreen.cpp \
    levelscreen.cpp \
    level2screen.cpp \
    menuspritesheet.cpp \
    scorescreen.cpp \
    scorespritesheet.cpp \
    font.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    game.h \
    screen.h \
    menuscreen.h \
    button.h \
    level1screen.h \
    level1spritesheet.h \
    hero.h \
    enemy.h \
    selectlevelscreen.h \
    levelscreen.h \
    level2screen.h \
    menuspritesheet.h \
    scorescreen.h \
    scorespritesheet.h \
    font.h \
    sprite.h

