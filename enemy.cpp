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
}

