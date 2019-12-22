#ifndef ENEMY_H
#define ENEMY_H

//#include "game.h"

#include "structs.h"

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QPainter>

class Game;

class Enemy:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Enemy(int x, int y, sceneItems enemyType);
    ~Enemy();
    int damage();
    bool moveUp();
    bool moveDown();
    bool moveLeft();
    bool moveRight();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

public slots:
    void move();
    void nextFrame();
    void getArr();

private:
    QTimer *_timer;
    QPixmap *_sprite;
    int _currentFrame;
    //Game *game;
    QPointF _position;
    char arr[30][20];

public:
    int lifes = 2 + rand() % 4;

};

#endif // ENEMY_H
