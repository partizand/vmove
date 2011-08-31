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

#include "moveblock.h"

#include <QDir>
#include <QStringList>
#include <QtXml>

MoveBlock::MoveBlock(const QString &nameblock,const MoveDir &mSourceDir,const MoveDir &mDestDir,MoveDirection direct):
        nameBlock(nameblock),msourceDir(mSourceDir),mdestDir(mDestDir),direction(direct)
{

}

MoveBlock::MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
          const QString &sourcemask,const QString &destmask,
          MoveDirection direct):
 nameBlock(nameblock),
 msourceDir(sourcedir,sourcemask),
 mdestDir(destdir,destmask),
 direction(direct)
{


}
void MoveBlock::refresh()
{
msourceDir.refresh();
mdestDir.refresh();
}

