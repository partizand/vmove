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

