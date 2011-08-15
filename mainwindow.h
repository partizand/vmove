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
