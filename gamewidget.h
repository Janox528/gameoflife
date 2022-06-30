#ifndef GAMEWIDGET_H
#define GAMEWIDGET_H

#include <QWidget>
#include <cabase.h>
#include <iostream>
#include <QTimer>
#include <string>


using std::cout;

class GameWidget : public QWidget
{
    Q_OBJECT
public:
    void test();
    explicit GameWidget(QWidget *parent = nullptr);
    void cleanfield(QPainter &p);
    int getUniverseSize();
    void PrepareFieldSnake();


    int getGamemode() const;
    void setGamemode(int value);


    void setCellMode(int n);
    int getCellMode();

signals:

public slots:
    void startGame();
    void stopGame();
    void clear();
    void setTimerIntervall(int i);
    void setUniverseSize(int x);
    void saveGame();
    void loadGame();
    void newGeneration();
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void randomValues();
    void setDirection(int a);
    void prepareHunter();
    void setLifespan(int x);





private:
    QTimer* timer;
    int worldSize;
    int gamemode;
    int score;
    int intervall;

    int lifespan;
    int cellmode;  // 0 = food  1 = victim  2=hunter



};

#endif // GAMEWIDGET_H





