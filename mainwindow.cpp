#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //MyAct=new QAction("My Action",this);
    //ui->menuView->addAction(MyAct);
    //connect (MyAct,SIGNAL(triggered()),this,SLOT(on_actionMyAct_triggered()));

    //panelCount=mover.count;
    if (mover.buttonAllLeft) ui->mainToolBar->addAction(ui->actionMoveAllLeft);
    if (mover.buttonAllRight) ui->mainToolBar->addAction(ui->actionMoveAllRight);
    if (mover.buttonAllBoth)
        {
        ui->mainToolBar->addSeparator();
        ui->mainToolBar->addAction(ui->actionMoveAll);
        }
    /*
    ui->actionMoveAllLeft->setEnabled(mover.buttonAllLeft);
    ui->actionMoveAllRight->setEnabled(mover.buttonAllRight);
    ui->actionMoveAll->setEnabled(mover.buttonAllBoth);

    ui->actionMoveAllLeft->setVisible(mover.buttonAllLeft);
    ui->actionMoveAllRight->setVisible(mover.buttonAllRight);
    ui->actionMoveAll->setVisible(mover.buttonAllBoth);
    */

    //ui->actionMoveAll->setVisible(false);
    gridLayout=new QGridLayout(ui->centralWidget);
    int i,line;

    for (i=0;i<mover.count;i++)
    {

        butLayouts.append(new QVBoxLayout());
        // Надпись
        labels.append(new QLabel(mover.moveBlocks[i]->nameBlock));
        // Левый список
        leftLists.append(new QListWidget());
        // Правый список
        rightLists.append(new QListWidget());

        // Кнопка ">"
        buttonsToRight.append(new MoveButton(i,">"));
        buttonsToRight[i]->setMaximumWidth(35);
        connect(buttonsToRight[i],SIGNAL(pressed()),this,SLOT(on_buttonToRight_pressed()));

        // Кнопка ">>"
        buttonsToRightAll.append(new MoveButton(i,">>"));
        buttonsToRightAll[i]->setMaximumWidth(35);
        connect(buttonsToRightAll[i],SIGNAL(pressed()),this,SLOT(on_buttonToRightAll_pressed()));

        // Кнопка "<"
        buttonsToLeft.append(new MoveButton(i,"<"));
        buttonsToLeft[i]->setMaximumWidth(35);
        connect(buttonsToLeft[i],SIGNAL(pressed()),this,SLOT(on_buttonToLeft_pressed()));

        // Кнопка "<<"
        buttonsToLeftAll.append(new MoveButton(i,"<<"));
        buttonsToLeftAll[i]->setMaximumWidth(35);
        connect(buttonsToLeftAll[i],SIGNAL(pressed()),this,SLOT(on_buttonToLeftAll_pressed()));
        // Добавление кнопок
        switch (mover.moveBlocks[i]->direction)
            {
            case MoveBlock::ToRight:
            butLayouts[i]->addWidget(buttonsToRight[i]);
            butLayouts[i]->addWidget(buttonsToRightAll[i]);
            break;
            case MoveBlock::ToLeft:
            butLayouts[i]->addWidget(buttonsToLeft[i]);
            butLayouts[i]->addWidget(buttonsToLeftAll[i]);
            break;
            case MoveBlock::ToBoth:
            butLayouts[i]->addWidget(buttonsToRight[i]);
            butLayouts[i]->addWidget(buttonsToRightAll[i]);
            butLayouts[i]->addWidget(buttonsToLeft[i]);
            butLayouts[i]->addWidget(buttonsToLeftAll[i]);
            break;
            }

        //butLayouts[i]->addWidget(buttonsToRight[i]);
        //butLayouts[i]->addWidget(buttonsToRightAll[i]);

        line=i*2;
        gridLayout->addWidget(labels[i],line,0,1,3);
        gridLayout->addWidget(leftLists[i],line+1,0);
        gridLayout->addLayout(butLayouts[i],line+1,1);
        //gridLayout->addWidget(buttonsToRight[i],line+1,1);
        //gridLayout->addWidget(buttonsToRightAll[i],line+1,1);
        gridLayout->addWidget(rightLists[i],line+1,2);
    }
    refresh();
    if (mover.refreshInterval>0) // Установлен интервал автообновления
        {// включаем таймер
        startTimer(mover.refreshInterval*1000);
        ui->statusBar->addWidget(new QLabel("Автообновление каждые " +QString::number(mover.refreshInterval)+" секунд"));
        }

}

