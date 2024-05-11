#include <iostream>

template <typename T = unsigned int, int N = 2>
class Point{
private:
    T points[N];
public:

    void set_value(int posn, T value){
        if (posn < 0  || posn >= N){
            std::cout << "Invalid position\n";
            return;
        }

        points[posn] = value;
    }

    T get_value(int posn){
        if (posn < 0 || posn >= N){
            std::cout << "Invalid position\n";
            return;
        }

        return points[posn];
    }

    void print_info(){
        std::cout << "point: [ ";
        for (auto point : points)
            std::cout << point << " ";
        std:: cout << "]\n";
    }

    friend std::ostream& operator<<(std::ostream& os, const Point& values){
        os << "Points : [ Dimensions: " << N << ", Components: ";
        for (int i = 0; i < N; ++i)
            os << values.points[i] << ' ';
        os << ']';
        return os;

    }
};

int main(){
    Point point_2d;
    point_2d.set_value(0,10);
    point_2d.set_value(1,20);
    point_2d.print_info() ;

    Point<double,3> point_3d;
    point_3d.set_value(0,10.1);
    point_3d.set_value(1,20.2);
    point_3d.set_value(2,30.3);
    point_3d.print_info() ;
    std::cout << point_3d << std::endl;
    return 0;
}