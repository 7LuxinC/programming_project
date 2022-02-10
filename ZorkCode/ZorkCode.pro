TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Character.cpp \
        Command.cpp \
        CommandWords.cpp \
        Parser.cpp \
        Room.cpp \
        ZorkUL.cpp \
        item.cpp

DISTFILES += \
    ZorkCode.pro.user

HEADERS += \
    Character.h \
    Command.h \
    CommandWords.h \
    Parser.h \
    Room.h \
    ZorkUL.h \
    item.h
