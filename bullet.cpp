#include "bullet.h"
#include "enemy.h"
#include "game.h"

extern Game *game;

Bullet::Bullet(directionType type)
{
    _sprite = new QPixmap(":/images/Resources/Sprites/Bullet/bullet.png");
    QTimer *timer = new QTimer();

    qDebug() << colliding_Items.size();
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

bool Bullet::collidesWithItem(const Enemy *enemy, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const
{
    qDebug() << "bullet.cpp: in collideswithitem";
    int radx, rady;
    double xx, yy;
    xx = enemy->x();
    yy = enemy->y();
    qDebug() << "bullet.cpp: before radx";
    radx = abs(xx+15-this->x());
    qDebug() << "bullet.cpp: before rady";
    rady = abs(yy+15-this->y());
    if(radx<20 && rady<20){
        qDebug() << "bullet.cpp: exit from collideWithItem with true";
        return true;
    }
    qDebug() << "bullet.cpp: exit from collideWithItem with false";
    return false;
}


void Bullet::moveUp()
{   
    qDebug() << "bullet.cpp: in moveUp";
    graduate = 0;
    ig = x() / 30;
    jg = y() / 30;
    if(game->array[ig][jg - 1] != '_'){
        graduate = jg*30;
    }
    setPos(x(),y()-10);
        if (pos().y()  < graduate || pos().y() < -100){
            qDebug() << "bullet.cpp: in if moveUp.";
            game->bul.bulletList.removeOne(this);
            scene()->removeItem(this);
            deleteLater();
            qDebug() << "bullet.cpp: exit from moveUp";
            return;
        }

        for(int i = 0; i < game->enemyList.size(); i++){
            qDebug() << "bullet.cpp: in for enemyList moveUp";
            if (this->collidesWithItem(game->enemyList[i])){
                qDebug() << "Woooohooo!!!!";

                game->bul.bulletList.removeOne(this);
                scene()->removeItem(this);

                deleteLater();

                if (game->enemyList[i]->damage() == 0){
                    game->enemyList.removeAt(i);
                }

                qDebug() << "bullet.cpp: exit from for enemyList moveUp";
                return;
            }
        }
}

void Bullet::moveDown() {
    qDebug() << "bullet.cpp: in moveDown";
    graduate = 0;
    ig = x() / 30;
    jg = y() / 30;
    if (game->array[ig][jg+1] != '_'){
        graduate = (jg+1)*30;
    }
    setPos(x(),y()+10);
    if (pos().y() == graduate || pos().y() > 700){
        qDebug() << "bullet.cpp: in if moveDown";
        game->bul.bulletList.removeOne(this);
        scene()->removeItem(this);
        deleteLater();
        qDebug() << "bullet.cpp: exit from moveDown";
        return;
    }
    //Qt::ItemSelectionMode mode;

    for(int i = 0; i < game->enemyList.size(); i++){
        qDebug() << "bullet.cpp: in for enemyList moveDown";
        if (this->collidesWithItem(game->enemyList[i])){
            qDebug() << "Woooohooo!!!!";
            game->bul.bulletList.removeOne(this);
            scene()->removeItem(this);
            deleteLater();
            if (game->enemyList[i]->damage() == 0){
                game->enemyList.removeAt(i);
            }
            qDebug() << "bullet.cpp: exit from for enemyList moveDown";
            return;
        }
    }


        //qDebug() << colliding_Items.size();
        /*if(colliding_Items.size() != 0){
            qDebug()<< colliding_Items.first();
        }*/

}
void Bullet::moveLeft(){
    qDebug() << "bullet.cpp: in moveLeft";
    graduate = 0;
    ig = x() / 30;
    jg = y() / 30;
    if (game->array[ig - 1][jg] != '_'){
        graduate = ig*30;
    }
    setPos(x()-10,y());
    if (pos().x() == graduate-10 || pos().x() < -100){
        qDebug() << "bullet.cpp: in if moveLeft.";
        game->bul.bulletList.removeOne(this);
        scene()->removeItem(this);
        deleteLater();
        qDebug() << "bullet.cpp: exit from moveLeft";
        return;
    }

    //qDebug() << "bullet.cpp: enemyList.size():" << game->enemyList.size();
    //Qt::ItemSelectionMode mode;

    /*if(this->collidingItems().isEmpty()){
        qDebug() << "bullet.cpp: no collision";
    } else{
        qDebug() << "bullet.cpp: collision!!!";
    }*/
    for(int i = 0; i < game->enemyList.size(); i++){
        qDebug() << "bullet.cpp: in for enemyList moveLeft";
        if (this->collidesWithItem(game->enemyList[i])){
            qDebug() << "Woooohooo!!!!";
            //qDebug() << "bullet.cpp: enemy: " << typeid(game->enemyList[i]);
            game->bul.bulletList.removeOne(this);
            scene()->removeItem(this);
            deleteLater();
            if (game->enemyList[i]->damage() == 0){
                game->enemyList.removeAt(i);
            }
            qDebug() << "bullet.cpp: exit from for enemyList moveLeft";
            return;
        }
    }

       /* QList<QGraphicsItem *> listOfCollides = collidingItems();
        qDebug() << "bullet.cpp: size of list:" << listOfCollides.size();
        for(int i = 0, n = listOfCollides.size(); i < n; i++){
            if(typeid(*(listOfCollides[i])) == typeid(Enemy)){
                qDebug() << "Colliding";

            }
            delete listOfCollides[i];
            delete this;
        } */


}

void Bullet::moveRight(){
    qDebug() << "bullet.cpp: in moveRight";

    graduate = 0;

    ig = x()/30;
    jg = y()/30;
    if (game->array[ig+1][jg] != '_'){
        graduate = (ig+1)*30;
    }
    setPos(x()+10,y());
      if (pos().x() == graduate || pos().x() > 1000){
          qDebug() << "bullet.cpp: in if moveRight.";
          //qDebug() << pos().x();
          //qDebug() << x();
          game->bul.bulletList.removeOne(this);
          scene()->removeItem(this);
          deleteLater();
          qDebug() << "bullet.cpp: exit from moveRight";
          return;
      }
      for(int i = 0; i < game->enemyList.size(); i++){
          qDebug() << "bullet.cpp: in for enemyList moveRight";
          if (this->collidesWithItem(game->enemyList[i])){
              qDebug() << "Woooohooo!!!!";
              game->bul.bulletList.removeOne(this);
              scene()->removeItem(this);
              deleteLater();
              if (game->enemyList[i]->damage() == 0){
                  game->enemyList.removeAt(i);
              }
              qDebug() << "bullet.cpp: exit from for enemyList moveRight";
              return;
          }
      }
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


