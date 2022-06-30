/*
 *
 * Autoren: Rene Meier,Adrian Musella, Fanjun
 * Version:16.01.2018
 *
 */
#include <iostream>
#include <cabase.h>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <list>
#include <QtCore>
#include <QDebug>



using namespace std;



/*
 * return: int ax
 * Gibt die x länge des Feldes zurück
 *
 */
int CABase::getAx()
{
    return ax;
}
/*
 * return: int ay
 * Gibt die y länge des Feldes zurück
 *
 */
int CABase::getAy()
{
    return ay;
}
/*
 * param: int x
 * Setzt die ax Variable(Feldlänge) auf den wert x
 *
 */
void CABase::setAx(int x)
{
    ax = x;
}
/*
 * param: int y
 * Setzt die ay Variable(Feldlänge) auf den wert y
 *
 */
void CABase::setAy(int y)
{
    ay = y;
}
/*
 * return: int wert
 * param: int x,int y
 * Gibt den Wert im Feld an Position x,y zurueck(0 für tot und 1 für lebend)
 *
 */
int CABase::getValue(int x, int y)
{
    return field[x][y];
}
/*
 * param: int x,inty,int value
 * Setzt den Wert im Feld an den Koordinaten x,y auf value.
 * 0 für tot 1 für lebendig
 *
 */
void CABase::setValue(int x, int y,int value)// fragen ob 0 als 1 zählt bei der eingabe
{
    field[x][y] = value;
    //cout <<x<<","<<y<<": "<<value<<"\n";
}


/*
 *
 * Gibt das Array field auf der Konsole aus.
 * Ein totes Feld wird leer dargestellt und ein lebendes Feld durch einen * dargestellt
 * Erzeugt einen Rand um das Feld( * * *) und printet das Usermenü
 *
 */
void CABase::printField()
{
    cout << "Game of life" <<"\n\n";
    cout << "X:"<<ax<<"    Y:"<<ay<<"\n\n\n\n";
    for(int i = 0;i<ax;i++) //obere Feldgrenze
    {
        cout <<"* ";
    }
    for(int i= 0; i <ax ;i++)//x schleife
    {
        cout << "* \n"; //rechte feldgrenze
        for(int j = 0;j<ay;j++)//y schleife
        {
            if(j == 0)
            {
                cout <<"* "; //linke feldgrenze
            }
            if(field[i][j] == 0)
            {
                cout <<"  ";//leertaste als totes Feld
            }
            else if(field[i][j] == 1)
            {
                cout << "* ";//* repräsentiert ein lebendes Feld
            }
            else
            {
                cout <<"- ";
            }
        }

    }
    cout <<"*\n";
    for(int i = 0;i<=ax;i++)//untere Feldgrenze
    {
        cout <<"* ";
    }
    //usermenü
    cout << "\n";
    cout << "0. Exit \n";
    cout << "1. Evolve \n";
    cout << "2. Set alive cell \n";
    cout << "3. Reprint \n";
    cout << "4. Resize \n";
    cout << "5. Random test values";
}


/*
 * param: int x,y als Koordinaten im Feld
 * return: int count
 * Gibt die Anzahl an Nachbarn zurueck die Zelle x,y besitzt.
 * Die welt ist in einer "Donat" Form, sodass der bei der Weltbegrenzung auf die andere Seite übergegangen wird. -> nachbar von 0,0 ist zb ax-1,ay-1
 *
 */
