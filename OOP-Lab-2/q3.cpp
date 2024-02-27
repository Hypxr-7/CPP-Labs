#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using std::cout, std::cin, std::endl, std::vector, std::string;

class IntegerSet{
private:
    vector<bool> int_set;
public:
    IntegerSet(){
        for (int i = 0; i < 100; i++)
            int_set.push_back(false);
    }

    IntegerSet unionOfSets(const IntegerSet& obj) const {
        int max_size = (this->int_set.size() < obj.int_set.size()) ? obj.int_set.size() : this->int_set.size();
        IntegerSet new_set;
        for (int i = 0; i < max_size; i++)
            if (this->int_set[i] == true || obj.int_set[i] == true)
                new_set.int_set[i] = true;
            else
                new_set.int_set[i] = false;
        return new_set;
    }

    IntegerSet intersectionOfSets(const IntegerSet& obj) const {
        int min_size = (this->int_set.size() > obj.int_set.size()) ? obj.int_set.size() : this->int_set.size();
        IntegerSet new_set;
        for (int i = 0; i < min_size; i++)
            if (this->int_set[i] == true && obj.int_set[i] == true)
                new_set.int_set[i] = true;
            else
                new_set.int_set[i] = false;
        return new_set;
    }

    void insertElement(int k){
        int_set[k] = true;
    }

    void deleteElement(int m){
        int_set[m] = false;
    }

    string to_string() const {
        string s = "";
        for (int i = 0; i < int_set.size(); i++)
            if (int_set[i])
                s += (std::to_string(i) + " ");
        return s; 
    }

    bool isEqualTo(IntegerSet& obj) const {
        for (int i = 0; i < int_set.size(); i++)
            if (int_set[i] != obj.int_set[i])
                return false;
        return true;
    }
};

int main(){
    srand(time(NULL));

    IntegerSet randset1;
    IntegerSet randset2;
    for (int i = 0; i < 10; i++){
        randset1.insertElement(rand() % 100);
        randset2.insertElement(rand() % 100);
    }

    cout << "randset1: " << randset1.to_string() << endl;
    cout << "randset2: " << randset2.to_string() << endl;

    IntegerSet unionSet = randset1.unionOfSets(randset2);
    IntegerSet intersectionSet = randset1.intersectionOfSets(randset2);
    
    cout << "unionSet: " << unionSet.to_string() << endl;
    cout << "intersectionSet: " << intersectionSet.to_string() << endl;

    IntegerSet set1;
    set1.insertElement(1);
    set1.insertElement(2);
    set1.insertElement(3);
    cout << "set 1: " << set1.to_string() << endl;

    IntegerSet set2;
    set2.insertElement(1);
    set2.insertElement(2);
    set2.insertElement(3);
    cout << "set 2: " << set2.to_string() << endl;

    if(set1.isEqualTo(set2)){
        std::cout << "set1 is equal to set2" << std::endl;
    } else {
        std::cout << "set1 is not equal to set2" << std::endl;
    }

    return 0;
}