#include <iostream>

using std::cout, std::endl;

class Mammal {
public:
    Mammal(void) : itsAge(1) {
        cout << "Mammal constructor..." << endl;
    }
    virtual ~Mammal(void) {
        cout << "Mammal destructor..." << endl;
    }
    virtual void Move() const {
        cout << "Mammal moves a step!" << endl;
    }
    virtual void Speak() const {
        cout << "What does a mammal speak? Mammilian!" << endl;
    }
protected:
    int itsAge;
};

class Dog : public Mammal{
public:
    Dog() : Mammal() {
        cout << "Dog constructor..." << endl;
    }

    ~Dog(){
        cout << "Dog destructor..." << endl;
    }

    void Move() const {
        cout << "Dog moves a step!" << endl;
    }

    void Speak() const {
        cout << "Dog barks!" << endl;
    }
};

int main () {
    Mammal *pDog = new Dog;
    pDog->Move();
    pDog->Speak();
    delete pDog;

    //Dog *pDog2 = new Dog;
    //pDog2->Move();
    //pDog2->Speak();
    //delete pDog2;

    return  0;
}
