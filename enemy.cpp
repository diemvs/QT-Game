#include "enemy.h"

#include <fstream>
#include <string>
#include <iostream>

using namespace std;

Enemy::Enemy(int x, int y, sceneItems enemyType)
{
    _currentFrame = 0;
    setPos(x, y);
    _position.setX(x);
    _position.setY(y);
    switch(enemyType){
    case bat:{
        _sprite = new QPixmap(":/images/Resources/Sprites/Enemies/bat_1.png");
        break;
    }
    case skeleton:{
        _sprite = new QPixmap(":/images/Resources/Sprites/Enemies/skeleton_1.png");
        break;
    }
    case orc:{
        _sprite = new QPixmap(":/images/Resources/Sprites/Enemies/orc_1.png");
        break;
    }
    }
    _timer = new QTimer();
    getArr();
    connect(_timer, &QTimer::timeout, this, &Enemy::nextFrame);
    connect(_timer, &QTimer::timeout, this, &Enemy::move);
    _timer->start(300);

}

Enemy::~Enemy()
{
    _sprite = nullptr;
    _currentFrame = 0;
    _timer = nullptr;
    //game = nullptr;

}

int Enemy::damage()
{
    lifes--;

    if(lifes == 0){

        delete this;
    }
    return lifes;
}

bool Enemy::moveUp()
{
    int xPos = _position.x()/30;
    int yPos = _position.y()/30;

    int topGraduate;

    if(arr[xPos][yPos-1] != '_'){
        topGraduate = (yPos)*30;
        if(_position.y()-5 < topGraduate){
            return false;
        }
    }
    return true;
}

bool Enemy::moveDown(){
    int xPos = _position.x()/30;
    int yPos = _position.y()/30;

    int botGraduate = 0;


    if(arr[xPos][yPos+1] != '_'){
        botGraduate = (yPos -1)*30;
        if(_position.y()+5 > botGraduate){
            return false;
        }
    }
    return true;

}

bool Enemy::moveLeft(){
    int xPos = _position.x()/30;
    int yPos = _position.y()/30;

    int leftGraduate = 0;

    if(arr[xPos-1][yPos] != '_'){
        leftGraduate = (xPos)*30;
        if(_position.x()-5 < leftGraduate){
            return false;
        }
    }
    return true;
}

bool Enemy::moveRight(){
    int xPos = _position.x()/30;
    int yPos = _position.y()/30;

    int rightGraduate = 0;

    if(arr[xPos+1][yPos] != '_'){
        rightGraduate = (xPos-1)*30;
        if(_position.x()+5 > rightGraduate){
            return false;
        }
    }
    return true;
}

void Enemy::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(0,0, *_sprite, _currentFrame, 0, 30,30);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Enemy::move()
{
    int randomNumber = rand() % 4;

    switch(randomNumber){
    case 0:{
        if(moveDown()){
        setPos(_position.x(), _position.y()+5);
        _position.setY(_position.y()+5);
        }
        break;

    }
    case 1:{
        if(moveUp()){
        setPos(_position.x(), _position.y()-5);
        _position.setY(_position.y()-5);
        }
        break;
    }
    case 2:{
        if(moveLeft()){
        setPos(_position.x()-5, _position.y());
        _position.setX(_position.x()-5);
        }
        break;
    }
    case 3:{
        if(moveRight()){
        setPos(_position.x()+5, _position.y());
        _position.setX(_position.x()+5);
        }
        break;
    }
    }
}



void Enemy::nextFrame(){
    _currentFrame += 30;
        if (_currentFrame >= 90 ) _currentFrame = 0;
        this->update(0,0,30,30);
}

void Enemy::getArr()
{
    ifstream file;
    file.open("C:\\qt_proj\\Game\\Resources\\Levels\\level_1.txt");
    int row = 0;
    string st;
    char *str = new char[256];
    str[0] = 0;
    getline(file, st);
    getline(file, st);
    getline(file,st);
    while(getline(file, st)){
        for (int k = 0; k < 30; k++){
            arr[k][row] = st[k];
        }
        row++;
    }
    file.close();
}

QRectF Enemy::boundingRect() const
{
    return QRectF(0,0,30,30);
}
