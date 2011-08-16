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
    //QStringList sFiles;
    QString displayName,strSum;
    QDir source(mDir);
    //MoveFile FileEntry;
    displayNames.clear();
    if (!source.exists()) return; // �������� ���
    source.setFilter(QDir::Files);
    if (mMask!="") source.setNameFilters(mMask.split("|"));
    fileNames=source.entryList(); // ������ ������ � ��������
    for (i=0;i<fileNames.size();i++) // �������� �� �������, ���������
    {
        displayName=fileNames.at(i);
        if (fileNames.at(i).startsWith("i") || fileNames.at(i).startsWith("u")) // ��� ����� ���������� � i
        {
            strSum=GetSumFile(mDir+"/"+fileNames.at(i));
            if (strSum!="")
            {
               displayName=fileNames.at(i)+" (" +strSum+")";
            }
        }
        displayNames.append(displayName);
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

          QDomElement domElement=domDoc.documentElement(); // ����� ��� PacketEPD ��� ED101
          if (!domElement.isNull())
          {
              strSum=domElement.attribute("Sum",""); //� ��� ���� �����
              strSum=GetDisplaySum(strSum);

          }
      }

  }
  return strSum;
}
//! ������������� ����� � �������� ������
QString MoveDir::GetDisplaySum(const QString &strSum)
{
    if (strSum.length()<3) return strSum;
    QString money;
    //money=strSum.left(strSum.length()-2)+","+strSum.right(2)+" �.";
    //QString money(strSum);
    double dValue = strSum.toDouble();
    dValue=dValue/100;

    //money.setNum(dValue,'f',2);
    money = QString("%L1").arg(dValue ,0,'f',2,' ')+" �.";

    return money;
}