int CABase::getNeighbor(int x, int y)
{
    int count = 0;

    //oben
    if(x > 0)
    {
        if(getValue(x-1,y) == 1)
        {
            count ++;

        }
    }
    else if(getValue(ax-1,y) == 1)
    {
        count++;
    }

    //oben rechts
    if( x > 0)
    {
        if(y<ay-1)
        {
            if(getValue(x-1,y+1) == 1)
            {
                count ++;
            }
        }
        else if(getValue(x-1,0) == 1)
        {
            count ++;
        }
    }
    else if(y<ay-1)
    {
        if(getValue(ax-1,y+1) == 1)
        {
            count++;
        }

    }
    else if(getValue(ax-1,0) == 1)
    {
        count ++;
    }

    //rechts
    if(y<ay-1)
    {
        if(getValue(x,y+1) == 1)
        {
            count++;
        }

    }
    else if(getValue(x,0) == 1)
    {
        count++;
    }
    //rechts unten
    if(x<ax-1 )
    {
        if(y<ay-1)
        {
            if(getValue(x+1,y+1) == 1)
            {
                count++;
            }
        }
        else if(getValue(x+1,0) == 1)
        {
            count++;
        }
    }
    else if(y<ay-1)
    {
        if(getValue(0,y+1) == 1)
        {
            count++;
        }
    }
    else if(getValue(0,0) == 1)
    {
        count++;
    }


    //unten
    if(x<ax-1  )
    {
        if(getValue(x+1,y) == 1)
        {
            count++;
        }
    }
    else if(getValue(0,y) == 1)
    {
        count++;
    }

    //unten links
    if( y > 0  )
    {
        if(x<ax-1)
        {
            if(getValue(x+1,y-1) == 1)
            {
                count++;
            }
        }
        else if(getValue(0,y-1) == 1)
        {
            count++;
        }
    }
    else if(x<ax-1)
    {
        if(getValue(x+1,ay-1) == 1)
        {
            count++;
        }
    }
    else if(getValue(0,ay-1) == 1)
    {
        count++;
    }


    //links
    if(y > 0)
    {
        if(getValue(x,y-1) == 1)
        {
            count++;
        }
    }
    else if(getValue(x,ay-1) == 1)
    {
        count++;
    }
    //links oben
    if(x > 0 )
    {
        if(y>0)
        {
            if(getValue(x-1,y-1) == 1 )
            {
                count++;
            }
        }
        else if(getValue(x-1,ay-1) == 1 )
        {
            count++;
        }
    }
    else if(y>0)
    {
        if(getValue(ax-1,y-1) == 1 )
        {
            count++;
        }
    }
    else if(getValue(ax-1,ay-1) == 1 )
    {
        count++;
    }


    return count;
}


/*
 * evolve funktion für das Snake Spiel
 * macht einen Zeitschritt im Spiel
 *
 * Werte: 0= nichts, 1 = Kopf, 2 = Body, 3 = schwanz, 4 = food
 *
 */
bool CABase::evolveSnake()
{
    eating = false;
    new_field = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        new_field[j] = new int[ay];
    }

    //mit 0 füllen(tot)
    for(int i =0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            new_field[i][j] = 0;
        }
    }

    for(int i=0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            if(field[i][j] != 0 && field[i][j] != 4) //wenn ein Schlangenteil auf dem Feld ist..
            {
                int newi,newj;
                //nach unten
                if(directionSnake[i][j] == 4)
                {
                    newi = i;
                    newj = j-1;
                }
                //nach links
                else if(directionSnake[i][j] == 8)
                {
                    newi = i-1;
                    newj = j;
                }
                //nach oben
                else if(directionSnake[i][j] == 6)
                {
                    newi = i;
                    newj = j+1;
                }
                //nach rechts
                else if(directionSnake[i][j] == 2)
                {
                    newi = i+1;
                    newj = j;
                }


                //hat die welt eine wand?
                if(wall == true)
                {

                    //aus dem Spielfeld, return false
                    if(newi <= -1 || newj <= -1 || newi>=ax || newj >= ay)
                    {

                        return false;
                    }
                }

                //Handelt es sich um einen Kopf? wenn ja kollisionsabfrage
                if(field[i][j] == 1)
                {



                        //food
                        if(field[newi][newj] == 4)
                        {
                            eating = true;


                            field[newi][newj] = 0;

                        }
                        //body getroffen, return false
                        else if(field[newi][newj] == 2)
                        {

                            return false;
                        }
                        //schwanz
                        else if(field[newi][newj] == 3)
                        {
                            //hat die schlange die runde davor gegessen?
                            //Wenn ja wird sich der schwanz nicht weiterbewegen und das spiel endet

                            //HINWEIS: dieses Szenario kann in der Momentanen Version des Spiels nicht entstehen.
                            //Dieser Teil war dazu gedacht, wenn es Food gibt welches mehr als 1 Runde die Schlange wachsen lässt.
                            //Dennoch habe ich es nicht auskommentiert, da es das Spiel nicht beeinflusst.
                            if(eating)
                            {

                                return false;
                            }
                        }


                }








            }
        }
    }
    //noch einmal alle Elemente durchgehen, jetzt werden die Schlangenelemente bewegt und das Food in die neue Generation übertragen
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            if(field[i][j] != 0)
            {
                int newi,newj;
                //nach unten
                if(directionSnake[i][j] == 4)
                {
                    newi = i;
                    newj = j-1;
                }
                //nach links
                else if(directionSnake[i][j] == 8)
                {
                    newi = i-1;
                    newj = j;
                }
                //nach oben
                else if(directionSnake[i][j] == 6)
                {
                    newi = i;
                    newj = j+1;
                }
                //nach rechts
                else if(directionSnake[i][j] == 2)
                {
                    newi = i+1;
                    newj = j;
                }
                //schwanz verlängert den body wenn gegessen wurde
                if(field[i][j] == 3)
                {

                    //gegessen?
                    if(eating == true)
                    {
                        score++;
                        new_field[newi][newj] = 2;
                        new_field[i][j] = 3;
                    }
                    else
                    {
                        new_field[newi][newj] = 3;
                    }
                }
                //head
                else if(field[i][j] == 1)
                {
                    new_field[newi][newj] = field[i][j];
                    directionSnake[newi][newj] = direction; //setze direction auf neues feld
                }
                //body
                else if(field[i][j] == 2)
                {
                    new_field[newi][newj] = field[i][j];
                }
                //food bewegt sich nicht
                else if(field[i][j] == 4)
                {
                    new_field[i][j] = 4;
                }
            }

        }
    }




    //new_field Werte in field kopieren

    for(int i=0;i<ax;i++)
    {
        for(int j =0;j<ay;j++)
        {
            field[i][j] = new_field[i][j];
        }
    }
    if(eating)
    {
        generateFood();
    }

    //Speicherplatz von new_array wieder freigeben
    for(int i =0;i<ax;i++) //lösche altes array
    {
        delete[] new_field[i];// lösche 2. Dimension
    }
    delete[] new_field;//lösche Pointer array
    return true;

}


