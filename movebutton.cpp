#include "movebutton.h"

MoveButton::MoveButton(int butIndex,const QString &text,QWidget *parent):
    QPushButton (text,parent)
{
  setIndex(butIndex);

}
void MoveButton::setIndex(int butIndex)
{
    indexp=butIndex;
}
int MoveButton::getIndex()
{
    return indexp;
}
