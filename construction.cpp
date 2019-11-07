#include "construction.h"


Construction::Construction(int x, int y, sceneItems wallType)
{

    switch (wallType){

    case bricks_1:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/1.png");
        setPos(x, y);
        break;
    }
    case bricks_2:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/2.png");
        setPos(x, y);
        break;
    }
    case flag_1:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/3.png");
        setPos(x, y);
        break;
    }
    }
}

void Construction::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *_sprite, _currentFrame, 0, 30,30);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

QRectF Construction::boundingRect() const
{
    return QRectF(0,0,30,30);
}
