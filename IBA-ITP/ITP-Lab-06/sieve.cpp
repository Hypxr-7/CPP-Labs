#include <iostream>
#include <cmath>
#include <iomanip>

int main(){
    using namespace std;

    // we only need to continue the outer for loop till square root of n as multiple greater than that will be marked off
    // we can also start checking with the square of j as previous multiples have already been marked off
    // another optimization is to chech 2*i multiples as even ones would have been marked

    int n;
    cout << "Enter Number: ";
    cin >> n;

    bool prime[n+1] = {};

    for (int i = 2; i < sqrt(n+1); i++ ){
        int j = i*i;
        if (!prime[i]){
            while (j <= n+1){
                prime[j] = true;
                if (i == 2){
                    j += i;
                }
                else{
                    j += 2*i;
                }
            }
        }
    }

    int count = 0; 
    for (int i = 2; i < n+1; i++){
        if (!prime[i]){
            count++;
            cout << i << endl;
        }
    }
    
    cout << "There are " << count << " prime numbers till " << n << endl; 

    return 0;
}