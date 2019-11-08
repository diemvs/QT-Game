#include "enemy.h"

Enemy::Enemy(int x, int y, sceneItems enemyType)
{
    _currentFrame = 0;
    setPos(x, y);
    switch(enemyType){
    case bat:{
        _sprite = new QPixmap(":/images/Resources/Sprites/Enemies/bat.png");
        break;
    }
    case skeleton:{
        _sprite = new QPixmap(":/images/Resources/Sprites/Enemies/skeleton.png");
        break;
    }
    case orc:{
        _sprite = new QPixmap(":/images/Resources/Sprites/Enemies/orc.png");
        break;
    }
    }


    _timer = new QTimer();
    connect(_timer, &QTimer::timeout, this, &Enemy::nextFrame);
    _timer->start(100);
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *_sprite, _currentFrame, 0, 30,30);
    Q_UNUSED(option);
    Q_UNUSED(widget);
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

void Enemy::nextFrame(){
    _currentFrame += 30;
        if (_currentFrame >= 90 ) _currentFrame = 0;
        this->update(0,0,30,30);
}

QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,30,30);
}
