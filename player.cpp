#include "player.h"
#include "bullet.h"
#include "enemy.h"

#include <QDebug>
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::keyPressEvent(QKeyEvent *event)
{
    //_timerMovement->start(100);
    //выстрел
    if (event->key() == Qt::Key_Up){
        directionType type = UP;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x() + 30, y());
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Down){
        directionType type = DOWN;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x() + 30, y()+70);
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Left){
        directionType type = LEFT;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x(), y() + 30);
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Right){
        directionType type = RIGHT;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x()+70, y() +30);
        scene()->addItem(bullet);
    }
    else if(event->key() == Qt::Key_A){
        //if (pos().x() > 0)
        //setPos(x()-10, y());
        _speed.setX(-10);
        move();
        //_speed.setX(0);
    }
    else if (event->key() == Qt::Key_D){
        //if (pos().x() + 100 < 900)
        //setPos(x()+10, y());
        //qDebug() << "Key D pressed";
        _speed.setX(10);
        move();
        //_speed.setX(0);
    }
    else if (event->key() == Qt::Key_W){
        //if (pos().y() > 0)
        //setPos(x(), y()-10);
        //qDebug() << "Key W pressed";
        if(!event->isAutoRepeat())
        _speed.setY(-10);
        move();
        //_speed.setY(0);

    }
    else if (event->key() == Qt::Key_S){
        //if (pos().y() < 600)
        //setPos(x(), y()+10);
        _speed.setY(10);
        move();
        //_speed.setY(0);

        //keyRelease отжатие кнопки
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    //qDebug()<< "key released";
    qDebug () << event->isAutoRepeat();
    if(!event->isAutoRepeat()){
        _speed.setX(0);
        _speed.setY(0);
    }
}

Player::Player(){
    _position.setX(400);
    _position.setY(500);

    _currentFrame = 0;
    _sprite = new QPixmap(":/images/Resources/PNG/Human/human_nude_hair.png");
    _timer = new QTimer();

    connect(_timer, &QTimer::timeout, this, &Player::nextFrame);
    _timer->start(100);
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->drawPixmap(-10,-10, *_sprite, _currentFrame, 0, 20,20);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Player::nextFrame(){
    _currentFrame += 20;
        if (_currentFrame >= 30 ) _currentFrame = 0;
        //this->update(-10,-10,20,10);
        this->update(-10,-10,20,20);
}

void Player::move()
{
    _position.setX(_position.x() + _speed.x());
    _position.setY(_position.y() + _speed.y());
    setPos(_position.x(),_position.y());
}

QRectF Player::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}
