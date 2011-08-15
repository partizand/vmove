#ifndef MOVEBLOCK_H
#define MOVEBLOCK_H

#include <QString>
#include <QList>
#include <QStringList>

//! Запись одного блока перемещения

class MoveBlock
{
public:
    //! Направление перемещения
    enum MoveDirection {ToLeft,ToRight,ToBoth};
    MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
              const QString &sourcemask,const QString &destmask,
              MoveDirection direct);

    //! Имя блока
    QString nameBlock;
    //! Каталог источник (слева)
    QString sourceDir;
    //! Каталог приемник (справа)
    QString destDir;
    //! Маска файлов источника
    QString sourceMask;
    //! Маска файлов приемника
    QString destMask;
    //! Допустимые направления перемещения
    MoveDirection direction;
    //! Список файлов в каталоге источнике (слева)
    QStringList sourceFiles;
    //! Список файлов в каталоге приемнике (справа)
    QStringList destFiles;
    //! Перечитать содержимое директорий
    void refresh ();
};

#endif // MOVEBLOCK_H
