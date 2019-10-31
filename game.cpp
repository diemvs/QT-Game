#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "level.h"

#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include <QKeyEvent>

using namespace std;

Game::Game(QWidget *parent){

    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,900,600);
    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(900,600);


    player = new Player();
    player->setPos(400,500);
    gameScene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    //connect (_timer, &QTimer::timeout, this, &Player::move);

    _level("C:\\qt_proj\\Game\\Resources\\Levels\\level_1.txt");
    _levelGeneration();

    show();

    _timer.start(100);
}

void Game::_level(string path){
    ifstream file;
    //file.open("C:\\qt_proj\\Game\\level_1.txt");
    file.open(path);
    int row = 0;
    string st;
    char *str = new char[256];

    str[0] = 0;

    //char str[256];
    while(getline(file, st)){
        for (int k = 0; k < 30; k++){
            array[k][row] = st[k];
            //cout << array[k][row];
        }
        //cout << endl;
        row++;
    }
}

void Game::_levelGeneration(){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 20; j++){
            switch(array[i][j]){
            case 'a': {

            Enemy *enemy = new Enemy(i*30, j*30);
            gameScene->addItem(enemy);
                break;
            }
            case 'b':{


                break;
            }
            case 'c':

                break;
            case 'd':

                break;
            case 'e':

                break;
            case 'f':

                break;
            case 'g':

                break;
            case 'h':

                break;
            case 'i':

                break;
            case 'j':

                break;
            case 'k':

                break;
            case 'l':

                break;
            case 'm':

                break;
            case 'n':

                break;
            case 'o':

                break;
            case 'p':

                break;
            case 'q':

                break;
            case 'r':

                break;
            case 's':

                break;
            case 't':

                break;
            case 'u':

                break;
            case 'v':

                break;
            case 'w':

                break;
            case 'x':

                break;
            case 'z':

                break;

            }
        }
    }
}

