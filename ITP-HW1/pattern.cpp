#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main() {
    std::cout << std::fixed << std::setprecision(3);

    double price;
    int i = 1, stock_up = 0, stock_down = 0;
    string sell_or_buy = "";

    cin >> price;
    double prev_val = price;
    cout << i << "    " << price << "    " << sell_or_buy << endl;


    while(std::cin >> price) {
        i++;
        if (prev_val < price){
            stock_up++;
            stock_down = 0;
        }
        else if (prev_val > price){
            stock_down++;
            stock_up = 0;
        }
        else{
            stock_down = 0;
            stock_up = 0;
        }

        cout << i << "    " << price << "    " << sell_or_buy << endl;

        if (stock_up == 3){
            sell_or_buy = "sell";
        }
        else if (stock_down == 3){
            sell_or_buy = "buy";
        }
        else{
            sell_or_buy = "";
        }

        prev_val = price;
    }
    return 0;
}