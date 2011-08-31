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

#ifndef MOVEDIR_H
#define MOVEDIR_H

#include <QList>
#include <QStringList>

#include "movefile.h"

//! ������ ������ �������� �����������
class MoveDir
{
public:
    MoveDir();

    MoveDir(const QString &mdir,const QString &mmask);
    //! ��� ��������
    QString mDir;
    //! ����� ������
    QString mMask;
    //! ������ ���� ������ � ��������
    QStringList fileNames;

    QStringList displayNames;
    //QList<MoveFile> mFiles;
    //MoveFile mFiles;
    //! ���������� ���������� ����������
    void refresh ();
private:
    //! �������� � ��������� ������, ����� � �������
    void refreshSum();
    //! �������� ����� �����
    QString GetSumFile(const QString &filename);
    //! ������������� ����� � �������� ������
    QString GetDisplaySum(const QString &strSum);


};

#endif // MOVEDIR_H
