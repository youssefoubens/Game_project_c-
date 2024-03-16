#include <iostream>
#include <string>
#include <conio.h>

#include "shape.h"

#include "class_shape.h"
#include "class_decalge_color.h"
#include "class_decalge_form.h"

void displayFrame(list_shape &shapeList, shape &s)
{
    int size;

    system("cls");
    //  std::cout << "\033[2J\033[1;1H"; // ANSI escape codes for clearing the console
    size = shapeList.getsize();
    std::cout << size;
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "|    " << colorizeShape(shapeToString(s.f), s.c) << "                                                              |" << std::endl;

    std::cout << "|                                                                   |" << std::endl;
    std::cout << "|     ==>                                 <==                       |" << std::endl;
    std::cout << "|                                                                   |" << std::endl;
    std::cout << "|                                                                   |" << std::endl;
    shapeList.display_shapes();
    std::cout << "--------------------------------------------------------------------" << std::endl;
    std::cout << "Press 'a' to add a shape to the right. Press 'l' to add a shape to the left. Press 'q' to exit." << std::endl;
}

shape generateRandomShape()
{
    shape randomShape;

    int colorIndex = rand() % 4;
    randomShape.c = static_cast<Color>(colorIndex);

    int shapeIndex = rand() % 4;
    randomShape.f = static_cast<ShapeType>(shapeIndex);

    randomShape.next_same_color = nullptr;
    randomShape.prev_same_color = nullptr;
    randomShape.next_same_form = nullptr;
    randomShape.prev_same_form = nullptr;
    randomShape.next_shape = nullptr;

    return randomShape;
}

void switch_color(list_shape *l)
{

    decalage_shape_color blue(Blue, l);

    decalage_shape_color yellow(Yellow, l);

    decalage_shape_color red(Red, l);

    decalage_shape_color green(Green, l);

    char c = _getch();
    switch (c)
    {
    case 'b':

        blue.decaler_color();

        break;
    case 'y':

        yellow.decaler_color();

        break;
    case 'a':

        red.decaler_color();

        break;
    case 'g':
        green.decaler_color();

        break;
    default:
        break;
    }
}

void switch_form(list_shape *l)
{

    decalage_shape_form square(Square, l);

    decalage_shape_form diamond(Diamond, l);

    decalage_shape_form circle(Circle, l);

    decalage_shape_form triangle(Triangle4, l);

    char c = _getch();
    switch (c)
    {
    case 's':

        square.decaler_form();

        break;
    case 'i':
        diamond.decaler_form();

        break;
    case 'e':

        circle.decaler_form();
        break;
    case 't':
        triangle.decaler_form();

        break;
    default:
        break;
    }
}
int main()
{
    list_shape shapeList;
    shape s;
    shapeList.insert_shape_left(Yellow, Diamond);

    shapeList.insert_shape_left(Red, Circle);

    shapeList.insert_shape_left(Yellow, Circle);
    shapeList.insert_shape_left(Blue, Square);
    shapeList.insert_shape_left(Blue, Diamond);
    shapeList.display_same_form();

    s = generateRandomShape();

    char key;
    bool exitFlag = false;
    int a;
    while (!exitFlag)
    {

        displayFrame(shapeList, s);

        key = _getch(); // Capture a key press

        switch (key)
        {
        case 'r':
            a = shapeList.getsize();
            if (a < 15)
            {
                shapeList.insert_shape_right(s.c, s.f);
                s = generateRandomShape();
            }
            else
            {
                std::cout << "you failed";
                exitFlag = true;
            }

            break;

        case 'l':
            a = shapeList.insert_shape_left(s.c, s.f) == 1;
            if (a == 1)
            {
                s = generateRandomShape();
            }
            else
            {
                std::cout << "you failed";
                exitFlag = true;
            }
            break;
        case 'f':
            shapeList.delete_three_same_linked_form();
            break;
            ;
        case 'd':
            switch_color(&shapeList);

            break;
            ;
        case 'z':
            switch_form(&shapeList);

            break;
            ;
        case 'c':
            shapeList.delete_three_same_linked_color();
            break;
            ;
        case 'q':
            exitFlag = true;
            break;

        default:
            break;
        }
    }

    return 0;
}
