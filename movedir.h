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

#ifndef MOVEDIR_H
#define MOVEDIR_H

#include <QList>
#include <QStringList>

#include "movefile.h"

//! Запись одного каталога перемещения
class MoveDir
{
public:
    MoveDir();

    MoveDir(const QString &mdir,const QString &mmask);
    //! Имя каталога
    QString mDir;
    //! Маска файлов
    QString mMask;
    //! Список имен файлов в каталоге
    QStringList fileNames;

    QStringList displayNames;
    //QList<MoveFile> mFiles;
    //MoveFile mFiles;
    //! Перечитать содержимое директории
    void refresh ();
private:
    //! Добавить к названиям файлов, сумму в скобках
    void refreshSum();
    //! Получить сумму файла
    QString GetSumFile(const QString &filename);
    //! Преобразовать сумму в читаемый формат
    QString GetDisplaySum(const QString &strSum);


};

#endif // MOVEDIR_H