//setzt directionSnake an den Positionen x,y auf Value {2,4,6,8}
void CABase::setValueDirection(int x,int y,int value)
{
    directionSnake[x][y]=value;
}


//in einer zufälligen Zelle, die keine Schlangenteile enthält, wird ein Food erstellt.
void CABase::generateFood()
{
    srand (time(NULL));//neuer seed
    bool foundlocation = false;
    int x,y;
    while(foundlocation == false)//erst übernehmen wenn das food nicht auf der schlange landet
    {
        x = rand()%(ay-1); //randomzahl zw 0 und ay-1
        y = rand()%(ax-1);

        if(field[x][y] == 0)
        {
            foundlocation = true;

        }
    }
    field[x][y] = 4;




}


//printet lifespanHunter Array in die Konsole, nur zum lifetime Debuggen
void CABase::printlifetime()
{
    string s = "";
    for(int i=0;i<ax;i++)
    {
        for(int j = 0;j<ay;j++)
        {
            s.append(to_string( lifespanHunter[i][j]-0));
            s.append(" ");
        }
        cout << s;
        cout << "\n";
        s = "";
    }
    cout << "//////////////////////////////////////////////////////// \n \n n";
}


//printet directionHunter Array in die Konsole, nur zum lifetime Debuggen
void CABase::printdirectionfield()
{
    string s = "";
    for(int i=0;i<ax;i++)
    {
        for(int j = 0;j<ay;j++)
        {
            s.append(to_string( directionHunter[i][j]-0));
            s.append(" ");
        }
        cout << s;
        cout << "\n";
        s = "";
    }
    cout << "//////////////////////////////////////////////////////// \n \n n";
}

//generiert nummer zwischen 0 und n
int CABase::randomNumber(int n)
{
    if(n == 1)
    {
        return 0;
    }
        int x = rand()%(n-1); //randomzahl zw 0 und ay-1




    return x;
}


//getter für lifespan
int CABase::getLifespan() const
{
    return lifespan;
}



//setter für lifespan
void CABase::setLifespan(int value)
{
    lifespan = value;
}

//setzt direction auf den übergebenen wert {2,4,6,8}
void CABase::setDirection(int value)
{
    direction = value;
}


//getter für score
int CABase::getScore() const
{
    return score;
}


//setter für score
void CABase::setScore(int value)
{
    score = value;
}



/*
 * evolve macht einen Zeitschritt im Spiel des Lebens nach den Regeln aus der Aufgabenstellung
 */
