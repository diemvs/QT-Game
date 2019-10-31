#ifndef Player_H
#define Player_H
#include <QGraphicsPixmapItem>
#include <QObject>
#include <QTimer>
#include <QPointF>

class Player :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    Player();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
public slots:
    void nextFrame();
    void move();

private:
    QTimer *_timer, *_timerMovement;
    QPixmap *_sprite;
    int _currentFrame;
    QPointF _speed, _position;


};

#endif
