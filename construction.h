#ifndef CONSTRUCTION_H
#define CONSTRUCTION_H

#include "enemy.h"

#include <QObject>
#include <QGraphicsPixmapItem>
#include <QPainter>

class Construction : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Construction(int x, int y, sceneItems wallType);
private:
    QPixmap *_sprite;
public:
    QList<char> sceneConstructions;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

};

#endif // CONSTRUCTION_H
