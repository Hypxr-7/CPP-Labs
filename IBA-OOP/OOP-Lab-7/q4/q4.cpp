#include <iostream>
#include "Seq.h"

using namespace std;

int main(){
    Seq<int> s1;
    s1.add(1);
    s1.add(2);
    s1.add(3);
    s1.display();
    Seq<int> s2(s1);
    s2.display();
    s2.add(4);
    s2.display();
    s1.display();
    s1.remove(2);
    s1.display();

    Seq<string> s3;
    s3.add("Hello");
    s3.add("There");
    s3.add("World");
    s3.add("!");
    s3.display();
    s3.insertAt("C++", 2);
    s3.display();
    s3.remove("Hello");
    s3.display();
    return 0;
}