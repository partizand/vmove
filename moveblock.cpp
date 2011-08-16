#include "moveblock.h"

#include <QDir>
#include <QStringList>
#include <QtXml>

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
refreshSum();
QDir dest(destDir);
dest.setFilter(QDir::Files);
if (destMask!="") dest.setNameFilters(destMask.split("|"));
destFiles=dest.entryList();
}

void MoveBlock::refreshSum()
{
    QString strSum;
    // Проходим по файлам, ищем там суммы
    int i;
    for (i=0;i<sourceFiles.count();i++)
    {
        if (sourceFiles.at(i).startsWith("i")) // Имя файла начинается с i
        {
            strSum=GetSumFile(sourceDir+"/"+sourceFiles.at(i));
            if (strSum!="")
            {
               sourceFiles[i]=sourceFiles.at(i)+" (" +strSum+")";
            }
        }

    }

}

QString MoveBlock::GetSumFile(const QString &filename)
{
  QDomDocument domDoc;
  QFile file(filename);
  QString strSum("");
  if (file.open(QIODevice::ReadOnly)) // Файл открылся на чтение
  {
      if (domDoc.setContent(&file)) // Прочитался как xml
      {
          //QDomNodeList elements = doc.documentElement().elementsByTagName( "PacketEPD" );

          QDomElement domElement=domDoc.documentElement(); // Вроде как PacketEPD
          if (!domElement.isNull())
          {
              strSum=domElement.attribute("Sum",""); //А это типа сумма

          }
      }

  }
  return strSum;
}

