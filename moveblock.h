#ifndef MOVEBLOCK_H
#define MOVEBLOCK_H

#include <QString>
//#include <QList>
#include <QStringList>

#include "movedir.h"

//! Запись одного блока перемещения

class MoveBlock
{
public:
    //! Направление перемещения
    enum MoveDirection {ToLeft,ToRight,ToBoth};
  MoveBlock(const QString &nameblock,const MoveDir &mSourceDir,const MoveDir &mDestDir,MoveDirection direct);

    MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
              const QString &sourcemask,const QString &destmask,
              MoveDirection direct);

    //! Имя блока
    QString nameBlock;
    //! Источник (слева)
    MoveDir msourceDir;


    //! Приемник (справа)
    MoveDir mdestDir;

    //! Допустимые направления перемещения
    MoveDirection direction;
    //! Перечитать содержимое директорий
    void refresh ();

};

#endif // MOVEBLOCK_H
