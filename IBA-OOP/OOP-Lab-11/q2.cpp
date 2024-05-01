#include <iostream>
#include <string>
#include <random>
#include <vector>
#include <format>

using namespace std;

template <typename T>
using Interval = std::pair<T, T>;

enum class EClass {A, B, C, D, E, F};

class Database{
private:

    class Property {
    public:
        string name;
        int price;
        int area;
        int rooms;
        float bfactor;
        bool garage;
        EClass eclass;
    };

    vector<Property> properties;

    const unsigned int seed = random_device{}();
    default_random_engine generator {seed};

    uniform_int_distribution<int> price_gen = uniform_int_distribution<int> {10000000, 50000000};
    uniform_int_distribution<int> area_gen = uniform_int_distribution<int> {20, 200};
    uniform_int_distribution<int> room_gen = uniform_int_distribution<int> {1, 10};
    uniform_real_distribution<float> bfactor_gen = uniform_real_distribution<float> {0, 1};
    bernoulli_distribution garage_gen = bernoulli_distribution {0.5};
    uniform_int_distribution<int> eclass_gen = uniform_int_distribution<int> {0, 5};
    uniform_int_distribution<int> length_gen = uniform_int_distribution<int> {5, 10};
    uniform_int_distribution<int> letter_gen = uniform_int_distribution<int> {0, 51};

    string RandomString(){
        static const char alphabet[] = "ABCDEFGHIJKLMNOPKRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
        string new_name;
        int length = length_gen(generator);
        for (int i = 0; i < length; i++){
            int letter = letter_gen(generator);
            new_name += alphabet[letter];
        }

        return new_name;
    }

    template <typename T>
    bool InInterval(Interval<T> interval, T value){
        return value >= interval.first && value <= interval.second;
    }

public:
    Database() = default;

    void Insert(){
        Property new_property;
        new_property.name = RandomString();
        new_property.price = price_gen(generator);
        new_property.area = area_gen(generator);
        new_property.rooms = room_gen(generator);
        new_property.bfactor = bfactor_gen(generator);
        new_property.eclass  = static_cast<EClass>(eclass_gen(generator));
        new_property.garage = garage_gen(generator);
        properties.push_back(new_property);
    }

    void Print(){
        cout << format("{:^10}  {:^10}  {:^10}  {:^10}   {:^10}   {:^10}\n", "Name", "Price", "Area", "Rooms", "B-Factor", "Garage");
        for (auto p : properties) {
            cout << format("{:^10}  {:^10}  {:^10}  {:^10}   {:^10}   {:^10}", p.name, p.price, p.area, p.rooms, p.bfactor, p.garage);
            switch (p.eclass) {
                case EClass::A :
                    cout << format("{:^10}\n", "A");
                    break;
                case EClass::B :
                    cout << format("{:^10}\n", "B");
                    break;
                case EClass::C :
                    cout << format("{:^10}\n", "C");
                    break;
                case EClass::D :
                    cout << format("{:^10}\n", "D");
                    break;
                case EClass::E :
                    cout << format("{:^10}\n", "E");
                    break;
                case EClass::F :
                    cout << format("{:^10}\n", "F");
                    break;
                default:
                    cout <<"\n";
            }
        }
    }

    void Find(Interval<int> price, Interval<int> area, Interval<int> rooms, Interval<float> bright, Interval<EClass> eclass, bool garage, int max_res){
        cout << format("{:^10}  {:^10}  {:^10}  {:^10}   {:^10}\n", "Name", "Price", "Area", "Rooms", "B-Factor");
        int total = 0;
        for (auto p : properties){
            if (InInterval(area, p.area) &&
                InInterval(price, p.price) &&
                InInterval(rooms, p.rooms) &&
                InInterval(bright, p.bfactor) &&
                InInterval(eclass, p.eclass) &&
                garage == p.garage){
                string format_bfactor = format("{:.2f}", p.bfactor);
                cout << format("{:^10}  {:^10}  {:^10}  {:^10}   {:^10}   {:^10}", p.name, p.price, p.area, p.rooms, format_bfactor, p.garage);
                switch (p.eclass) {
                    case EClass::A :
                        cout << format("{:^10}\n", "A");
                        break;
                    case EClass::B :
                        cout << format("{:^10}\n", "B");
                        break;
                    case EClass::C :
                        cout << format("{:^10}\n", "C");
                        break;
                    case EClass::D :
                        cout << format("{:^10}\n", "D");
                        break;
                    case EClass::E :
                        cout << format("{:^10}\n", "E");
                        break;
                    case EClass::F :
                        cout << format("{:^10}\n", "F");
                        break;
                    default:
                        cout << "\n";
                }

                total++;
                if (total==max_res) break;
            }
        }
    }
};

int main(){
    Database database;
    for (int i = 0; i < 1000; i++) database.Insert();

    Interval<int> price = {10000000, 40000000};
    Interval<int> area = {50, 150};
    Interval<int> rooms = {2, 9};
    Interval<float> bfactor = {0.2, 0.9};
    Interval<EClass> eclass = {EClass::B, EClass::F};
    bool garage = true;
    int max = 50;

    database.Find(price, area, rooms, bfactor, eclass, garage, max);

    return 0;
}