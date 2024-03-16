#include <iostream>
#include <vector>
#include <numbers>

class Shape {
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return std::numbers::pi * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
};

double total_area(std::vector<Shape*> shapes) {
    double area = 0;
    for (Shape *shape : shapes) 
        area += shape->area();
    return area;
}

double circle_area(std::vector<Shape*> shapes) {
    double area = 0;
    for (Shape *shape : shapes) {
        Circle *circle = dynamic_cast<Circle*>(shape);
        if (circle != nullptr)
            area += circle->area();
    }
    return area;
}

int main(){
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(1));
    shapes.push_back(new Rectangle(1, 2));
    shapes.push_back(new Circle(2));
    shapes.push_back(new Rectangle(2, 3));

    std::cout << "Total area: " << total_area(shapes) << std::endl;
    std::cout << "Total circle area: " << circle_area(shapes) << std::endl;

    for (Shape *shape : shapes)
        delete shape;

    return 0;
}