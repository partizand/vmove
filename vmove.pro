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
    testcl.cpp

HEADERS  += mainwindow.h \
    movebutton.h \
    mover.h \
    moveblock.h \
    logging.h \
    testcl.h


#QTPLUGIN += libqgif4 #qgif


FORMS    += mainwindow.ui

RESOURCES += resurs.qrc
