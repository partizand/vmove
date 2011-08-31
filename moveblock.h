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

��� ���������������� �� �������� GPL 3
�����: �������� ������, 2011 �.
*/

#ifndef MOVEBLOCK_H
#define MOVEBLOCK_H

#include <QString>
//#include <QList>
#include <QStringList>

#include "movedir.h"

//! ������ ������ ����� �����������

class MoveBlock
{
public:
    //! ����������� �����������
    enum MoveDirection {ToLeft,ToRight,ToBoth};
  MoveBlock(const QString &nameblock,const MoveDir &mSourceDir,const MoveDir &mDestDir,MoveDirection direct);

    MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
              const QString &sourcemask,const QString &destmask,
              MoveDirection direct);

    //! ��� �����
    QString nameBlock;
    //! �������� (�����)
    MoveDir msourceDir;


    //! �������� (������)
    MoveDir mdestDir;

    //! ���������� ����������� �����������
    MoveDirection direction;
    //! ���������� ���������� ����������
    void refresh ();

};

#endif // MOVEBLOCK_H
