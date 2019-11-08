#include "bullet.h"
#include "enemy.h"
#include "game.h"




extern Game *game;

Bullet::Bullet(directionType type)
{
    _sprite = new QPixmap(":/images/Resources/Sprites/Bullet/bullet.png");
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

}


void Bullet::moveUp()
{   
    //�������� ��������
    int topGraduate = 0;
    int ig, jg;
    ig = x() / 30;
    jg = y() / 30;
    if(game->array[ig][jg - 1] == 'a'){
        topGraduate = jg*30;
    }
    setPos(x(),y()-10);
        if (pos().y() + rect().height() < topGraduate){
            scene()->removeItem(this);
            delete this;
        }
}

void Bullet::moveDown() {
    int botGraduate = 0;
    int ig, jg;
    ig = x() / 30;
    jg = y() / 30;
    if (game->array[ig][jg+1] == 'a'){
        botGraduate = (jg+1)*30;
    }
    setPos(x(),y()+10);

        if (pos().y() == botGraduate){
            scene()->removeItem(this);
            delete this;
}
}
void Bullet::moveLeft(){
    int leftGraduate = 0;
    int ig,jg;
    ig = x() / 30;
    jg = y() / 30;
    if (game->array[ig - 1][jg] == 'a'){
        leftGraduate = ig*30;
    }
      setPos(x()-10,y());
        if (pos().x() == leftGraduate-10){
            scene()->removeItem(this);
            delete this;
        }

}

void Bullet::moveRight(){
    int rightGraduate = 0;
    int ig,jg;
    ig = x()/30;
    jg = y()/30;
    if (game->array[ig+1][jg] == 'a'){
        rightGraduate = (ig+1)*30;
    }
    qDebug() << pos().x();
    qDebug() << x();
    qDebug() << "graduate" << rightGraduate;
    qDebug() << "ig:" << ig;
    qDebug() << "jg:" << jg;
    setPos(x()+10,y());
      if (pos().x() == rightGraduate){
          qDebug() << pos().x();
          qDebug() << x();
          scene()->removeItem(this);
          delete this;
      }
}

void Bullet::move(directionType type){
    /*switch(type){
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

    }*/
}

void Bullet::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *_sprite, _currentFrame, 0, 10,10);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Bullet::boundingRect() const
{
    return QRectF(0,0,10,10);
}


