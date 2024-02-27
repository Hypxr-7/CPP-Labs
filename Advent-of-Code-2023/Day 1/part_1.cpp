#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string calValue(string s);

int main(){
    ifstream ifs("input.txt");
    string line;
    int sum = 0;
    while(getline(ifs, line)){
        cout << calValue(line) << " ";
        sum += stoi(calValue(line));
    }

    cout << endl << "Sum: " << sum;

    return 0;
}

string calValue(string s){
    string sReturn;
    for(char c: s){
        if (isdigit(c)){
            if (sReturn.length() <= 1){
                sReturn += c;
            }
            else{
                sReturn[1] = c;
            }
        }
    }
    if (sReturn.length() == 1){
        sReturn += sReturn[0];
    }
    return sReturn;
}
