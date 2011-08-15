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
    //! Событие таймера
    void timerEvent (QTimerEvent *event);

private:
    Ui::MainWindow *ui;
    //! Объект перемещений
    Mover mover;
    //! Обновление списка файлов
    void refresh();

    QAction *MyAct;
    QGridLayout *gridLayout;
    // Количество панелей переноса
    //int panelCount;
    //! Компоновщики кнопок
    QList <QLayout *> butLayouts;
    //! Списки слева
    QList<QListWidget *> leftLists;
    //! Списки справа
    QList<QListWidget *> rightLists;
    //! Кнопки ">"
    QList<MoveButton *> buttonsToRight;
    //! Конопки ">>"
    QList<QPushButton *> buttonsToRightAll;
    //! Кнопки "<"
    QList<MoveButton *> buttonsToLeft;
    //! Конопки "<<"
    QList<QPushButton *> buttonsToLeftAll;
    //! Надписи
    QList<QLabel *> labels;
    //! Перемещение выбранных файлов по индексу
    void moveSelected(int index,MoveBlock::MoveDirection mDirect=MoveBlock::ToRight);
    //! Перемещение всех файлов по индексу
    void moveAll(int index,MoveBlock::MoveDirection mDirect=MoveBlock::ToRight);



private slots:
    void on_actionMoveAllRight_activated();
    void on_actionMoveAllLeft_activated();
    void on_actionRefresh_activated();
    //void on_actionMoveAll_triggered();
    void on_actionMoveAll_activated();
    //void on_actionMyAct_triggered();
    //! Нажата кнопка ">"
    void on_buttonToRight_pressed();
    //! Нажата кнопка ">>"
    void on_buttonToRightAll_pressed();
    //! Нажата кнопка "<"
    void on_buttonToLeft_pressed();
    //! Нажата кнопка "<<"
    void on_buttonToLeftAll_pressed();
};

#endif // MAINWINDOW_H
