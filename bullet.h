#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

#include "structs.h"

class Bullet:public QObject, public QGraphicsRectItem
{
    Q_OBJECT
public:

    Bullet(directionType type);


public slots:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    void move(directionType type);
private:
    QPixmap *_sprite;
    int _currentFrame = 0;

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


};

#endif // BULLET_H
