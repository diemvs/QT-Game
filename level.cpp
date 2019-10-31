#include "level.h"

using namespace std;


void level::starting_drawing(){
    for (int i = 0; i < 30; i++){
        for (int j = 0; j < 20; j++){
            switch(array[i][j]){
            case 'a': {
            Enemy *enemy = new Enemy(i, j);
            //gameScene->addItem(enemy);
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


level::level()
{
    ifstream file;
    file.open("C:\\qt_proj\\Game\\level_1.txt");
    int row = 0;
    string st;
    char *str = new char[256];

    str[0] = 0;

    //char str[256];
    while(getline(file, st)){
        for (int k = 0; k < 30; k++){
            array[k][row] = st[k];
            cout << array[k][row];
        }
        cout << endl;
        row++;
    }

    cout << st << endl;

    /*
    for (int y = 0; y < 20; y++){
        for (int x = 0; x < 30; x++){
            file >> array[x][y];
        }
    }
    cout << "array cout";
    for (int y = 0; y < 20; y++){
        for (int x = 0; x < 30; x++){
            cout << array[y][x] << "|";
        }
        cout << endl;
    }*/
}





