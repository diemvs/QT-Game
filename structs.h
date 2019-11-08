#ifndef STRUCTS_H
#define STRUCTS_H

//level_1.txt
enum sceneItems{
    //walls
    bricks_1 = 'a',
    bricks_2 = 'b',
    flag_1 = 'c',
    leftSideBricks = 'd',
    bricks_3 = 'e', //main walls
    bricks_4 = 'f',

    //enemies
    bat = 'i',
    skeleton = 'j',
    orc = 'k'

};

enum directionType {
    UP, DOWN, LEFT, RIGHT
};

#endif // STRUCTS_H
