// here you can add color or form

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

std::string shapeToString(ShapeType s)
{
    switch (s)
    {
    case Square:
        return "S";
    case Diamond:
        return "D";
    case Circle:
        return "O";
    case Triangle4:
        return "A";
    default:
        return "Unknown";
    }
}

// Function to colorize a shape based on its color
std::string colorizeShape(const std::string &shape, Color c)
{
    std::string coloredShape = shape;

    switch (c)
    {
    case Blue:
        coloredShape = "\033[34m" + coloredShape + "\033[0m"; // Blue
        break;
    case Yellow:
        coloredShape = "\033[33m" + coloredShape + "\033[0m"; // Yellow
        break;
    case Red:
        coloredShape = "\033[31m" + coloredShape + "\033[0m"; // Red
        break;
    case Green:
        coloredShape = "\033[32m" + coloredShape + "\033[0m"; // Green
        break;
    default:
        break;
    }

    return coloredShape;
}

struct shape
{
    Color c;
    ShapeType f;
    shape *next_same_color;
    shape *prev_same_color;
    shape *next_same_form;
    shape *prev_same_form;
    shape *next_shape;
    shape *prev_shap;
};