void CABase::evolve()
{

    new_field = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        new_field[j] = new int[ay];
    }



    //new_field mit den werten nach dem evolve Schritt füllen
    for(int i=0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            if(getValue(i,j)== 0)//Zelle tot
            {

                if(getNeighbor(i,j) == 3)
                {
                    new_field[i][j] = 1;//wiedergebohren
                }
                else
                {

                    new_field[i][j] = 0;//bleibt tot

                }
            }
            else if(getValue(i,j)==1)//Zelle lebt
            {
                if(getNeighbor(i,j) < 2)
                {
                    new_field[i][j] = 0;//stirbt weil weniger als 2 Nachbarn(Unterbevölkerung)
                }
                else if(getNeighbor(i,j) > 3)
                {
                    new_field[i][j] = 0;//stirbt weil mehr als 3 Nachbarn(Überbevölkerung)
                }
                else
                {
                    new_field[i][j] = 1;//bleibt am leben weil 2-3 Nachbarn vorhanden sind
                }
            }
            else
            {
                cout << "!!!!ERROR!!!!\n";
                cout <<"Zell: ["<<i<<","<<j<<"] is not as expected";
            }
        }
    }

    //new_field Werte in field kopieren

    for(int i=0;i<ax;i++)
    {
        for(int j =0;j<ay;j++)
        {
            field[i][j] = new_field[i][j];
        }
    }


    //Speicherplatz von new_array wieder freigeben
    for(int i =0;i<ax;i++) //lösche altes array
    {
        delete[] new_field[i];// lösche 2. Dimension
    }
    delete[] new_field;//lösche Pointer array
}
/*
 * param:int ax, int ay
 * regeneriert ein neues Feld der grösse ax,ay und füllt diese mit 0(tot)
 *
 *
 *
 */
void CABase::setSize(int x, int y)
{
    for(int i =0;i<ax;i++) //lösche altes array
    {
        delete[] field[i];// lösche 2. Dimension
    }
    delete[] field;//lösche Pointer array


    field = new int*[x];//Pointer array

    for(int j = 0;j<x;j++)// 2. Dimension
    {
        field[j] = new int[y];
    }

    for(int i =0;i<x;i++) // mit 0 füllen
    {
        for(int j=0;j<y;j++)
        {
            field[i][j] = 0;
        }
    }
    ay =y;
    ax= x;



    //neuerstellung aller hidden arrays für milestone 3:

    //new_field wird hier für platz reservierungen benutzt
    new_field = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        new_field[j] = new int[ay];
    }

    //initialisierung mit 1 und 0,1 steht für eine nicht tote Zelle
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            if (field[i][j] != 0)
            {
                new_field[i][j] = 1;
            }
            else
            {
                new_field[i][j] = 0;
            }
        }
    }


    //direction array resetten...

    directionHunter = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        directionHunter[j] = new int[ay];
    }
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            directionHunter[i][j] = 0;
        }
    }

    //hunter_neu, "handle array" erstellen
    hunter_neu = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        hunter_neu[j] = new int[ay];
    }

    //mit werten aus field füllen
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            hunter_neu[i][j] = field[i][j];

        }
    }


    lifespanHunter = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        lifespanHunter[j] = new int[ay];
    }

    //mit werten aus field füllen
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            lifespanHunter[i][j] = field[i][j];

        }
    }

}



// milestone 3 ab hier



//setzt lifespanHunter array an der stelle x,y auf den wert value
void CABase::setlifespanHunter(int x, int y, int value){
    lifespanHunter[x][y] = value; // lebensdauer für die zelle.
}


//setzt directionHunter an der Stelle x,y aufden Wert value
void CABase::setdirectionHunter(int x, int y, int value){
    directionHunter[x][y] = value;
}



//gibt die anzahl derbenachbarten zellen zurück mit dem wert cellvalue
int CABase::countCellNearby(int x,int y,int Cellvalue)
{
    int count = 0;
    if(x > 0 && field[x-1][y] == Cellvalue) //links
    {
        count++;
    }
    if(y > 0 && field[x][y-1] == Cellvalue)//unten
    {
        count++;
    }
    if(x <ax-1 && field[x+1][y] == Cellvalue)//rechts
    {
        count++;
    }
    if(y < ay-1  && field[x][y+1] == Cellvalue)//oben
    {
        count++;
    }

    //diagonale bewegungen möglich?

//    if(x > 0 && y > 0 &&field[x-1][y-1] == Cellvalue)//links unten
//    {
//        count++;
//    }
//    if(x > 0 && y < ay-1 && field[x-1][y+1] == Cellvalue)//links oben
//    {
//        count++;
//    }
//    if(y > 0 && x < ax-1 && field[x+1][y-1] == Cellvalue)//rechts unten
//    {
//        count++;
//    }
//    if(y < ay-1 && x < ax-1 && field[x+1][y+1] == Cellvalue)//rechts oben
//    {
//        count++;
//    }

    return count;

}


