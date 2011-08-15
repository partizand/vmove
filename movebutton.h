#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QPushButton>

/** ������ � ��������
  */
class MoveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MoveButton(int butIndex,const QString &text, QWidget *parent = 0);
    //! ������ �������
    Q_PROPERTY(int index READ getIndex WRITE setIndex);
signals:

public slots:

private:
    //! ������ ������
    int indexp;
    //! ���������� ������ ������
    int getIndex();
    //! ������������� ������ ������
    void setIndex(int butIndex);
};

#endif // MOVEBUTTON_H
