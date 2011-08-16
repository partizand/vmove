#ifndef MOVER_H
#define MOVER_H

#include "moveblock.h"
#include <QList>
#include <QSettings>
#include <QObject>
#include "logging.h"

//! ���������� ����������� ������
/** �������� ��� ������� � ��������� ��� ����������� ������
  */
class Mover
{


public:
    Mover();
    ~Mover();

    //! ���������� ������ ��������
    //Q_PROPERTY (int count READ getCount);
    int count;
    //! ������ ������ ��������
    QList<MoveBlock *> moveBlocks;
    //! �������� ���������� � ���������� ���������
    void refresh();
    //! ����������� ���� ����
    //void move(int index,const QString &fileName,MoveBlock::MoveDirection movDirect=MoveBlock::ToRight);
    void move(int indexBlock,int indexFile,MoveBlock::MoveDirection movDirect=MoveBlock::ToRight);
    //! �������� ����������� ������������ ������ � �����
    bool backupEnabled;
    //! ������� ������
    QString backupDir;
    //! ������ �������������� ����������� ��������� ���.
    int refreshInterval;
    //! ������ ��� ������ ��������
    bool buttonAllLeft;
    //! ������ ��� ������� ��������
    bool buttonAllRight;
    //! ������ ��� � ��� ������� ��������
    bool buttonAllBoth;
private:
    //! ������� ����
    Logging log;

    //! �������� %yymmdd% �� ������� ����
    QString replDate(const QString &str);
    //! ��������������� ������� ��� replDate, ���������� ������ ��������� ��������� %yymmdd%
    QString getParamBlock(const QString &str);
};

#endif // MOVER_H
