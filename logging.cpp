#include "logging.h"

#include <QApplication>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDir>

Logging::Logging()
{
    logDir=QApplication::applicationDirPath()+"/Log";
    QDir dir(logDir);
    if (!dir.exists())
    {
        dir.mkpath(logDir);
    }
}
//! Запись сообщения в файл с добавлением файла
void Logging::writeMessage(const QString &mess)
{
    QString fileName;
    QString messToFile;
    QDateTime dateNow(QDateTime::currentDateTime());
    fileName=dateNow.toString("yyMMdd")+".log";
    fileName=logDir+"/"+fileName; // Полное имя файла
    if (mess=="-") messToFile="---------------------------------------";
        else messToFile=dateNow.toString("dd.MM.yyyy hh:mm:ss")+" "+mess;
    QFile file(fileName);
    if (!file.open(QIODevice::Append)) return;
    QTextStream stream(&file);
    stream.setCodec("windows-1251");
    stream << messToFile << endl;
    file.close();

}
