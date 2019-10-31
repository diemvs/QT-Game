#include "enemy.h"

#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h>


Enemy::Enemy(int x, int y)
{
    //int random_number_1 = rand() % 700;
    //int random_number_2 = rand() % 500;
    setPos(x, y);
    //setRect(0, 0, 20,20);
    //setPixmap(QPixmap(":/images/im.jpg")); //":/images/im.jpg"
    setRect(0, 0, 30, 30);
}

void Enemy::move()
{
    //int random_number = rand() % 5;
    int random_number = 0;
    switch(random_number) {
        case 1:
        setPos(x(), y()+5);
        if (pos().y() + rect().height() < 0 ){
            scene()->removeItem(this);
            delete this;
        }
            break;
        case 2:
        setPos(x(), y()-5);
        if (pos().y() + rect().height() < 0){
             scene()->removeItem(this);
            delete this;
        }
            break;
        case 3:
        setPos(x()+5, y());
        if (pos().y() + rect().height() < 0){
             scene()->removeItem(this);
            delete this;
        }
             break;
         case 4:
                 setPos(x()-5, y());
                 if (pos().y() + rect().height() < 0){
                     scene()->removeItem(this);
                     delete this;
                 }
                     break;
    }
}
