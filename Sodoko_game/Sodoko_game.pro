#-------------------------------------------------
#
# Project created by QtCreator 2022-05-13T14:01:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Sodoko_game
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        game_helper.cpp \
        game_play.cpp \
        login_page.cpp \
        mainwindow.cpp \
    matrix.cc \
    rdarray.cc

HEADERS  += mainwindow.h \
    game_helper.h \
    game_play.h \
    login_page.h \
    include.h \
    matrix.h \
    rdarray.h

FORMS    += mainwindow.ui \
    game_helper.ui \
    game_play.ui \
    login_page.ui

RESOURCES += \
    backgroundlogin_page.qrc \
    close_icon_log.qrc \
    human_login.qrc \
    image_for_game1.qrc \
    login_image_back.qrc \
    login_page_main.qrc \
    main_window_image_back.qrc \
    pic_mainwindow_start.qrc \
    reload_icon_log.qrc
