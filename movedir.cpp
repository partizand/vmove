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
    file.close();
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

