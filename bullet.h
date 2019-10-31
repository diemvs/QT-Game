#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsRectItem>
#include <QObject>

enum directionType {
    UP, DOWN, LEFT, RIGHT
};

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

};

#endif // BULLET_H
