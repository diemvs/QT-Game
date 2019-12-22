#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>
#include <iostream>
#include <fstream>
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QKeyEvent>

//#include "enemy.h"
#include "player.h"
#include "score.h"
#include "bullist.h"
//#include "construction.h"

//#include "structs.h"

using namespace std;

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=nullptr);
    bulList bul;
    void gameOver();
    //QList<enemy> enemyList;
public:
    Player *player;
    Score *score;
    QGraphicsScene *gameScene;
    char array[30][20];
    QList<Enemy *> enemyList;
    int* randomDigits = new int[100];
private:
    void _level(string path);
    void _levelGeneration();


private:
    QTimer _timer;
    int _countOfUnderSpaces = 0;
    int _countOfEnemies = 0;

};

#endif // GAME_H


