#include <iostream>
#include <string>
#include <random>

enum Color
{
    Blue,
    Yellow,
    Red,
    Green
};

enum ShapeType
{
    Square,
    Diamond,
    Circle,
    Triangle4
};

class Shape
{
private:
    Color color;
    ShapeType shape;
    Shape *next_;
    Shape *prev;

public:
    Shape(/* args */);
    ~Shape();
};
