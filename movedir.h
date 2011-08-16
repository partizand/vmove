#ifndef MOVEDIR_H
#define MOVEDIR_H

#include <QList>

#include "movefile.h"

//! Запись одного каталога перемещения
class MoveDir
{
public:
    MoveDir();

    MoveDir(const QString &mdir,const QString &mmask);
    //! Имя каталога
    QString mDir;
    //! Маска файлов
    QString mMask;
    //! Список файлов в каталоге
    QList<MoveFile> mFiles;
    //MoveFile mFiles;
    //! Перечитать содержимое директории
    void refresh ();
private:
    //! Добавить к названиям файлов, сумму в скобках
    void refreshSum();
    //! Получить сумму файла
    QString GetSumFile(const QString &filename);
};

#endif // MOVEDIR_H
