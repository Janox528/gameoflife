/*
 *
 * Autoren: Rene Meier,Adrian Musella, Fanjun
 * Version:16.01.2018
 *
 */

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gamewidget.h"
#include <qobject.h>
#include <qpushbutton.h>
#include <qdebug.h>
#include <QPainter>
#include <cabase.h>
#include <QKeyEvent>
#include <QDebug>







MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    gw(new GameWidget(this)),
    ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
        lastDirection = 6;


        ui->comboBox_gamemode->addItem("GameOfLife");
        ui->comboBox_gamemode->addItem("Snake");
        ui->comboBox_gamemode->addItem("Hunter");
        ui->comboBox_gamemode->setCurrentIndex(ui->comboBox_gamemode->findText("GameOfLife"));

        ui->comboBox_cellsmode->addItem("Hunter");
        ui->comboBox_cellsmode->addItem("Victim");
        ui->comboBox_cellsmode->addItem("Food");

        //Connection zwischen Signalen und Slots wird hergestellt

        connect(ui->pushButton_start, SIGNAL(clicked()), gw,SLOT(startGame()));
        connect(ui->pushButton_randomValues, SIGNAL(clicked()), gw,SLOT(randomValues()));
        connect(ui->pushButton_stop, SIGNAL(clicked()), gw,SLOT(stopGame()));
        connect(ui->pushButton_clear, SIGNAL(clicked()), gw,SLOT(clear()));
        connect(ui->pushButton_safe, SIGNAL(clicked()), gw, SLOT(saveGame()));
        connect(ui->pushButton_load, SIGNAL(clicked()), gw, SLOT(loadGame()));
        connect(ui->spinBox_Timer, SIGNAL(valueChanged(int)), gw, SLOT(setTimerIntervall(int)));
        connect(ui->spinBox_size, SIGNAL(valueChanged(int)), gw, SLOT(setUniverseSize(int)));
        connect(ui->pushButton_load,SIGNAL(clicked()),this,SLOT(setsizescroll()));
        connect(ui->pushButton_changeMode,SIGNAL(clicked()),this,SLOT(setGameMode()));
        connect(ui->pushButton_startSnake,SIGNAL(clicked()),this,SLOT(startSnake()));
        connect(ui->spinBox_lebenszeit, SIGNAL(valueChanged(int)), gw, SLOT(setLifespan(int)));
        connect(ui->pushButton_5, SIGNAL(clicked()), gw, SLOT(newGeneration()));


        connect(ui->comboBox_cellsmode,SIGNAL(activated(int)),SLOT(setCellMode()));


        ui->spinBox_Timer->setSuffix(" ms");
        ui->arraygrid->addWidget(gw); //gamewidget ins grid eingefügt


        //push button in ein Textfeld umwandeln.. ich weiss eine traurige Lösung, aber irgendwie hat es mit Textfeldern nicht gut funktioniert.. Das Ergebnis ist das Selbe :D
        ui->pushButton->setFlat(true);
        ui->pushButton_2->setFlat(true);
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_3->setFlat(true);
        ui->pushButton_4->setFlat(true);
        ui->pushButton_4->setEnabled(false);





    }


/*
 * setzt den Wert der spinbox_size auf die weltengrösse.
 * Dadurch erschafft er ein leeres feld der weltengrösse. Also müssen wir die laden funktion nocheinmal ausführen
 *
 *
 */
void MainWindow::setsizescroll()
{
    ui->spinBox_size->setValue(gw->getUniverseSize());
    gw->loadGame();

}


//setzt gamemode
void MainWindow::setGameMode()
{
    if(ui->comboBox_gamemode->currentText() == "Snake")
    {
        gw->setGamemode(1);
        //qDebug() << "gamemode snake";
        startSnake();

    }
    else if(ui->comboBox_gamemode->currentText() == "Hunter")
    {
        gw->setGamemode(2);
        gw->prepareHunter();
        //qDebug() << "gamemode hunter";
    }
    else
    {
        gw->setGamemode(0);
        //qDebug() << ui->comboBox_gamemode->currentText();
    }
}


void MainWindow::setCellMode()
{
    if(ui->comboBox_cellsmode->currentText() == "Hunter"){
        gw->setCellMode(2);
        //qDebug() << "zellmodus 2";
    }
    else if(ui->comboBox_cellsmode->currentText() == "Victim")
    {
        gw->setCellMode(1);
        //qDebug() << "zellmodus 1";
    }
    else if(ui->comboBox_cellsmode->currentText() == "Food")
    {
        gw->setCellMode(3);
        //qDebug() << "zellmodus 3";

    }
}



//startet Snake spiel, falls gamemode auf 1 ist
void MainWindow::startSnake()
{
    if(gw->getGamemode() == 1)
    {
        lastDirection = 6;
        gw->PrepareFieldSnake();
    }
}

//ui löschen um Memory leaks zu vermeiden
MainWindow::~MainWindow()
{
    delete gw;
    delete ui;

}



/*
 *
 * param:*event
 * setzt die Richtung {2,4,6,8} des Kopfes auf den Wert der dazugehörigen Eingabe{w,a,s,d}
 * Ein Richtungswechsel um 180 grad ist nicht möglich.
 */
void MainWindow::keyPressEvent(QKeyEvent *event)
{

    if(event->key() == Qt::Key_W && lastDirection != 2)//oben
    {
        gw->setDirection(8);
        lastDirection = 8;

    }
    else if(event->key() == Qt::Key_D && lastDirection != 4)//rechts
    {
        gw->setDirection(6);
        lastDirection = 6;
    }
    else if(event->key() == Qt::Key_S && lastDirection != 8)//unten
    {
        gw->setDirection(2);
        lastDirection = 2;
    }
    else if(event->key() == Qt::Key_A && lastDirection != 6)//links
    {
        gw->setDirection(4);
        lastDirection = 4;
    }


}







//komischer fehler, kann es nicht löschen und die moc Datei erstellt es immer wieder neu und gibt nen Fehler aus..
void MainWindow::on_spinBox_size_editingFinished()
{

}
