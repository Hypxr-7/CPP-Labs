#include <iostream>

using std::cout,std::cin, std::endl;

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

class Cat : public Mammal{
public:
    Cat() : Mammal() {
        cout << "Cat constructor..." << endl;
    }

    ~Cat(){
        cout << "Cat destructor..." << endl;
    }

    void Move() const {
        cout << "Cat moves a step!" << endl;
    }

    void Speak() const {
        cout << "Cat barks!" << endl;
    }
};

class Horse : public Mammal{
public:
    Horse() : Mammal() {
        cout << "Horse constructor..." << endl;
    }

    ~Horse(){
        cout << "Horse destructor..." << endl;
    }

    void Move() const {
        cout << "Horse moves a step!" << endl;
    }

    void Speak() const {
        cout << "Horse barks!" << endl;
    }
};

class Mouse : public Mammal{
public:
    Mouse() : Mammal() {
        cout << "Mouse constructor..." << endl;
    }

    ~Mouse(){
        cout << "Mouse destructor..." << endl;
    }

    void Move() const {
        cout << "Mouse moves a step!" << endl;
    }

    void Speak() const {
        cout << "Mouse barks!" << endl;
    }
};

int main () {
    Mammal* theArray[5];
    Mammal* ptr;
    int choice, i;
    for (i = 0; i<5; i++) {
        cout << "(1)dog (2)cat (3)horse (4)mouse: " << endl << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1: ptr = new Dog; break;
            case 2: ptr = new Cat; break;
            case 3: ptr = new Horse; break;
            case 4: ptr = new Mouse; break;
            default: ptr = new Mammal; break;
        }
        theArray[i] = ptr;
    }

    cout << "------------------" << endl;

    for (i=0;i<5;i++)
        theArray[i]->Speak();

    cout << "------------------" << endl;

// Always free dynamically allocated objects
    for (i=0;i<5;i++)
        delete theArray[i];
}