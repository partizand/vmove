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

#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QPushButton>

/** Кнопка с индексом
  */
class MoveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MoveButton(int butIndex,const QString &text, QWidget *parent = 0);
    //! Индекс конопки
    Q_PROPERTY(int index READ getIndex WRITE setIndex);
signals:

public slots:

private:
    //! Индекс кнопки
    int indexp;
    //! Возвращает индекс кнопки
    int getIndex();
    //! Устанавливает индекс кнопки
    void setIndex(int butIndex);
};

#endif // MOVEBUTTON_H
