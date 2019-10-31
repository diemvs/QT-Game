#include "bullet.h"
#include "enemy.h"
#include "game.h"

#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <QList>


extern Game *game;

Bullet::Bullet(directionType type)
{
    setRect(0, 0, 10, 10);
    QTimer *timer = new QTimer();

    switch(type){
    case UP:
        connect(timer, SIGNAL(timeout()), this, SLOT(moveUp()));
        timer->start(50);
        break;
    case DOWN:
        connect(timer, SIGNAL(timeout()), this, SLOT(moveDown()));
        timer->start(50);
        break;
    case LEFT:
        connect(timer, SIGNAL(timeout()), this, SLOT(moveLeft()));
        timer->start(50);
        break;
    case RIGHT:
        connect(timer, SIGNAL(timeout()), this, SLOT(moveRight()));
        timer->start(50);
        break;

    }
    //qDebug()<< "Shot!";
}


void Bullet::moveUp()
{   
    //Движение выстрела

    setPos(x(),y()-10);
        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
        }
}

void Bullet::moveDown() {
    setPos(x(),y()+10);

        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
}
}
void Bullet::moveLeft(){
      setPos(x()-10,y());
        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
        }

}

void Bullet::moveRight(){
    setPos(x()+10,y());
      if (pos().y() + rect().height() < 0){
          scene()->removeItem(this);
          delete this;
      }
}

void Bullet::move(directionType type){
    switch(type){
    case UP:
    setPos(x(),y()-10);
        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
            }
        break;
    case DOWN:
    setPos(x(),y()+10);
        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
    }
        break;
    case LEFT:
    setPos(x()-10,y());
        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
          }
        break;
    case RIGHT:
    setPos(x()+10,y());
        if (pos().y() + rect().height() < 0){
            scene()->removeItem(this);
            delete this;
          }
        break;

    }
}


