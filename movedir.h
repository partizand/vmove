#ifndef MOVEDIR_H
#define MOVEDIR_H

#include <QList>
#include <QStringList>

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
    //! ������ ���� ������ � ��������
    QStringList fileNames;

    QStringList displayNames;
    //QList<MoveFile> mFiles;
    //MoveFile mFiles;
    //! ���������� ���������� ����������
    void refresh ();
private:
    //! �������� � ��������� ������, ����� � �������
    void refreshSum();
    //! �������� ����� �����
    QString GetSumFile(const QString &filename);
    //! ������������� ����� � �������� ������
    QString GetDisplaySum(const QString &strSum);


};

#endif // MOVEDIR_H
