/*
Copyright 2011 Kapustin Andrey

This file is part of Visual move.

Visual move is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Visual move is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with FileRouter.  If not, see <http://www.gnu.org/licenses/>.

Код распространяется по лицензии GPL 3
Автор: Капустин Андрей, 2011 г.
*/

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
