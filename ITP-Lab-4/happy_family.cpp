#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
    srand(time(0));
    int boys = 0;
    int girls = 0;
    int children = 0;
    while (boys == 0 || girls == 0){
        if (rand()%2 == 0)
            boys++;
        else
            girls++;
        children++;
    }
    cout << "Total Children: " << children << endl;
}