//oben von new_field[x][y] frei?return: true/false
bool CABase::obenFrei(int x, int y){
    if (new_field[x-1][y] == 0){
        return false;
    }else{
        return true;
    }
}


//rechts von new_field[x][y] frei?return: true/false
bool CABase::rechtsFrei(int x, int y){
    if (new_field[x][y+1] == 0){
        return false;
    }else{
        return true;
    }
}


//unten von new_field[x][y] frei?return: true/false
bool CABase::untenFrei(int x, int y){
    if (new_field[x+1][y] == 0){
        return false;
    }else{
        return true;
    }
}


//links von new_field[x][y] frei?return: true/false
bool CABase::linksFrei(int x, int y){
    if (new_field[x][y-1] == 0){
        return false;
    }else{
        return true;
    }
}

// setzt die Bewegungsrichtungen der Zellen nach den Kriterien der Aufgabe 1a, Milestone 3
void CABase::cellEvolutionDirection(int x,int y)
{

    //neuer code:
    //new field benutzen um zu merken ob ein feld bereits blockiert es durch einen zuvor gezogenes lebewesen, damit nicht 2 auf das gleiche feld ziehen
    //randomnumber(int n) gibt einen zufälligen wert von 1 bis n zurück

    int randomIndexDirection;




    ///////////////////////////////////////////////////////////////////////////

    if ((field[x][y] == 0) || (field[x][y] == 3))
    { //feld leer oder food -> nichts machen
        return;
    }

    if (field[x][y] == 2)
    { //ist das feld ein jäger?
        if(countCellNearby(x,y,1) != 0)
        { // ist mind. ein victim in reichweite?

            if(x< ax-1 && field[x+1][y] == 1 && new_field[x+1][y] != 2)
            { //victim unten?
                directionHunter[x][y] = 2;
                new_field[x][y] = 0;

                new_field[x+1][y] = 2; // "hunter-sperre"

                //qDebug() << "Feld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
            else if(y>0 && field[x][y-1] == 1 && new_field[x][y-1] != 2)
            { //victim links?
                directionHunter[x][y] = 4;
                new_field[x][y] = 0;

                new_field[x][y-1] = 2; // "hunter-sperre"

                //qDebug() << "Feld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
            else if(x>0 && field[x-1][y] == 1 && new_field[x-1][y] != 2)
            { //victim oben?
                directionHunter[x][y] = 8;
                new_field[x][y] = 0;

                new_field[x-1][y] = 2; // "hunter-sperre"

                //qDebug() << "Feld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
            else if(y< ay-1 && field[x][y+1] == 1 && new_field[x][y+1] != 2)
            { //victim rechts
                directionHunter[x][y] = 6;
                new_field[x][y] = 0;

                new_field[x][y+1] = 2; // "hunter-sperre"

               // qDebug() << "Feld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
            else
            {
                //qDebug() <<"Error: Jäger findet Beute nicht,obwohl sie in Reichweite ist";


            }


        }
        else
        {
            //qDebug() << "Suche Random feld für Jäger";
            //qDebug() << "unten: "<<new_field[x-1][y];

            //suche leere Zellen
            int* N;
            N = new int [4];
            int count = 0;
            if(x >0 && new_field[x-1][y] == 0)//unten
            {
                N[count] = 8;
                count++;
                //qDebug() << "Unten Frei";
            }
            if(x < ax-1 && new_field[x+1][y] == 0)//oben
            {
                N[count] = 2;
                count++;
                //qDebug() << "oben Frei";
            }
            if(y >0 && new_field[x][y-1] == 0)//rechts
            {
                N[count] = 4;
                count++;
                //qDebug() << "rechts Frei";
            }
            if(y < ay-1 && new_field[x][y+1] == 0)//links
            {
                N[count] = 6;
                count++;
                //qDebug() << "links Frei";
            }
            if(count == 0)
            {
                directionHunter[x][y] = 0;
            }else{
                int choose = randomNumber(count+1);

                //qDebug() << "randomzahl:" << choose;
                choose = N[choose];
                delete[] N;
                //qDebug() <<"Choose: "<<choose;


                directionHunter[x][y] = choose;
                if(choose == 2)//neuen platz reservieren
                {
                    new_field[x+1][y] = field[x][y];
                }
                else if(choose == 4)
                {
                    new_field[x][y-1] = field[x][y];
                }
                else if(choose == 6)
                {
                    new_field[x][y+1] = field[x][y];
                }
                else if(choose == 8)
                {
                    new_field[x-1][y] = field[x][y];
                }
                new_field[x][y] = 0;
               }

        }
    }

    if (field[x][y] == 1)
    { //ist das feld ein victim?
        if(countCellNearby(x,y,2) != 0)
        { //ist mind. ein jäger in der nähe?
            //qDebug() << "ein jäger in reichweite";
            return; //nichts tun. victim wird gefressen
        }
        if(countCellNearby(x,y,3) != 0 && countCellNearby(x,y,2) == 0)
        { //ist mindestens ein food in reichweite und kein jäger in reichweite
            if(x<ax-1 && field[x+1][y] == 3 && new_field[x+1][y] != 3)
            { //food unten?
                directionHunter[x][y] = 2;
                new_field[x][y] = 0;

                new_field[x+1][y] = 3; // "victim-sperre"

                //qDebug() << "pFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];
            }
            else if(y>0 && field[x][y-1] == 3 && new_field[x][y-1] != 3)
            { //food links?
                directionHunter[x][y] = 4;
                new_field[x][y] = 0;

                new_field[x][y-1] = 3; // "victim-sperre"

                //qDebug() << "qFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
            else if(x>0 && field[x-1][y] == 3 && new_field[x-1][y] != 3)
            { //food oben?
                directionHunter[x][y] = 8;
                new_field[x][y] = 0;

                new_field[x-1][y] = 3; // "victim-sperre"

                //qDebug() << "rFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
            else if(y< ay-1 && field[x][y+1] == 3 && new_field[x][y+1] != 3)
            { //food rechts
                directionHunter[x][y] = 6;
                new_field[x][y] = 0;

                new_field[x][y+1] = 3; // "hunter-sperre"

                //qDebug() << "sFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

            }
        }
        else
        { // sonst suche ein freies feld und gehe hin
            //qDebug() << "Suche Random feld für Jäger";
            //qDebug() << "unten: "<<new_field[x-1][y];

            //suche leere Zellen
            int* N;
            N = new int [4];
            int count = 0;
            if(x >0 && new_field[x-1][y] == 0)//unten
            {
                N[count] = 8;
                count++;
                //qDebug() << "Unten Frei";
            }
            if(x < ax-1 && new_field[x+1][y] == 0)//oben
            {
                N[count] = 2;
                count++;
                //qDebug() << "oben Frei";
            }
            if(y >0 && new_field[x][y-1] == 0)//rechts
            {
                N[count] = 4;
                count++;
                //qDebug() << "rechts Frei";
            }
            if(y < ay-1 && new_field[x][y+1] == 0)//links
            {
                N[count] = 6;
                count++;
                //qDebug() << "links Frei";
            }
            if(count == 0)
            {
                return;//kein Zug möglich
            }
            int choose = randomNumber(count+1);

            //qDebug() << "randomzahl:" << choose;
            choose = N[choose];
            delete[] N;
            //qDebug() <<"Choose: "<<choose;


            directionHunter[x][y] = choose;
            if(choose == 2)//neuen platz reservieren
            {
                new_field[x+1][y] = field[x][y];
            }
            else if(choose == 4)
            {
                new_field[x][y-1] = field[x][y];
            }
            else if(choose == 6)
            {
                new_field[x][y+1] = field[x][y];
            }
            else if(choose == 8)
            {
                new_field[x-1][y] = field[x][y];
            }
            new_field[x][y] = 0;
        }
    }



//    else if (x == 0){ //feld liegt auf oberem rand?
//        if (new_field[1][y] == 0){ //unter dem feld ist platz?
//            directionHunter[x][y] = 2; //nach unten gehen
//            new_field[1][y] = 1; //neues feld für andere zellen blockieren
//            new_field[x][y] = 0; //altes feld für andere zellen wieder freigeben
//            qDebug() << "ajFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];
//        }else{
//            directionHunter[x][y] = 0; //stehen bleiben
//        }
//    }

//    else if (y == ay-1){ //feld liegt auf rechtem rand?
//        if (new_field[x][ay-2] == 0){ //links vom feld ist platz?
//            directionHunter[x][y] = 4; //nach links gehen
//            new_field[x][ay-2] = 1; //neues feld für andere zellen blockieren
//            new_field[x][y] = 0; //altes feld für andere zellen wieder freigeben
//            qDebug() << "akFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

//        }else{
//            directionHunter[x][y] = 0; //stehen bleiben
//        }
//    }

//    else if (x == ax-1){ //feld liegt auf unterem rand?
//        if (new_field[ax-2][y] == 0){ //über dem feld ist platz?
//            directionHunter[x][y] = 8; //nach oben gehen
//            new_field[ax-2][y] = 1; //neues feld für andere zellen blockieren
//            new_field[x][y] = 0; //altes feld für andere zellen wieder freigeben
//            qDebug() << "alFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

//        }else{
//            directionHunter[x][y] = 0; //stehen bleiben
//        }
//    }

//    else if (y == 0){ //feld liegt auf unterem rand?
//        if (new_field[x][1] == 0){ //rechts vom feld ist platz?
//            directionHunter[x][y] = 6; //nach rechts gehen
//            new_field[x][1] = 1; //neues feld für andere zellen blockieren
//            new_field[x][y] = 0; //altes feld für andere zellen wieder freigeben
//            qDebug() << "amFeld " << x << " " << y << " " << "Wert " << directionHunter[x][y];

//        }else{
//            directionHunter[x][y] = 0; //stehen bleiben
//        }
//    }

}



//bewegt die Zellen nach den Kriterien der Aufgabe 1b,Milestone 3
void CABase::cellEvolutionMove(int x,int y)
{
    //bewegt die zelle in ihre blickrichtung(inkl. lifespan) und löscht die direction.
    //sämtliche entscheidungen wer ziehen darf ist in die direction funktion ausgelagert

    //füllt die lebenszeit auf maximal auf, falls gefressen wurde


    int newx = -1;
    int newy = -1;
    int oldentity = 0;
    int newentity = 0;



    //links
    if (directionHunter[x][y] == 4)
    {
        oldentity = hunter_neu[x][y-1];
        hunter_neu[x][y-1] = field[x][y];
        lifespanHunter[x][y-1] = lifespanHunter[x][y];
        lifespanHunter[x][y] = 0;
        hunter_neu[x][y] = 0;
        directionHunter[x][y] = 0;
        newx = x;
        newy = y-1;
    }

    //nach oben
    if (directionHunter[x][y] == 8)
    {
        oldentity = hunter_neu[x-1][y];
        hunter_neu[x-1][y] = field[x][y];
        lifespanHunter[x-1][y] = lifespanHunter[x][y];
        lifespanHunter[x][y] = 0;
        hunter_neu[x][y] = 0;
        directionHunter[x][y] = 0;
        newx = x-1;
        newy = y;
    }


    //rechts
    if (directionHunter[x][y] == 6)
    {
        oldentity = hunter_neu[x][y+1];
        hunter_neu[x][y+1] = field[x][y];
        lifespanHunter[x][y+1] = lifespanHunter[x][y];
        lifespanHunter[x][y] = 0;
        hunter_neu[x][y] = 0;
        directionHunter[x][y] = 0;
        newx = x;
        newy = y+1;
    }


    //nach unten
    if (directionHunter[x][y] == 2)
    {
        oldentity = hunter_neu[x+1][y];
        hunter_neu[x+1][y] = field[x][y];
        lifespanHunter[x+1][y] = lifespanHunter[x][y];
        lifespanHunter[x][y] = 0;
        hunter_neu[x][y] = 0;
        directionHunter[x][y] = 0;
        newx = x+1;
        newy = y;
    }



    //wurde gefressen?


    newentity = field[x][y];
    if(newx != -1 && newy != -1)
    {
        if(oldentity == 1 && newentity == 2)//hunter frisst victim
        {
            lifespanHunter[newx][newy] = lifespan+1;
        }
        else if(oldentity == 3 && newentity == 1)
        {
            lifespanHunter[newx][newy] = lifespan+1;//victim frisst gras
        }
    }



}



//main funktion des Hunter Spiels, garantiert den Gamecycle.
//ruft für alle felder die direction und move funktion auf
//initialisiert und resettet sämtliche hidde Arrays
void CABase::WorldEvolutionLifePredator()
{



    //new_field wird hier für platz reservierungen benutzt
    new_field = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        new_field[j] = new int[ay];
    }

    //initialisierung mit 1 und 0,1 steht für eine nicht tote Zelle
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            if (field[i][j] != 0)
            {
                new_field[i][j] = 1;
            }
            else
            {
                new_field[i][j] = 0;
            }
        }
    }


    //direction array resetten...
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            directionHunter[i][j] = 0;
        }
    }

    //hunter_neu, "handle array" erstellen
    hunter_neu = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        hunter_neu[j] = new int[ay];
    }

    //mit werten aus field füllen
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            hunter_neu[i][j] = field[i][j];

        }
    }


    //für alle zellen cellEvolutionDirection ausführen
    for(int i = 0;i<ax;i++)
    {
        for(int j = 0;j<ay;j++)
        {
            cellEvolutionDirection(i,j);
        }
    }
    //printdirectionfield();
    //für alle Zellen cellEvolutionMove ausführen
    for(int i = 0;i<ax;i++)
    {
        for(int j = 0;j<ay;j++)
        {
            cellEvolutionMove(i,j);
        }
    }


    //field mit den neuen Werten aus hunter_neu kopieren
    for(int i=0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            field[i][j] = hunter_neu[i][j];

        }
    }
    delete[] hunter_neu;//hunter neu speicher freigeben


    //lifetime von jägern und gejagten um 1 reduzieren und löschen falls sie einen Wert von 0 erreichen
    for(int i=0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            if(field[i][j] != 3)
            {
                if(lifespanHunter[i][j] == 1)//lifetime = 1? dann lösche die Zelle(verhungert)
                {
                    lifespanHunter[i][j] = 0;
                    field[i][j] = 0;
                    //qDebug() << "Lifetime: "<<lifespanHunter[i][j];
                }
                else if(lifespanHunter[i][j] >=2 )//lifetime > 1 und nichtot? reduziere Lebenszeit um 1
                {
                    lifespanHunter[i][j] = lifespanHunter[i][j]-1;
                    //qDebug() << "Lifetime: "<<lifespanHunter[i][j];
                }

            }
        }

    }

    //printlifetime();






}


