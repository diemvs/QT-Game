#ifndef GAME_H
#define GAME_H


#include <QGraphicsView>
#include <QWidget>
#include <QGraphicsScene>

#include <iostream>
#include <fstream>

#include "player.h"
#include "score.h"

using namespace std;

class Game: public QGraphicsView{

public:
    Game(QWidget * parent=nullptr);

    Player *player;
    Score *score;
    QGraphicsScene *gameScene;
private:
    void _level(string path);
    void _levelGeneration();

private:
    char array[30][20];
    QTimer _timer;


};

#endif // GAME_H