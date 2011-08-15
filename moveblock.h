#ifndef MOVEBLOCK_H
#define MOVEBLOCK_H

#include <QString>
#include <QList>
#include <QStringList>

//! ������ ������ ����� �����������

class MoveBlock
{
public:
    //! ����������� �����������
    enum MoveDirection {ToLeft,ToRight,ToBoth};
    MoveBlock(const QString &nameblock,const QString &sourcedir,const QString &destdir,
              const QString &sourcemask,const QString &destmask,
              MoveDirection direct);

    //! ��� �����
    QString nameBlock;
    //! ������� �������� (�����)
    QString sourceDir;
    //! ������� �������� (������)
    QString destDir;
    //! ����� ������ ���������
    QString sourceMask;
    //! ����� ������ ���������
    QString destMask;
    //! ���������� ����������� �����������
    MoveDirection direction;
    //! ������ ������ � �������� ��������� (�����)
    QStringList sourceFiles;
    //! ������ ������ � �������� ��������� (������)
    QStringList destFiles;
    //! ���������� ���������� ����������
    void refresh ();
};

#endif // MOVEBLOCK_H
