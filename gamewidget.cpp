/*
 *
 * Autoren: Rene Meier,Adrian Musella, Fanjun
 * Version:16.01.2018
 *
 */

#include "gamewidget.h"
#include <iostream>
#include <fstream>
#include <QTimer>
#include <cabase.h>
#include <QTimer>
#include <sstream>
#include <QMouseEvent>
#include <QRectF>
#include <QPainter>
#include "gamewidget.h"
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>


using namespace std;
CABase* ca;

/*
 *
 * Konstruktor
 * erschafft ein CABase objekt und initliaisert den Timer
 *
 */
GameWidget::GameWidget(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this))

{

    ca = new CABase();
    gamemode = 0;//standart ist game of life

    timer->setInterval(250);//timer bekommt standart wert von 250ms
    intervall = 250;
    connect(timer,SIGNAL(timeout()),this,SLOT(newGeneration()));//timer mit newgeneration verknüpfen
    cellmode = 2;
    lifespan = 5;


}

/*
 *
 * Werte: 0= nichts, 1 = Kopf, 2 = Body, 3 = schwanz, 4 = food
 */
void GameWidget::PrepareFieldSnake()
{
    timer->stop();

    ca->setSize(ca->getAx(),ca->getAy()); //feld löschen
    ca->setValue(3,3,3); //schlange erstellen
    ca->setValue(3,4,2);
    ca->setValue(3,5,1);
    ca->generateFood();
    ca->setDirection(6);
    ca->setValueDirection(3,3,6); //nach rechts ausgerichtet
    ca->setValueDirection(3,4,6);
    ca->setValueDirection(3,5,6);
    ca->setScore(0);
    score = 0;
    update();
    timer->setInterval(intervall);
    timer->start();
}



//startet den Timer
void GameWidget::startGame()
{

        timer->start();


}
//stoppt den timer
void GameWidget::stopGame()
{

        timer->stop();

}
/*
 * return: int size
 * gibt grösse des Universums zurück
 *
 */
int GameWidget::getUniverseSize()
{
    return ca->getAx();
}

/*
 * geht alle Zellen durch und setzt sie mit einer wahrscheinlichkeit von 50% auf lebend
 *
 */
void GameWidget::randomValues()
{
    if(gamemode == 0)
    {
        for(int i=0;i<ca->getAx();i++)
        {
            for(int j=0;j<ca->getAy();j++)
            {
                if(rand()%100 <50) //(random Zahl zwischen 0 und 100) < 50
                {
                    ca->setValue(i,j,1);//dann setze Zelle i,j lebend
                }
            }
        }
        update();
    }
}


//getter für gamemode
int GameWidget::getGamemode() const
{
    return gamemode;
}


//setter für drawmodus
void GameWidget::setCellMode(int n){
    cellmode = n;
}


//getter für drawmodus
int GameWidget::getCellMode(){
    return cellmode;
}

//löscht das feld und stoppt den timer
void GameWidget::prepareHunter()
{
    timer->stop();
    clear();
}

//setzt sowohl hier als auch in CABase Objekt die lebenszeit auf x
void GameWidget::setLifespan(int x)
{
    lifespan = x;
    ca->setLifespan(lifespan);
}

//setter für gamemode
void GameWidget::setGamemode(int value)
{
    gamemode = value;
}

//löscht alle lebendigen Felder und zeichnet das Spielfeld neu
void GameWidget::clear()
{

        ca->setSize(ca->getAx(),ca->getAy());
        update();

}

//Param: int x
// setzt den Timer auf den wert x
void GameWidget::setTimerIntervall(int x)
{
    timer->setInterval(x);
    intervall = x;
}


/*
 *
 * param: int x
 * setzt die Universumsgrösse auf x*x und zeichnet das Feld neu
 *
 */
void GameWidget::setUniverseSize(int x)
{
    ca->setSize(x,x);
    update();
}


//Speichert den Spielzustand in ein  Textdokument
void GameWidget::saveGame()
{

    if(gamemode == 2)
    {
        return;
    }
    string save = "";
    for(int i=0;i<ca->getAx();i++) //String aller elemente des arrays fertigen
    {
        for(int j=0;j<ca->getAy();j++)
        {

            save.append(to_string(ca->getValue(i,j)));

        }
    }




    ofstream myfile ("savegame.txt");  //grösse und string save in textdokument speichern
      if (myfile.is_open())
      {
          string firstline = to_string(ca->getAx());
          firstline.append("\n");
          myfile << firstline;
          myfile << save;
          myfile.close();
      }

}



/*
 * Lädt ein zuvor in savegame.txt gespeicherten Spielzustand.
 * Dazu gehören Weltengrösse und die lebendigen Zellen.
 * anschliessend wird das Array neu gezeichnet
 *
 */
