TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Usefulfuncs.cpp \
        main.cpp \
        ship.cpp \
        useless_task_dangerzone/keeper.cpp

HEADERS += \
    Usefulfuncs.h \
    ship.h \
    useless_task_dangerzone/keeper.h
