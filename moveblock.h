#ifndef MOVEBLOCK_H
#define MOVEBLOCK_H

#include <QString>
//#include <QList>
#include <QStringList>

#include "movedir.h"

//! ������ ������ ����� �����������

class MoveBlock
{
public:
    //! ����������� �����������
    enum MoveDirection {ToLeft,ToRight,ToBoth};
  MoveBlock(const QString &nameblock,const MoveDir &mSourceDir,const MoveDir &mDestDir,MoveDirection direct);

    MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
              const QString &sourcemask,const QString &destmask,
              MoveDirection direct);

    //! ��� �����
    QString nameBlock;
    //! �������� (�����)
    MoveDir msourceDir;


    //! �������� (������)
    MoveDir mdestDir;

    //! ���������� ����������� �����������
    MoveDirection direction;
    //! ���������� ���������� ����������
    void refresh ();

};

#endif // MOVEBLOCK_H
