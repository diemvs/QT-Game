#include "game.h"
#include "bullet.h"
#include "enemy.h"
#include "level.h"

using namespace std;

Game::Game(QWidget *parent){

    gameScene = new QGraphicsScene();
    gameScene->setSceneRect(0,0,900,600);
    setScene(gameScene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    setFixedSize(900,600);

    player = new Player();
    player->setPos(100,100);
    gameScene->addItem(player);

    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    _level("C:\\qt_proj\\Game\\Resources\\Levels\\level_1.txt");
    _levelGeneration();

    show();
    _timer.start(100);
}

void Game::_level(string path){
    ifstream file;
    file.open(path);
    int row = 0;
    string st;
    char *str = new char[256];

    str[0] = 0;

    //char str[256];
    while(getline(file, st)){
        for (int k = 0; k < 30; k++){
            array[k][row] = st[k];
        }
        row++;
    }
}

void Game::_levelGeneration(){
    sceneItems item;
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 20; j++){
            switch(array[i][j]){
            case 'a': {
             item = bricks_1;
            Construction *construction = new Construction(i*30, j*30, item);
            gameScene->addItem(construction);
                break;
            }
            case 'b':{
                item = bricks_2;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case 'c':{
                item = flag_1;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case 'd':{
                item = leftSideBricks;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
            }

                break;
            case 'e':{
                item = bricks_3;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case 'f':{
                item = bricks_4;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }

            case 'g':

                break;
            case 'h':

                break;
            case 'i': {
                item = bat;
                Enemy *enemy = new Enemy(i*30, j*30, item);
                gameScene->addItem(enemy);
            }

                break;
            case 'j':{
                item = skeleton;
                Enemy *enemy = new Enemy(i*30, j*30, item);
                gameScene->addItem(enemy);
            }
                break;
            case 'k':{
                item = orc;
                Enemy *enemy = new Enemy(i*30, j*30, item);
                gameScene->addItem(enemy);
            }

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

