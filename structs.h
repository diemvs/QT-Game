#ifndef STRUCTS_H
#define STRUCTS_H
#include <QList>

//char array[30][20];

//level_1.txt
enum sceneItems{
    //walls
    bricks_1 = 'a',
    bricks_2 = 'b',
    flag_1 = 'c',
    leftSideBricks = 'd',
    bricks_3 = 'e', //main walls
    bricks_4 = 'f',
    zelda_bricks_1 = '1', // upper left conner
    zelda_bricks_2 = '2', // upper wall
    zelda_bricks_3 = '3', // upper right conner
    zelda_bricks_4 = '4', // right wall
    zelda_bricks_5 = '5', // lower right conner
    zelda_bricks_6 = '6', // lower wall
    zelda_bricks_7 = '7', // lower left wall
    zelda_bricks_8 = '8', // left wall
    zelda_bricks_9 = '9', // mid wall 1
    zelda_bricks_10 = '0', // mid wall 2
    zelda_diamond = 'g',

    //enemies
    bat = 'i',
    skeleton = 'j',
    orc = 'k'

};

enum directionType {
    UP, DOWN, LEFT, RIGHT
};

#endif // STRUCTS_H
