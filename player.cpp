#include "player.h"
#include "bullet.h"
#include "enemy.h"

extern Game *game;

void Player::keyPressEvent(QKeyEvent *event)
{
    //_timerMovement->start(100);
    //выстрел
    if (event->key() == Qt::Key_Up){
        directionType type = UP;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x()-5, y()-20);
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Down){
        directionType type = DOWN;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x()-5, y()+10);
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Left){
        directionType type = LEFT;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x()-20, y()-5);
        scene()->addItem(bullet);
    }
    else if (event->key() == Qt::Key_Right){
        directionType type = RIGHT;
        Bullet *bullet = new Bullet(type);
        bullet->setPos(x()+10, y()-5);
        scene()->addItem(bullet);
    }
    else if(event->key() == Qt::Key_A){
        _speed.setX(-10);
        move();
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
    _position.setX(100);
    _position.setY(100);
    _currentFrame = 0;
    //_sprite = new QPixmap(":/images/Resources/PNG/Human/human_nude_hair.png");
    _sprite = new QPixmap(":/images/Resources/Sprites/Player/human_regular_bald.bmp");
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
    int topGraduate = 0, botGraduate = 0, leftGraduate = 0, rightGraduate = 0;
    int ig, jg;

    ig = _position.x()/30;
    jg = _position.y()/30;
    if(game->array[ig][jg+1] == 'a'){
        botGraduate = (jg+1)*30;
    }
    if(game->array[ig][jg-1] == 'a'){
        topGraduate = jg*30;
    }
    if(game->array[ig+1][jg] == 'a'){
        rightGraduate = (ig+1)*30;
    }
    if(game->array[ig-1][jg] == 'a'){
        leftGraduate = ig*30;
    }
        qDebug() << "aadsdas";
        _position.setX(_position.x() + _speed.x());
        _position.setY(_position.y() + _speed.y());
        qDebug() << "rG:" << rightGraduate << " lG:" << leftGraduate << " tG:" << topGraduate << " bG:" << botGraduate;
        qDebug() << "xPos:" << _position.x() << " yPos:" << _position.y();
    if((_position.x()==rightGraduate) || (_position.x()==leftGraduate) || (_position.y()==topGraduate) || (_position.y()==botGraduate)){
        _position.setX(_position.x() - _speed.x());
        _position.setY(_position.y() - _speed.y());
        setPos(_position.x(),_position.y());
    } else {

        setPos(_position.x(),_position.y());
    }
}

QRectF Player::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}
