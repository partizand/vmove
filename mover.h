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

#ifndef MOVER_H
#define MOVER_H

#include "moveblock.h"
#include <QList>
#include <QSettings>
#include <QObject>
#include "logging.h"

//! Функционал перемещения файлов
/** Содержит все функции и настройки для перемещения файлов
  */
class Mover
{


public:
    Mover();
    ~Mover();

    //! Количество блоков переноса
    //Q_PROPERTY (int count READ getCount);
    int count;
    //! Список блоков переноса
    QList<MoveBlock *> moveBlocks;
    //! Обновить информацию о содержимом каталогов
    void refresh();
    //! Переместить один файл
    //void move(int index,const QString &fileName,MoveBlock::MoveDirection movDirect=MoveBlock::ToRight);
    void move(int indexBlock,int indexFile,MoveBlock::MoveDirection movDirect=MoveBlock::ToRight);
    //! Включено копирование перемещаемых файлов в бэкап
    bool backupEnabled;
    //! Каталог бэкапа
    QString backupDir;
    //! Период автообновления содержимого каталогов сек.
    int refreshInterval;
    //! Кнопка все налево доступна
    bool buttonAllLeft;
    //! Кнопка все направо доступна
    bool buttonAllRight;
    //! Кнопка все в обе стороны доступна
    bool buttonAllBoth;
private:
    //! Ведение лога
    Logging log;

    //! Заменяет %yymmdd% на текущую дату
    QString replDate(const QString &str);
    //! Вспомогательная функция для replDate, возвращает первую найденную структуру %yymmdd%
    QString getParamBlock(const QString &str);
};

#endif // MOVER_H
