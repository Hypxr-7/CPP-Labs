#include <iostream>

int main(){
    using namespace std;

    int treasureMap[5][5] = {{34, 21, 32, 41, 25},
                            {14, 42, 43, 14, 31},
                            {54, 45, 52, 42, 23},
                            {33, 15, 51, 31, 35},
                            {21, 52, 33, 13, 23}};

    cout << " +----+----+----+----+----+" << endl;
    for (int i = 0; i < size(treasureMap); i++){
        for (int j = 0; j < size(treasureMap[0]); j++){
            cout << " | " << treasureMap[i][j];
        }
        cout << " | " << endl;
        cout << " +----+----+----+----+----+" << endl;
    }
    cout << endl;

    bool endFound = false;
    int index = 11;
    while (!endFound){
        int indexRow = ((index % 100) / 10) - 1;
        int indexColumn = (index % 10) - 1;
        if (treasureMap[indexRow][indexColumn] == index){
            endFound = true;
            cout << "Reached!";
        }
        else{
            cout << treasureMap[indexRow][indexColumn] << " --> ";
            index = treasureMap[indexRow][indexColumn];
        }
    }
    
}