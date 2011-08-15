#include "moveblock.h"

#include <QDir>
#include <QStringList>

MoveBlock::MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
                     const QString &sourcemask,const QString &destmask,
                     MoveDirection direct)
{
    nameBlock=nameblock;
    sourceDir=sourcedir;
    destDir=destdir;
    sourceMask=sourcemask;
    destMask=destmask;
    direction=direct;
}
void MoveBlock::refresh()
{
QDir source(sourceDir);
source.setFilter(QDir::Files);
if (sourceMask!="") source.setNameFilters(sourceMask.split("|"));
sourceFiles=source.entryList();
QDir dest(destDir);
dest.setFilter(QDir::Files);
if (destMask!="") dest.setNameFilters(destMask.split("|"));
destFiles=dest.entryList();
}
