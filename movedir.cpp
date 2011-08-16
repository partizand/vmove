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
//! ���������� ���������� ����������
void MoveDir::refresh ()
{
    int i;
    QStringList sFiles;
    QString displayName,strSum;
    QDir source(mDir);
    MoveFile FileEntry;
    if (!source.exists()) return; // �������� ���
    source.setFilter(QDir::Files);
    if (mMask!="") source.setNameFilters(mMask.split("|"));
    sFiles=source.entryList(); // ������ ������ � ��������
    for (i=0;i<sFiles.size();i++) // �������� �� �������, ���������
    {
        displayName="";
        if (sFiles.at(i).startsWith("i")) // ��� ����� ���������� � i
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
//! �������� ����� �����
QString MoveDir::GetSumFile(const QString &filename)
{
  QDomDocument domDoc;
  QFile file(filename);
  QString strSum("");
  if (file.open(QIODevice::ReadOnly)) // ���� �������� �� ������
  {
      if (domDoc.setContent(&file)) // ���������� ��� xml
      {
          //QDomNodeList elements = doc.documentElement().elementsByTagName( "PacketEPD" );

          QDomElement domElement=domDoc.documentElement(); // ����� ��� PacketEPD
          if (!domElement.isNull())
          {
              strSum=domElement.attribute("Sum",""); //� ��� ���� �����

          }
      }

  }
  return strSum;
}
