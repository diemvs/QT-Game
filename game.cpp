#include "game.h"
//#include "bullist.h"
//#include "bullet.h"
//#include "enemy.h"

//new
#include <ctime>


#include <QImage>

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

    setBackgroundBrush(QBrush(QImage(":/images/Resources/Sprites/background/bg_2.png")));
    _level("C:\\qt_proj\\Game\\Resources\\Levels\\level_1.txt");
    _levelGeneration();

    qDebug() << "------------------------------";
    qDebug() << "game.cpp: Size of enemylist = " << enemyList.size();

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
    getline(file, st);
    getline(file, st);
    for(int i = 0; i < st.size(); i++){
        _countOfEnemies = _countOfEnemies*10+(st[i]-'0');
    }
    getline(file,st);
    qDebug() << "game.cpp: count of enemies: " << _countOfEnemies;
    qDebug() << "------------------------------";
    while(getline(file, st)){
        for (int k = 0; k < 30; k++){
            array[k][row] = st[k];
            if(st[k]== '_'){
                 _countOfUnderSpaces++;

            }

        }

        row++;
    }
    srand(time(0));
    for(int i = 0; i < _countOfEnemies; i++){
        randomDigits[i] = 1 + rand() % _countOfUnderSpaces;
        qDebug() << "game.cpp: random digits: "<< randomDigits[i];
    }
    qDebug() << "------------------------------";
    for (int q = 0; q < _countOfEnemies; q++){
            for (int s = 0; s < _countOfEnemies; s++){
                if (randomDigits[s] > randomDigits[s+1]){
                    int intermed = randomDigits[s];
                    randomDigits[s] = randomDigits[s+1];
                    randomDigits[s+1] = intermed;
                }
            }

     }
    for(int i = 0; i < _countOfEnemies; i++){
        qDebug()<< "game.cpp: sorted random digits: " << i<< " " << randomDigits[i];
    }
    file.close();
}

void Game::_levelGeneration(){
    int currentUnderSpaces = 0, currentIterrator = 0; // текущий номер "_" // текущий номер элемента randomDigit
    sceneItems item;
    item = bat;
    Enemy *enemy = new Enemy(90, 90, item);
    gameScene->addItem(enemy);
    enemyList.append(enemy);

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
                break;
            }


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

            case 'g':{
                item = zelda_diamond;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case 'h':

                break;
            case 'i': {
                item = bat;
                Enemy *enemy = new Enemy(i*30, j*30, item);
                gameScene->addItem(enemy);
                enemyList.append(enemy);
                break;
            }


            case 'j':{
                item = skeleton;
                Enemy *enemy = new Enemy(i*30, j*30, item);
                gameScene->addItem(enemy);
                enemyList.append(enemy);

            }
                break;
            case 'k':{
                item = orc;
                Enemy *enemy = new Enemy(i*30, j*30, item);
                gameScene->addItem(enemy);
                enemyList.append(enemy);
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
            case '1':{
                item = zelda_bricks_1;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '2':{
                item = zelda_bricks_2;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '3':{
                item = zelda_bricks_3;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '4':{
                item = zelda_bricks_4;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '5':{
                item = zelda_bricks_5;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '6':{
                item = zelda_bricks_6;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '7':{
                item = zelda_bricks_7;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '8':{
                item = zelda_bricks_8;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }

            case '9':{
                item = zelda_bricks_9;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '0':{
                item = zelda_bricks_10;
                Construction *construction = new Construction(i*30, j*30, item);
                gameScene->addItem(construction);
                break;
            }
            case '_':{
                currentUnderSpaces++;
                switch((i+j) % 3){
                case 0:{
                    item = bat;
                    break;

                }
                case 1:{
                    item = skeleton;
                    break;
                }
                case 2:{
                    item = orc;
                    break;
                }


                };

                if(currentUnderSpaces == randomDigits[currentIterrator]){
                    Enemy *enemy = new Enemy(i*30, j*30, item);
                    gameScene->addItem(enemy);
                    enemyList.append(enemy);
                    currentIterrator++;
                }


                break;
            }
            }
        }
    }
}

void Game::gameOver()
{

    gameScene->clear();
    setBackgroundBrush(QBrush(QImage(":/images/Resources/Sprites/background/gameOver.jpg")));
}

