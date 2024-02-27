#include <iostream>

using namespace std;

int calcProfit(int arr[], int N){
    int profit = 0;
    int buy = arr[0];
    int sell = arr[0];

    for(int i = 1; i < N; i++){
        if(arr[i] < buy){
            buy = arr[i];
            sell = arr[i];
        }
        else if(arr[i] > sell){
            sell = arr[i];
        }
        profit = max(profit, sell - buy);
    }
    
    if (profit == 0)
        profit = -1;
        
    return profit;
}

int main(){
    int N = 5;
    int arr[N] = {1, 2, 3, 4, 5};
    int profit = calcProfit(arr, N); 

    cout << "Profit: " << profit << endl;

    return 0;
}