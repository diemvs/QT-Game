#include "bullet.h"
#include "enemy.h"
#include "game.h"

#include <QMessageBox>
#include <windows.h>

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

bool Bullet::collidesWithItem(const Enemy *enemy, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const
{

    int radx, rady;
    double xx, yy;
    xx = enemy->x();
    yy = enemy->y();

    radx = abs(xx+15-this->x());

    rady = abs(yy+15-this->y());
    if(radx<20 && rady<20){

        return true;
    }

    return false;
}


void Bullet::moveUp()
{   

    graduate = 0;
    ig = x() / 30;
    jg = y() / 30;
    if(game->array[ig][jg - 1] != '_'){
        graduate = jg*30;
    }
    setPos(x(),y()-10);
        if (pos().y()  < graduate || pos().y() < -100){

            game->bul.bulletList.removeOne(this);
            scene()->removeItem(this);
            deleteLater();

            return;
        }

        for(int i = 0; i < game->enemyList.size(); i++){

            if (this->collidesWithItem(game->enemyList[i])){


                game->bul.bulletList.removeOne(this);
                scene()->removeItem(this);

                deleteLater();

                if (game->enemyList[i]->damage() == 0){
                    game->enemyList.removeAt(i);
                    gameOver();
                }


                return;
            }
        }
}

void Bullet::moveDown() {

    graduate = 0;
    ig = x() / 30;
    jg = y() / 30;
    if (game->array[ig][jg+1] != '_'){
        graduate = (jg+1)*30;
    }
    setPos(x(),y()+10);
    if (pos().y() == graduate || pos().y() > 700){

        game->bul.bulletList.removeOne(this);
        scene()->removeItem(this);
        deleteLater();

        return;
    }

    for(int i = 0; i < game->enemyList.size(); i++){

        if (this->collidesWithItem(game->enemyList[i])){

            game->bul.bulletList.removeOne(this);
            scene()->removeItem(this);
            deleteLater();
            if (game->enemyList[i]->damage() == 0){
                game->enemyList.removeAt(i);
                gameOver();
            }

            return;
        }
    }




}
void Bullet::moveLeft(){
    graduate = 0;
    ig = x() / 30;
    jg = y() / 30;
    if (game->array[ig - 1][jg] != '_'){
        graduate = ig*30;
    }
    setPos(x()-10,y());
    if (pos().x() == graduate-10 || pos().x() < -100){
        game->bul.bulletList.removeOne(this);
        scene()->removeItem(this);
        deleteLater();
        return;
    }
    for(int i = 0; i < game->enemyList.size(); i++){
        if (this->collidesWithItem(game->enemyList[i])){
            //qDebug() << "bullet.cpp: enemy: " << typeid(game->enemyList[i]);
            game->bul.bulletList.removeOne(this);
            scene()->removeItem(this);
            deleteLater();
            if (game->enemyList[i]->damage() == 0){
                game->enemyList.removeAt(i);
                gameOver();
            }
            return;
        }
    }
}

void Bullet::moveRight(){
    graduate = 0;

    ig = x()/30;
    jg = y()/30;
    if (game->array[ig+1][jg] != '_'){
        graduate = (ig+1)*30;
    }
    setPos(x()+10,y());
      if (pos().x() == graduate || pos().x() > 1000){

          game->bul.bulletList.removeOne(this);
          scene()->removeItem(this);
          deleteLater();
          return;
      }
      for(int i = 0; i < game->enemyList.size(); i++){
          if (this->collidesWithItem(game->enemyList[i])){
              game->bul.bulletList.removeOne(this);
              scene()->removeItem(this);
              deleteLater();
              if (game->enemyList[i]->damage() == 0){
                  game->enemyList.removeAt(i);
                  gameOver();
              }
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

void Bullet::gameOver()
{
    if(game->enemyList.size() == 0){
        game->gameOver();
        QString gameOverText;
        gameOverText = "Congratulations! You win!\n";
        gameOverText += "Made by kiod x diemvs\n";
        gameOverText += "22.12.2019";
        QMessageBox::about(NULL, QObject::tr("Isaac"), gameOverText);
        game->close();
    }
}


