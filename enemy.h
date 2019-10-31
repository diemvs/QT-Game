#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>

class Enemy:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy(int x, int y);

public slots:
    void move();

};

#endif // ENEMY_H