void GameWidget::loadGame()
{

    if(gamemode == 2)
    {
        return;
    }


        int size = 0;
        ifstream inFile;

        string loadstring;
        string wholestring = "";

        inFile.open("savegame.txt");
        inFile >> size; // erste Zeile lesen(enthält universumsgrösse)
        while (inFile >> loadstring)
        {
            wholestring.append(loadstring); //alle zeilen(ausser die 1.) zu einem String zusammensetzen
        }
        inFile.close();

      setUniverseSize(size); // Grösse des Universums setzen


        int pos = 0;
        for(int i =0;i<ca->getAx();i++)
        {
           for(int j=0;j<ca->getAy();j++)
           {
               ca->setValue(i,j,int(wholestring.at(pos)-'0')); // Den Zellen ihren gespeicherten Wert wiedergeben

               pos++;
           }
        }




    update(); // zeichne


}


//paint event: zeichnet das Universum
void GameWidget::paintEvent(QPaintEvent *)

{

    QPainter p(this);

    cleanfield(p);

    paintGrid(p);

    paintUniverse(p);


}

//zeichnet das Raster. Die Zellengrösse Skaliert automatisch mit der grösse/zellenanzahl
void GameWidget::paintGrid(QPainter &p)
{


    int sizerec = 500;//feldgrösse
    p.drawRect(QRect(0,0,sizerec,sizerec)); // umrandung


    double cellWidth = (double)sizerec/(ca->getAx()); //scalierung breite

    for(double i = cellWidth; i <= sizerec; i += cellWidth)
    {
        p.drawLine(i, 0, i, sizerec);//Horizontalelinien
    }
    double cellHeight = (double)sizerec/(ca->getAy()); //scalierung höhe
    for(double j = cellHeight; j <= sizerec; j += cellHeight)
    {
        p.drawLine(0, j, sizerec, j);//vertikale linien
    }








}
//zeichnet das Universum. Lebende Zellen werden als schwarz markiert
void GameWidget::paintUniverse(QPainter &p)
{


    int sizerec = 500;


    if((gamemode == 0) || (gamemode == 1)){

        for(int i=1; i <= ca->getAx(); i++)
        {
            for(int j=1; j <= ca->getAx(); j++)
            {
                if(ca->getValue(i-1,j-1) != 0 && ca->getValue(i-1,j-1) != 4) //Füllt alle Felder welche als lebendig markiert sind schwarz auf
                {
                    qreal left = (qreal)((double)sizerec/ca->getAx()*j-(double)sizerec/ca->getAx());
                    qreal top  = (qreal)((double)sizerec/ca->getAx()*i-(double)sizerec/ca->getAx());
                    QRectF square(left, top, (qreal)(double)sizerec/ca->getAx(), (qreal)(double)sizerec/ca->getAx());// grösse und position des zu färbenden bereiches errechnet
                    p.fillRect(square, QBrush(QColor(0,0,0)));

                }
                if(ca->getValue(i-1,j-1) == 4)
                {
                    qreal left = (qreal)((double)sizerec/ca->getAx()*j-(double)sizerec/ca->getAx());
                    qreal top  = (qreal)((double)sizerec/ca->getAx()*i-(double)sizerec/ca->getAx());
                    QRectF square(left, top, (qreal)(double)sizerec/ca->getAx(), (qreal)(double)sizerec/ca->getAx());// grösse und position des zu färbenden bereiches errechnet
                    p.fillRect(square, QBrush(QColor(200,100,0)));
                }

            }

        }
    }
    else{ //folgendes für hunter game, unterschiedliche Farben für unterschiedliche Elemente
        for(int i=1; i <= ca->getAx(); i++)
        {
            for(int j=1; j <= ca->getAx(); j++)
            {
                if(ca->getValueHunter(i-1,j-1) == 3)//food
                {
                    qreal left = (qreal)((double)sizerec/ca->getAx()*j-(double)sizerec/ca->getAx());
                    qreal top  = (qreal)((double)sizerec/ca->getAx()*i-(double)sizerec/ca->getAx());
                    QRectF square(left, top, (qreal)(double)sizerec/ca->getAx(), (qreal)(double)sizerec/ca->getAx());// grösse und position des zu färbenden bereiches errechnet
                    p.fillRect(square, QBrush(QColor(140,157,87)));

                }
                if(ca->getValueHunter(i-1,j-1) == 1)//victim
                {
                    qreal left = (qreal)((double)sizerec/ca->getAx()*j-(double)sizerec/ca->getAx());
                    qreal top  = (qreal)((double)sizerec/ca->getAx()*i-(double)sizerec/ca->getAx());
                    QRectF square(left, top, (qreal)(double)sizerec/ca->getAx(), (qreal)(double)sizerec/ca->getAx());// grösse und position des zu färbenden bereiches errechnet
                    p.fillRect(square, QBrush(QColor(255,255,0)));
                }
                if(ca->getValueHunter(i-1,j-1) == 2)//hunter
                {
                    qreal left = (qreal)((double)sizerec/ca->getAx()*j-(double)sizerec/ca->getAx());
                    qreal top  = (qreal)((double)sizerec/ca->getAx()*i-(double)sizerec/ca->getAx());
                    QRectF square(left, top, (qreal)(double)sizerec/ca->getAx(), (qreal)(double)sizerec/ca->getAx());// grösse und position des zu färbenden bereiches errechnet
                    p.fillRect(square, QBrush(QColor(128,0,225)));
                }

            }

        }
    }
}








