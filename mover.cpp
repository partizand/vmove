#include "mover.h"
#include <QApplication>
#include <QFile>
#include <QDir>
#include <QDateTime>
#include <QMessageBox>



Mover::Mover()

{
    QSettings *sett=new QSettings(QApplication::applicationDirPath()+"/vmove.ini",QSettings::IniFormat);// (QSettings::IniFormat,QSettings::SystemScope,"ini","vmove");
    sett->setIniCodec("Windows-1251");

    // �������� ������ ��������
    /*
    sett->setValue("/settings/BackupEnabled",true);
    sett->setValue("/settings/BackupDir","d:/temp/2");

    sett->setValue("/blocks/name0","Test 1");
    sett->setValue("/blocks/sourceDir0","d:/temp/0");
    sett->setValue("/blocks/destDir0","d:/temp/1");
    */
    // ����� �������� ������

    // ������ ������� ��������
    backupEnabled=sett->value("/settings/BackupEnabled",false).toBool(); // ����� �������
    backupDir=sett->value("/settings/BackupDir","").toString();          // ������� ������
    refreshInterval=sett->value("/settings/refreshInterval",0).toInt();  // ������ ��������������� ���
    buttonAllLeft=sett->value("/settings/buttonLeft",true).toBool(); // ������ ��� ������
    buttonAllRight=sett->value("/settings/buttonRight",true).toBool(); // ������ ��� �������
    buttonAllBoth=sett->value("/settings/buttonBoth",true).toBool(); // ������ ��� �� ��� �������

    QString nameb,source,dest,sourcemask,destmask,strDirect;
    MoveBlock::MoveDirection direct;
    int i=0;
    do
    //for (int i=0;i<count;i++)
    {
        nameb=sett->value("/blocks/name"+QString::number(i),"").toString();
        source=sett->value("/blocks/sourceDir"+QString::number(i),"").toString();
        dest=sett->value("/blocks/destDir"+QString::number(i),"").toString();
        sourcemask=sett->value("/blocks/SourceMask"+QString::number(i),"").toString();
        destmask=sett->value("/blocks/DestMask"+QString::number(i),"").toString();

        strDirect=sett->value("/blocks/direction"+QString::number(i),"right").toString();
        direct=MoveBlock::ToRight;
        if (strDirect.compare("right",Qt::CaseInsensitive)==0) direct=MoveBlock::ToRight;
        if (strDirect.compare("left",Qt::CaseInsensitive)==0) direct=MoveBlock::ToLeft;
        if (strDirect.compare("both",Qt::CaseInsensitive)==0) direct=MoveBlock::ToBoth;

        if (source=="") break;
        //count=i+1;



        moveBlocks.append(new MoveBlock(nameb,source,dest,sourcemask,destmask,direct));
        i++;
    }
    while (source!="");
    count=moveBlocks.count();
    refresh ();
    delete sett;

}
Mover::~Mover()
{
    while (!moveBlocks.isEmpty())
         delete moveBlocks.takeFirst();
}
void Mover::refresh()
{
    for (int i=0;i<moveBlocks.count();i++)
    {
        moveBlocks[i]->refresh();
    }


}
// ����������� �����

void Mover::move(int indexBlock,int indexFile,MoveBlock::MoveDirection movDirect/*=MoveBlock::ToRight*/)
{
    QString sfullFileName,dfullFileName,fileName;
    switch (movDirect)
    {
    case MoveBlock::ToRight:
        fileName=moveBlocks[indexBlock]->msourceDir.fileNames[indexFile];
        sfullFileName=moveBlocks[indexBlock]->msourceDir.mDir+"/"+fileName;
        dfullFileName=moveBlocks[indexBlock]->mdestDir.mDir+"/"+fileName;
        break;
    case MoveBlock::ToLeft:
        fileName=moveBlocks[indexBlock]->mdestDir.fileNames[indexFile];
        sfullFileName=moveBlocks[indexBlock]->mdestDir.mDir+"/"+fileName;
        dfullFileName=moveBlocks[indexBlock]->msourceDir.mDir+"/"+fileName;
    }
    QFile sourfile(sfullFileName);
    if (!sourfile.exists()) return; // ����� ���
    // ����� ����� ���� �������
    if (backupEnabled)
    {
        QString backDir=replDate(backupDir); // �������� ����

        QDir dir(backDir);
        if (!dir.exists()) dir.mkpath(backDir); // ������� ������� ���� ��� ���
        sourfile.copy(backDir+"/"+fileName);
    }
    // ����������� �����
    if (sourfile.rename(dfullFileName))
    {
        log.writeMessage("��������� ���� "+sfullFileName+" � "+dfullFileName);
    }
    else
    {
        log.writeMessage("[������] ����������� ����� "+sfullFileName+" � "+dfullFileName);
    }
}

// ����������� �����
/*
void Mover::move(int index,const QString &fileName,MoveBlock::MoveDirection movDirect)
{
    QString sfullFileName,dfullFileName;
    switch (movDirect)
    {
    case MoveBlock::ToRight:
        sfullFileName=moveBlocks[index]->msourceDir+"/"+fileName;
        dfullFileName=moveBlocks[index]->mdestDir+"/"+fileName;
        break;
    case MoveBlock::ToLeft:
        sfullFileName=moveBlocks[index]->mdestDir+"/"+fileName;
        dfullFileName=moveBlocks[index]->msourceDir+"/"+fileName;
    }
    QFile sourfile(sfullFileName);
    if (!sourfile.exists()) return; // ����� ���
    // ����� ����� ���� �������
    if (backupEnabled)
    {
        QString backDir=replDate(backupDir); // �������� ����

        QDir dir(backDir);
        if (!dir.exists()) dir.mkpath(backDir); // ������� ������� ���� ��� ���
        sourfile.copy(backDir+"/"+fileName);
    }
    // ����������� �����
    if (sourfile.rename(dfullFileName))
    {
        log.writeMessage("��������� ���� "+sfullFileName+" � "+dfullFileName);
    }
    else
    {
        log.writeMessage("[������] ����������� ����� "+sfullFileName+" � "+dfullFileName);
    }
}
*/
//! �������� %yymmdd% �� ������� ����
QString Mover::replDate(const QString &str)
{
    QString block,strDate;
    QString result=str;
    QDateTime nowDate=QDateTime::currentDateTime();
    block=getParamBlock(str);
    while (block!="")
        {
        strDate=nowDate.toString(block);
        result.replace("%"+block+"%",strDate);
        block=getParamBlock(result);
        }
return result;
}

//! ��������������� ������� ��� replDate, ���������� ������ ��������� ��������� %yymmdd% ��� "" ���� �� �������
QString Mover::getParamBlock(const QString &str)
{
    int beg,end;
    beg=str.indexOf("%");
    if (beg==-1) return "";
    end=str.indexOf("%",beg+1);
    if (end==-1) return "";
    return str.mid(beg+1,end-beg-1);
}

