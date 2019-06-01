#-------------------------------------------------
#
# Project created by QtCreator 2019-04-20T14:53:45
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameProject
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    logic/logic.cpp \
        main.cpp \
    entities/bluebackground.cpp \
    entities/brick.cpp \
    entities/bullet.cpp \
    entities/evil1.cpp \
    entities/ground.cpp \
    entities/hero.cpp \
    entities/wall.cpp \
    scenes/scene.cpp \
    tools/scenedebuger.cpp \
    tools/soundmanager.cpp \
    tools/sprite.cpp \
    widgets/menuwidget.cpp \
    widgets/newview.cpp \
    widgets/optionswidget.cpp \
    widgets/widget.cpp

HEADERS += \
    entities/bluebackground.h \
    entities/brick.h \
    entities/bullet.h \
    entities/evil1.h \
    entities/ground.h \
    entities/hero.h \
    entities/wall.h \
    logic/logic.h \
    scenes/scene.h \
    tools/scenedebuger.h \
    tools/soundmanager.h \
    tools/sprite.h \
    widgets/menuwidget.h \
    widgets/newview.h \
    widgets/optionswidget.h \
    widgets/widget.h \
    tools/config.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    widgets/optionswidget.ui \
    widgets/menuwidget.ui

RESOURCES += \
    assets.qrc
