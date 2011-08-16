#ifndef MOVEFILE_H
#define MOVEFILE_H

#include <QString>

/*
class MoveFileEntry
{
public:
    MoveFileEntry();
    MoveFileEntry(const QString &FileName,const QString &FileDisplay="");
    //! �������� ��� �����
    QString fileName;
    //! ��� ����� ��� �����������
    QString fileDisplay;
};
*/
//! ������ ������ �����
class MoveFile
{
public:
    MoveFile();
    MoveFile(const QString &FileName,const QString &FileDisplay);

    //! �������� ��� �����
    QString fileName;
    //! ��� ����� ��� �����������
    QString fileDisplay;
};

#endif // MOVEFILE_H
