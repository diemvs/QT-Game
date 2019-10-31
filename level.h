#ifndef LEVEL_H
#define LEVEL_H

#include "enemy.h"
#include "player.h"
#include "score.h"

#include <vector>
#include <fstream>
#include <iostream>



using namespace std;

class level
{
public:
    level();
    void starting_drawing();
    char array[30][20];

    //a-d - player model
    //e-j - enemy model
    //k-o - play area
    //p-u - no play area
    //v-z - subjects
    //1-9 - additional models

};

#endif // LEVEL_H