/*
 *
 * Füllt alle Felder mit der Hintergrund Farbe auf
 *
 */
void GameWidget::cleanfield(QPainter &p)
{


    int sizerec = 500;


        double cellHeight = (double)sizerec/ca->getAx(); //zellengrösse

        for(int i=1; i <= ca->getAx(); i++)
        {
            for(int j=1; j <= ca->getAx(); j++)//färbt alle felder in der Hintergrundfarbe ein
            {

                    qreal left = (qreal)(cellHeight*j-cellHeight);
                    qreal top  = (qreal)(cellHeight*i-cellHeight);
                    QRectF square(left, top, (qreal)sizerec/ca->getAx(), (qreal)cellHeight);// grösse und position des zu färbenden bereiches errechnet
                    p.fillRect(square, QBrush(QColor(55,200,55)));



            }

        }




}


/*
 *
 *setzt die richtung des kopfes auf den param a wert
 *
 *
 */
void GameWidget::setDirection(int a)
{
    ca->setDirection(a);
}
//ruft die evolution funktion auf und zeichnet nach einem schritt das feld neu
void GameWidget::newGeneration()
{
    if(gamemode == 0)
    {
        ca->evolve();
    }
    else if(gamemode == 1)
    {
        /*
         * wenn false zurückgegeben wird ist das Spiel vorbei -> stoppe timer
         * und gebe den score in einem popup aus
         */
        if(!ca->evolveSnake())
        {

            timer->stop();
            QMessageBox scoreBox;
            int score = ca->getScore();
            clear();

            QString status = QString("GAME OVER!!!\n \n\n Score: %1").arg(score);
            scoreBox.setText(status);



            scoreBox.setFixedSize(1000,1000); //funktioniert nicht.. merkwürdig :/
            scoreBox.exec();

        }
        else
        {
            if(ca->getScore() > score && timer->interval() >= 75) //solange timer >= 75 bei jeder Nahrungsaufnahme, 25 ms schneller werden
            {
                score++;
                int t = timer->interval();
                timer->setInterval(t-25);


            }
        }
    }
    else if(gamemode == 2)//hunter
    {
        ca->WorldEvolutionLifePredator();

    }

    update();//neu zeichnen
}


/*
 * mouse:pressevent:
 * nur aktiv im gamemode 0
 *
 *
 */
void GameWidget::mousePressEvent(QMouseEvent *e)

{
    if(gamemode == 0)
    {

        double scaleing = (double)500/ca->getAx();//zellengrösse
        int x = floor(e->y()/scaleing); //x und y Position der Zelle bestimmen
        int y = floor(e->x()/scaleing);
        ca->setValue(x,y,1);
        update();//zeichne..
    }
    else if(gamemode==2)//gamemode hunter
    {
        double scaleing = (double)500/ca->getAx();//zellengrösse
        int x = floor(e->y()/scaleing); //x und y Position der Zelle bestimmen
        int y = floor(e->x()/scaleing);
        if(cellmode == 2)//hunter
        {
            ca->setValue(x,y,2);
            ca->setlifespanHunter(x,y,ca->defaultLifespan);
            }
        else if(cellmode == 1)//victim
        {
            ca->setValue(x,y,1);
            ca->setlifespanHunter(x,y,ca->defaultLifespan);

        }
        else if(cellmode == 3)//food
        {
            ca->setValue(x,y,3);



        }
        ca->setlifespanHunter(x,y,lifespan);
        update();
    }

}


/*
 * mouseMoveEvent:
 * alle Zellen die bei gedrückter Maustaste von dem cursor berührt werden, werden als lebendiog markiert und das feld neu gezeichnet
 *nur aktiv im gamemode 0
 */
void GameWidget::mouseMoveEvent(QMouseEvent *e)
{
    //crashes wenn mit gedrückter Maustaste aus dem Feld "herausgezeichnet" wird wurden behoben!
    //siehe Randabfragen in beiden if bedingungen.
    //Bei änderung der Pixelanzahl des Zeichenfeldes muss diese Funktion auch angepasst werden


    if(gamemode == 0 && e->y() >= 0&& e->y() <500 && e->x() >= 0 && e->x() < 500)
    {


        double scaleing = (double)500/ca->getAx();//zellengrösse
        int x = floor(e->y()/scaleing); //x und y position der Zelle bestimmen
        int y = floor(e->x()/scaleing);
        ca->setValue(x,y,1);
        update();
    }
    else if(gamemode==2 && e->y() >= 0&& e->y() <500 && e->x() >= 0 && e->x() < 500)//gamemode hunter
    {
        double scaleing = (double)500/ca->getAx();//zellengrösse
        int x = floor(e->y()/scaleing); //x und y Position der Zelle bestimmen
        int y = floor(e->x()/scaleing);
        if(cellmode == 2)//hunter
        {
            ca->setValue(x,y,2);
            }
        else if(cellmode == 1)//victim
        {
            ca->setValue(x,y,1);
        }
        else if(cellmode == 3)//food
        {
            ca->setValue(x,y,3);

        }
        ca->setlifespanHunter(x,y,lifespan);
        update();
    }

}









