#include <vector>
#include <iostream>


using std::vector, std::cout, std::endl, std::max;



int average(const vector<int>& a, int start, int end);
int scoresAverage(const vector<int>& a);

int main(){
    int v1 = scoresAverage({2, 2, 4, 4});
    int v2 = scoresAverage({4, 4, 4, 2, 2, 2});
    int v3 = scoresAverage({3, 4, 5, 1, 2, 3});

    cout << v1 << endl;
    cout << v2 << endl;
    cout << v3 << endl;

    return 0;
}


int average(const vector<int>& a, int start, int end){
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += a[i];
    }
    return sum / (end - start + 1);
}


int scoresAverage(const vector<int>& a){
    int firstHalfAvg = average(a, 0, a.size()/2 - 1);  
    int secondHalfAvg = average(a, a.size() / 2, a.size() - 1);
    return max(firstHalfAvg, secondHalfAvg); 
}