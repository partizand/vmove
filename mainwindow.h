/*
Copyright 2011 Kapustin Andrey

This file is part of Visual move.

Visual move is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Visual move is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with FileRouter.  If not, see <http://www.gnu.org/licenses/>.

��� ���������������� �� �������� GPL 3
�����: �������� ������, 2011 �.
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QGridLayout>
#include <QListWidget>
#include <QList>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include "movebutton.h"
#include "mover.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    //! ������� �������
    void timerEvent (QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    //! ������ �����������
    Mover mover;
    //! ���������� ������ ������
    void refresh();

    QAction *MyAct;
    QGridLayout *gridLayout;
    // ���������� ������� ��������
    //int panelCount;
    //! ������������ ������
    QList <QLayout *> butLayouts;
    //! ������ �����
    QList<QListWidget *> leftLists;
    //! ������ ������
    QList<QListWidget *> rightLists;
    //! ������ ">"
    QList<MoveButton *> buttonsToRight;
    //! ������� ">>"
    QList<QPushButton *> buttonsToRightAll;
    //! ������ "<"
    QList<MoveButton *> buttonsToLeft;
    //! ������� "<<"
    QList<QPushButton *> buttonsToLeftAll;
    //! �������
    QList<QLabel *> labels;
    //! ����������� ��������� ������ �� �������
    void moveSelected(int index,MoveBlock::MoveDirection mDirect=MoveBlock::ToRight);
    //! ����������� ���� ������ �� �������
    void moveAll(int index,MoveBlock::MoveDirection mDirect=MoveBlock::ToRight);



private slots:
    void on_actionMoveAllRight_activated();
    void on_actionMoveAllLeft_activated();
    void on_actionRefresh_activated();
    //void on_actionMoveAll_triggered();
    void on_actionMoveAll_activated();
    //void on_actionMyAct_triggered();
    //! ������ ������ ">"
    void on_buttonToRight_pressed();
    //! ������ ������ ">>"
    void on_buttonToRightAll_pressed();
    //! ������ ������ "<"
    void on_buttonToLeft_pressed();
    //! ������ ������ "<<"
    void on_buttonToLeftAll_pressed();
};

#endif // MAINWINDOW_H
