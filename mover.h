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

#ifndef MOVER_H
#define MOVER_H

#include "moveblock.h"
#include <QList>
#include <QSettings>
#include <QObject>
#include "logging.h"

//! ���������� ����������� ������
/** �������� ��� ������� � ��������� ��� ����������� ������
  */
class Mover
{


public:
    Mover();
    ~Mover();

    //! ���������� ������ ��������
    //Q_PROPERTY (int count READ getCount);
    int count;
    //! ������ ������ ��������
    QList<MoveBlock *> moveBlocks;
    //! �������� ���������� � ���������� ���������
    void refresh();
    //! ����������� ���� ����
    //void move(int index,const QString &fileName,MoveBlock::MoveDirection movDirect=MoveBlock::ToRight);
    void move(int indexBlock,int indexFile,MoveBlock::MoveDirection movDirect=MoveBlock::ToRight);
    //! �������� ����������� ������������ ������ � �����
    bool backupEnabled;
    //! ������� ������
    QString backupDir;
    //! ������ �������������� ����������� ��������� ���.
    int refreshInterval;
    //! ������ ��� ������ ��������
    bool buttonAllLeft;
    //! ������ ��� ������� ��������
    bool buttonAllRight;
    //! ������ ��� � ��� ������� ��������
    bool buttonAllBoth;
private:
    //! ������� ����
    Logging log;

    //! �������� %yymmdd% �� ������� ����
    QString replDate(const QString &str);
    //! ��������������� ������� ��� replDate, ���������� ������ ��������� ��������� %yymmdd%
    QString getParamBlock(const QString &str);
};

#endif // MOVER_H
