#include <iostream>
#include <vector>

using namespace std;

class Shape {
public:
    virtual void getValues() = 0;
    virtual void calculateArea() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    float radius;
    float area;
public:
    void getValues() override {
        cout << "Enter the radius of the circle: ";
        cin >> radius;
    }
    void calculateArea() override {
        area = 3.14 * radius * radius;
        cout << "Area of the circle is: " << area << endl;
    }
};

class Square : public Shape {
private:
    float side;
    float area;
public:
    void getValues() override {
        cout << "Enter the side of the square: ";
        cin >> side;
    }
    void calculateArea() override {
        area = side * side;
        cout << "Area of the square is: " << area << endl;
    }
};

class Ellipse : public Shape {
private:
    float major_axis;
    float minor_axis;
    float area;
public:
    void getValues() override {
        cout << "Enter the major axis of the ellipse: ";
        cin >> major_axis;
        cout << "Enter the minor axis of the ellipse: ";
        cin >> minor_axis;
    }
    void calculateArea() override {
        area = 3.14 * major_axis * minor_axis;
        cout << "Area of the ellipse is: " << area << endl;
    }
};

class Rectangle : public Shape {
private:
    float length;
    float breadth;
    float area;
public:
    void getValues() override {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the breadth of the rectangle: ";
        cin >> breadth;
    }
    void calculateArea() override {
        area = length * breadth;
        cout << "Area of the rectangle is: " << area << endl;
    }
};

int main() {
    vector<Shape*> shapes {new Circle, new Square, new Ellipse, new Rectangle};
    for (auto shape : shapes) {
        shape->getValues();
        shape->calculateArea();
        delete shape;
    }

    return 0;
}
