#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>

//#include "structs.h"
//#include "enemy.h"
#include "construction.h"


class Bullet:public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QList<QGraphicsItem *> colliding_Items = collidingItems();

public:

    Bullet(directionType type);
    bool collidesWithItem(const Enemy *enemy, Qt::ItemSelectionMode mode) const;

public slots:
    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
private:
    QPixmap *_sprite;

    int _currentFrame = 0;
    int graduate = 0;
    int ig, jg;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;


};

#endif // BULLET_H
