#ifndef MOVEFILE_H
#define MOVEFILE_H

#include <QString>

/*
class MoveFileEntry
{
public:
    MoveFileEntry();
    MoveFileEntry(const QString &FileName,const QString &FileDisplay="");
    //! Короткое имя файла
    QString fileName;
    //! Имя файла для отображения
    QString fileDisplay;
};
*/
//! Запись одного файла
class MoveFile
{
public:
    MoveFile();
    MoveFile(const QString &FileName,const QString &FileDisplay);

    //! Короткое имя файла
    QString fileName;
    //! Имя файла для отображения
    QString fileDisplay;
};

#endif // MOVEFILE_H
