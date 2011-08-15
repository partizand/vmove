#include <QtGui/QApplication>
#include "mainwindow.h"

#include <QTextCodec>
#include <QtPlugin>
Q_IMPORT_PLUGIN(qgif);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("Windows-1251"));

    MainWindow w;
    w.show();

    return a.exec();
}
