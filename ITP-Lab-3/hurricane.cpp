#include <iostream>
#include <cstdlib>
using namespace std;
int main() 
{
    srand(time(0));
    int num = rand() % 1000;
    if (num <= 99)
        num = num + 100;
    cout << "Random Number: " << num << endl;
    int num_d1 = num % 10;
    int num_d2 = (num % 100) / 10;
    int num_d3 = num / 100;
    
    
    cout << "Enter guess: ";
    int guess_num;
    cin >> guess_num;
    int gnum_d1 = guess_num % 10;
    int gnum_d2 = (guess_num % 100) / 10;
    int gnum_d3 = guess_num  / 100;
    bool flag = true;
    
    if (guess_num == num)
    {
        flag = false;
        cout << "You win 1 Million Rupees!";
    }
    else if (gnum_d1 == num_d1 || gnum_d2 == num_d1 || gnum_d3 == num_d1)
    {
        if (gnum_d1 == num_d2 || gnum_d2 == num_d2 || gnum_d3 == num_d2)
        {
            if (gnum_d1 == num_d3 || gnum_d2 == num_d3 || gnum_d3 == num_d3)
            {
                flag = false;
                cout << "You win 5 Lak Rupees!";
            }
        }
    }
    if (((gnum_d1 == num_d1 || gnum_d2 == num_d1 || gnum_d3 == num_d1) ||(gnum_d1 == num_d2 || gnum_d2 == num_d2 || gnum_d3 == num_d2) || (gnum_d1 == num_d3 || gnum_d2 == num_d3 || gnum_d3 == num_d3)) && flag == true)
    {
        cout << "You win 1 Lak Rupees";
    }
}