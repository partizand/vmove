#ifndef MOVEDIR_H
#define MOVEDIR_H

#include <QList>

#include "movefile.h"

//! ������ ������ �������� �����������
class MoveDir
{
public:
    MoveDir();

    MoveDir(const QString &mdir,const QString &mmask);
    //! ��� ��������
    QString mDir;
    //! ����� ������
    QString mMask;
    //! ������ ������ � ��������
    QList<MoveFile> mFiles;
    //MoveFile mFiles;
    //! ���������� ���������� ����������
    void refresh ();
private:
    //! �������� � ��������� ������, ����� � �������
    void refreshSum();
    //! �������� ����� �����
    QString GetSumFile(const QString &filename);
};

#endif // MOVEDIR_H
