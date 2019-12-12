#include "construction.h"
#include "structs.h"

Construction::Construction(int x, int y, sceneItems wallType)
{

    switch (wallType){
    case bricks_1:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/1.png");
        setPos(x, y);
        sceneConstructions.append(bricks_1);
        break;
    }
    case bricks_2:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/2.png");
        setPos(x, y);
        sceneConstructions.append(bricks_2);
        break;
    }
    case flag_1:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/3.png");
        setPos(x, y);
        break;
    }
    case leftSideBricks:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/4.png");
        setPos(x, y);
        break;
    }
    case bricks_3:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/6.png");
        setPos(x, y);
        break;
    }
    case bricks_4:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/7.png");
        setPos(x, y);
        break;
    }
    case zelda_bricks_1:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/8.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_1);
        break;
    }
    case zelda_bricks_2:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/9.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_2);
        break;
    }
    case zelda_bricks_3:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/10.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_3);
        break;
    }
    case zelda_bricks_4:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/11.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_4);
        break;
    }
    case zelda_bricks_5:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/12.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_5);
        break;
    }
    case zelda_bricks_6:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/13.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_6);
        break;
    }
    case zelda_bricks_7:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/14.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_7);
        break;
    }
    case zelda_bricks_8:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/15.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_8);
        break;
    }
    case zelda_bricks_9:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/17.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_9);
        break;
    }

    case zelda_diamond:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/16.png");
        setPos(x, y);
        sceneConstructions.append(zelda_diamond);
        break;
    }
    case zelda_bricks_10:{
        _sprite = new QPixmap (":/images/Resources/Sprites/wall/18.png");
        setPos(x, y);
        sceneConstructions.append(zelda_bricks_10);
        break;
    }
    }
}

void Construction::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *_sprite, 0, 0, 30,30);

    Q_UNUSED(option);
    Q_UNUSED(widget);

}

QRectF Construction::boundingRect() const
{
    return QRectF(0,0,30,30);
}
