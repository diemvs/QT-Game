#include "player.h"
#include "game.h"


extern Game *game;



void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A || event->key() == 1060){
        _speed.setX(-10);
        move();
        nextFrame();
    }
    else if (event->key() == Qt::Key_D || event->key() == 1042){
        _speed.setX(10);
        move();
        nextFrame();
    }
    else if (event->key() == Qt::Key_W || event->key() == 1062){
        if(!event->isAutoRepeat())
        _speed.setY(-10);
        move();
        nextFrame();
    }
    else if (event->key() == Qt::Key_S || event->key() == 1067){
        _speed.setY(10);
        move();
        nextFrame();
    }
}

void Player::keyReleaseEvent(QKeyEvent *event)
{
    if(!event->isAutoRepeat()){
        _speed.setX(0);
        _speed.setY(0);

        if (event->key() == Qt::Key_Up){
                directionType type = UP;
                Bullet *bullet = new Bullet(type);
                bullet->setPos(x()-5, y()-20);
                scene()->addItem(bullet);
                game->bul.bulletList.append(bullet);

            }
            else if (event->key() == Qt::Key_Down){
                directionType type = DOWN;
                Bullet *bullet = new Bullet(type);
                bullet->setPos(x()-5, y()+10);
                scene()->addItem(bullet);
                game->bul.bulletList.append(bullet);

            }
            else if (event->key() == Qt::Key_Left){
                directionType type = LEFT;
                Bullet *bullet = new Bullet(type);
                bullet->setPos(x()-20, y()-5);
                scene()->addItem(bullet);
                game->bul.bulletList.append(bullet);

            }
            else if (event->key() == Qt::Key_Right){
                directionType type = RIGHT;
                Bullet *bullet = new Bullet(type);
                bullet->setPos(x()+10, y()-5);
                scene()->addItem(bullet);
                game->bul.bulletList.append(bullet);

            }
    }
}

Player::Player(){
    _position.setX(100);
    _position.setY(100);
    _currentFrame = 0;

    _sprite = new QPixmap(":/images/Resources/Sprites/Player/human_regular_bald.bmp");
    _timer = new QTimer();

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
    if(game->array[ig][jg+1] != '_'){
        botGraduate = (jg+1)*30;
    }
    if(game->array[ig][jg-1] != '_'){
        topGraduate = jg*30;
    }
    if(game->array[ig+1][jg] != '_'){
        rightGraduate = (ig+1)*30;
    }
    if(game->array[ig-1][jg] != '_'){
        leftGraduate = ig*30;
    }
        _position.setX(_position.x() + _speed.x());
        _position.setY(_position.y() + _speed.y());
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
