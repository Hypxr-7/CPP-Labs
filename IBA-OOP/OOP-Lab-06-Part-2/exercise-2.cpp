#include <iostream>
#include <vector>

void process(int num){
    if (num == 1)
        throw num;
    else if(num == 2)
        throw "yikes";
}

int main(){
    std::vector<int> x = {0, 1, 2, 3};
    for (int i : x){
        try {
            process(i);
            std::cout << "We Gucci" << std::endl;
        } catch (int &e) {
            std::cout << "int exception: " << e << std::endl;
        } catch (const char *e) {
            std::cout << "const char* exception: " << e << std::endl;
        }
    }
    return 0;
}