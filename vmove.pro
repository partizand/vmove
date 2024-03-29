#-------------------------------------------------
#
# Project created by QtCreator 2011-01-26T12:14:43
#
#-------------------------------------------------

QT       += core gui xml

TARGET = vmove
TEMPLATE = app

#LIBS += -LC:/Qt/2010.05/qt/plugins/imageformats #libqgif4

SOURCES += main.cpp\
        mainwindow.cpp \
    movebutton.cpp \
    mover.cpp \
    moveblock.cpp \
    logging.cpp \
    movedir.cpp \
    movefile.cpp

HEADERS  += mainwindow.h \
    movebutton.h \
    mover.h \
    moveblock.h \
    logging.h \
    movedir.h \
    movefile.h


#QTPLUGIN += libqgif4 #qgif


FORMS    += mainwindow.ui

RESOURCES += resurs.qrc
