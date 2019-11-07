#ifndef ENEMY_H
#define ENEMY_H

#include "game.h"

#include <QGraphicsRectItem>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>

class Enemy:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:
    Enemy(int x, int y);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

public slots:
    void move();
    void nextFrame();

private:
    QTimer *_timer;
    QPixmap *_sprite;
    int _currentFrame;

};

#endif // ENEMY_H
