#ifndef CABASE_H
#define CABASE_H
#include <string>




class CABase
{
public:
    CABase();
    ~CABase();

    int** field;
    void evolve();
    int** new_field;
    int** directionSnake;
    int** hunter_neu;
    int getAx();
    int getAy();
    void setAx(int x);
    void setAy(int y);
    int getValue(int x, int y);
    void setValue(int x, int y,int value);
    void setSize(int ax,int ay);
    void printField();
    int getNeighbor(int x,int y);
    bool evolveSnake();
    void setValueDirection(int x,int y,int value);
    void generateFood();
    void printlifetime();
    void printdirectionfield();


    void setDirection(int value);

    int getScore() const;
    void setScore(int value);




    int** lifespanHunter;  //lebenszeit für jedes feld
    int** directionHunter; //bewegungsrichtung für jedes feld


    int directions[4] = {2,4,6,8};
    int helpDirections1[3] = {4,6,8};
    int helpDirections2[3] = {2,6,8};
    int helpDirections3[3] = {2,4,8};
    int helpDirections4[3] = {2,4,6};
    int helpDirections5[2] = {2,4};
    int helpDirections6[2] = {2,6};
    int helpDirections7[2] = {2,8};
    int helpDirections8[2] = {4,6};
    int helpDirections9[2] = {4,8};
    int helpDirections10[2] = {6,8};

    bool obenFrei(int x, int y);
    bool rechtsFrei(int x, int y);
    bool untenFrei(int x, int y);
    bool linksFrei(int x, int y);


    int defaultLifespan = 10;

    void setlifespanHunter(int x, int y, int value);
    void setdirectionHunter(int x, int y, int value);
    void setstateHunter(int x, int y, int value);

    void cellEvolutionDirection(int x,int y);
    void cellEvolutionMove(int x, int y);
    void WorldEvolutionLifePredator();
    int predatorDirectNeighbour(int x,int y);  //
    int getValueHunter(int x, int y); //gibt die art der zelle (food, pred oder hunter) in feld [i][j] zurück
    void generateRandomMovement(int x, int y);
    int countCellNearby(int x, int y,int cellvalue);
    int randomNumber(int n);


    int getLifespan() const;
    void setLifespan(int value);

private:
    int ay;
    int ax;
    bool wall;
    bool eating;
    int direction;
    int score;
    int olddirection;
    int lifespan;



};
#endif // CABASE_H