//getter für das hunterfield(überflüssig, es gibt bereits einen getter für field, aber so ist der name angepasst)
int CABase::getValueHunter(int x,int y){
    return field[x][y];
}


//generiert zufällige richtung für eine Zelle
void CABase::generateRandomMovement(int x, int y){
    int randomIndex = rand() % 5;
    directionHunter[x][y] = directions[randomIndex]; //setzt bewegungsrichtung auf einen zufälligen wert
}



//konstruktor initialisiert das Feld mit grösse 30,30 und füllt es mit 0(tot) in jeder Zelle
CABase::CABase()
{
    //snake default werte erstellen
    wall = true;
    eating = false;
    direction = 6;
    srand (time(NULL));//neuer seed
    lifespan = 5;
    score = 0;

    field = new int*[30];//array of pointer

    for(int j = 0;j<30;j++)//2. Dimension wird hinzugefügt
    {
        field[j] = new int[30];
    }


    //mit 0(tot) füllen

    for(int i =0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            field[i][j] = 0;
        }
    }

    ax = 30;
    ay = 30;


    //richtungs array für snake erstellen(default wert= 8)

    directionSnake = new int*[ax];//Pointer array

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        directionSnake[j] = new int[ay];
    }

    //mit 8 füllen(aufwärts)
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ax;j++)
        {
            directionSnake[i][j] = 8;
        }
    }




    // milestone 3 ab hier


    //initialisierung des lifespanHunter arrays
    lifespanHunter = new int*[ax];

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        lifespanHunter[j] = new int[ay];
    }

    //mit 0 füllen
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            lifespanHunter[i][j] = 0;
        }
    }

    // initialisierung des directionHunter Arrays
    directionHunter = new int*[ax];

    for(int j = 0;j<ax;j++)// 2. Dimension
    {
        directionHunter[j] = new int[ay];
    }


    //füllen mit 0
    for(int i =0;i<ax;i++)
    {
        for(int j=0;j<ay;j++)
        {
            directionHunter[i][j] = 0;
        }
    }












}




//Destruktor, gibt Speicherplatz wieder frei
CABase::~CABase()
{
    for(int i =0;i<ax;i++)
    {
        delete[] field[i];
    }
    delete[] field;

}