MainWindow::~MainWindow()
{
    delete ui;
}
//! Событие таймера
void MainWindow::timerEvent (QTimerEvent *event)
{
    refresh();
}

// Обновление списка файлов
void MainWindow::refresh()
{
    mover.refresh();
    for (int i=0;i<mover.count;i++)
    {
        leftLists[i]->clear();
        leftLists[i]->addItems(mover.moveBlocks[i]->msourceDir.displayNames);
        rightLists[i]->clear();
        rightLists[i]->addItems(mover.moveBlocks[i]->mdestDir.displayNames);
    }
}
//! Перемещение выбранных файлов по индексу
void MainWindow::moveSelected(int index,MoveBlock::MoveDirection mDirect /*=Mover::ToRigth*/)
{
    //QList<QListWidgetItem *> selItems;
    QListWidget *listWidget;
    switch (mDirect)
        {
        case MoveBlock::ToRight:
            listWidget=leftLists[index];
            break;
        case MoveBlock::ToLeft:
            listWidget=rightLists[index];
            break;
        default:
            return;
        }
    for (int j=0;j<listWidget->count();j++)
    {
        if (listWidget->item(j)->isSelected())
        {
        mover.move(index,j,mDirect);
        }
    }
}
//! Перемещение всех файлов по индексу
void MainWindow::moveAll(int index,MoveBlock::MoveDirection mDirect /*=Mover::ToRigth*/)
{
    switch (mDirect)
        {
        case MoveBlock::ToRight:
                    for (int j=0;j<leftLists[index]->count();j++)
                        {
                        mover.move(index,j,mDirect);
                        }
        break;
        case MoveBlock::ToLeft:
                    for (int j=0;j<rightLists[index]->count();j++)
                        {
                        mover.move(index,j,mDirect);
                        }
                    break;
        }


}




// Нажата кнопка ">"
void MainWindow::on_buttonToRight_pressed()
{
    int i;
    i=sender()->property("index").toInt(); // Индекс кнопки
    moveSelected(i);
    refresh();
}
// Нажата кнопка ">>"
void MainWindow::on_buttonToRightAll_pressed()
{
    int i;
    i=sender()->property("index").toInt(); // Индекс кнопки
    moveAll(i);
    refresh();
}


// Нажата кнопка "<"
void MainWindow::on_buttonToLeft_pressed()
{
    int i;
    i=sender()->property("index").toInt(); // Индекс кнопки
    moveSelected(i,MoveBlock::ToLeft);
    refresh();
}
// Нажата кнопка "<<"
void MainWindow::on_buttonToLeftAll_pressed()
{
    int i;
    i=sender()->property("index").toInt(); // Индекс кнопки
    moveAll(i,MoveBlock::ToLeft);
    refresh();
}


// Действие обновить
void MainWindow::on_actionRefresh_activated()
{
     //QMessageBox::information(this,"Тестовое сообщение","Нажали обновить");
     refresh();
}

// Переместить все в обе стороны
void MainWindow::on_actionMoveAll_activated()
{
    for (int i=0;i<mover.count;i++)
    {
        if (mover.moveBlocks[i]->direction==MoveBlock::ToRight || mover.moveBlocks[i]->direction==MoveBlock::ToLeft)
            {
            moveAll(i,mover.moveBlocks[i]->direction);
            }
    }
    refresh();

}


// Действие переместить все налево
void MainWindow::on_actionMoveAllLeft_activated()
{
    for (int i=0;i<mover.count;i++)
    {
        if (mover.moveBlocks[i]->direction==MoveBlock::ToLeft || mover.moveBlocks[i]->direction==MoveBlock::ToBoth)
            {
            moveAll(i,MoveBlock::ToLeft);
            }
    }
    refresh();
}

//! Выбрано переместить все направо
void MainWindow::on_actionMoveAllRight_activated()
{
    for (int i=0;i<mover.count;i++)
    {
        if (mover.moveBlocks[i]->direction==MoveBlock::ToRight || mover.moveBlocks[i]->direction==MoveBlock::ToBoth)
            {
            moveAll(i);
            }
    }
    refresh();

}
