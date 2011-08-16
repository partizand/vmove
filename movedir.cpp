#include "movedir.h"

#include <QDir>
#include <QtXml>

MoveDir::MoveDir()
{
}
MoveDir::MoveDir(const QString &mdir,const QString &mmask):
        mDir(mdir),mMask(mmask)
{

}
//! Перечитать содержимое директории
void MoveDir::refresh ()
{
    int i;
    QStringList sFiles;
    QString displayName,strSum;
    QDir source(mDir);
    MoveFile FileEntry;
    if (!source.exists()) return; // Каталога нет
    source.setFilter(QDir::Files);
    if (mMask!="") source.setNameFilters(mMask.split("|"));
    sFiles=source.entryList(); // Список файлов в каталоге
    for (i=0;i<sFiles.size();i++) // Проходим по каждому, добавляем
    {
        displayName="";
        if (sFiles.at(i).startsWith("i")) // Имя файла начинается с i
        {
            strSum=GetSumFile(mDir+"/"+sFiles.at(i));
            if (strSum!="")
            {
               displayName=sFiles.at(i)+" (" +strSum+")";
            }
        }
        FileEntry=MoveFile(sFiles.at(i),displayName);
        mFiles.append(FileEntry);
    }


}
//! Получить сумму файла
QString MoveDir::GetSumFile(const QString &filename)
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
