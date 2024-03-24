#include <iostream>

using std::cout, std::cin;

void writeChars(int n);

int main(){
    cout << "Enter num: ";
    int num;
    cin >> num;
    writeChars(num);
    
    return 0;
}

void writeChars(int n){
    if (n <= 0) 
        return; 
    if (n == 1) 
        cout << "*";
    else 
        if (n == 2)
        cout << "**";
        else{
            cout << "<";
            writeChars(n - 2);
            cout << ">";
        }
}