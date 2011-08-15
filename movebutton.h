#ifndef MOVEBUTTON_H
#define MOVEBUTTON_H

#include <QPushButton>

/** Кнопка с индексом
  */
class MoveButton : public QPushButton
{
    Q_OBJECT
public:
    explicit MoveButton(int butIndex,const QString &text, QWidget *parent = 0);
    //! Индекс конопки
    Q_PROPERTY(int index READ getIndex WRITE setIndex);
signals:

public slots:

private:
    //! Индекс кнопки
    int indexp;
    //! Возвращает индекс кнопки
    int getIndex();
    //! Устанавливает индекс кнопки
    void setIndex(int butIndex);
};

#endif // MOVEBUTTON_H
