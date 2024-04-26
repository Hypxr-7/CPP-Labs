#include <iostream>

using namespace std;

class Tool{
protected:
    int strength;
    char type;
public:
    Tool(int s, char c) : strength(s) , type(c) {}

    void setStrength(int s){ strength = s; }

    int getStrength() { return strength; }

    char getType() { return type;}
};

class Rock : public Tool{
public:
    Rock(int s) : Tool(s, 'r') {}


    bool fight(Tool tool){
        int s = strength;
        if (tool.getType() == 'p')
            s /= s;
        else if (tool.getType() == 's')
            s += s;

        if (s > tool.getStrength())
            return true;
        else
            return false;
    }

};

class Paper : public Tool{
public:
    Paper(int s) : Tool(s, 'p') {}

    bool fight(Tool tool){
        int s = strength;
        if (tool.getType() == 's')
            s /= s;
        else if (tool.getType() == 'r')
            s += s;

        if (s > tool.getStrength())
            return true;
        else
            return false;
    }
};

class Scissors : public Tool{
public:
    Scissors(int s) : Tool(s, 's') {}

    bool fight(Tool tool) {
        int s = strength;
        if (tool.getType() == 'r')
            s /= s;
        else if (tool.getType() == 'p')
            s += s;

        if (s > tool.getStrength())
            return true;
        else
            return false;
    }
};

int main() {
// Example main function
// You may add your own testing code if you like
    Scissors s1(5);
    Paper p1(7);
    Rock r1(15);

    cout << s1.fight(p1) << p1.fight(s1) << endl;
    cout << p1.fight(r1) << r1.fight(p1) << endl;
    cout << r1.fight(s1) << s1.fight(r1) << endl;
    return 0;
}