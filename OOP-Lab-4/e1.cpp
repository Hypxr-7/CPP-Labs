#include <iostream>
#include <vector>

using std::cout, std::endl, std::string, std::vector, std::to_string;

// Base class
class Animal {
private:
    string name;
    int age;

public:
    // Non-default constructor
    Animal(string name, int age) : name(name), age(age) {}

    // Getters
    string getName() { return name; }
    int getAge() { return age; }

    // Setters
    void setName(string newName) { name = newName; }
    void setAge(int newAge) { age = newAge; }

    // Print details
    virtual void printDetails() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }

    virtual void makeSound() = 0; // Pure virtual function
};

// Derived class 1
class Dog : public Animal {
private:
    string breed;
    bool isTrained;

public:
    // Non-default constructor
    Dog(string name, int age, string breed, bool isTrained) : Animal(name, age), breed(breed), isTrained(isTrained) {}

    // Getters
    string getBreed() { return breed; }
    bool getIsTrained() { return isTrained; }

    // Setters
    void setBreed(string newBreed) { breed = newBreed; }
    void setIsTrained(bool newIsTrained) { isTrained = newIsTrained; }

    // Print details
    void printDetails() override {
        Animal::printDetails();
        cout << "Breed: " << breed << ", Trained: " << (isTrained ? "Yes" : "No") << endl;
    }

    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

// Derived class 2
class Cat : public Animal {
private:
    string color;
    bool isIndoor;

public:
    // Non-default constructor
    Cat(string name, int age, string color, bool isIndoor) : Animal(name, age), color(color), isIndoor(isIndoor) {}

    // Getters
    string getColor() { return color; }
    bool getIsIndoor() { return isIndoor; }

    // Setters
    void setColor(string newColor) { color = newColor; }
    void setIsIndoor(bool newIsIndoor) { isIndoor = newIsIndoor; }

    // Print details
    void printDetails() override {
        Animal::printDetails();
        cout << "Color: " << color << ", Indoor: " << (isIndoor ? "Yes" : "No") << endl;
    }

    void makeSound() override {
        cout << "Meow!" << endl;
    }
};


// Additional class
class AnimalShelter {
private:
    vector<Animal*> animals;

public:
    // Method to add an animal
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    // Method to print details of all animals
    void printAll() {
        for (Animal* animal : animals) {
            animal->printDetails();
        }
    }
};

int main() {
    // Create an animal shelter
    AnimalShelter shelter;

    // Create dogs and add them to the shelter
    for (int i = 1; i <= 5; i++) {
        Dog* dog = new Dog("Dog" + to_string(i), i, "Breed" + to_string(i), true);
        shelter.addAnimal(dog);
    }

    // Create cats and add them to the shelter
    for (int i = 1; i <= 5; i++) {
        Cat* cat = new Cat("Cat" + to_string(i), i, "Color" + to_string(i), true);
        shelter.addAnimal(cat);
    }

    // Print details of all animals in the shelter
    shelter.printAll();

    return 0;
}