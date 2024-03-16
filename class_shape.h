
struct adress
{
    shape *head1;
    shape *tail1;
    int size;
};
class list_shape
{
private:
    shape *head;
    shape *tail;
    int size;

public:
    list_shape();
    int insert_shape_right(Color c, ShapeType s);
    int insert_shape_left(Color c, ShapeType s);
    shape delete_shape();
    int getsize();
    void delete_three_same_linked_color();
    void delete_three_same_linked_form();
    void display_same_form();
    void display_shapes();
    adress *address_f_l_color(Color c);
    adress *address_f_l_form(ShapeType f);
    ~list_shape();
};
void list_shape::display_same_form()
{
    shape *current = head;
    while (current != nullptr)
    {
        std::cout << current->f << " ";

        current = current->next_same_form;
    }
}
int list_shape::getsize()
{
    return size;
};
list_shape::list_shape()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

int list_shape::insert_shape_right(Color c, ShapeType s)
{
    shape *newShape = new shape;

    newShape->c = c;
    newShape->f = s;
    newShape->next_shape = nullptr;
    newShape->prev_shap = nullptr;
    newShape->next_same_color = nullptr;
    newShape->next_same_form = nullptr;
    if (size == 15)
    {
        std::cout << "impossible d ajouter";
        return 0;
    }
    else
    {
        try
        {
            /* code */

            if (head == nullptr)
            {
                head = newShape;
                tail = newShape;
            }
            else
            {
                shape *current = tail;
                while (current != nullptr)
                {
                    if (newShape->c == current->c)
                    {
                        newShape->prev_same_color = current;

                        break;
                    }

                    current = current->prev_shap;
                }
                shape *current1 = tail;
                while (current1 != nullptr)
                {
                    if (newShape->f == current1->f)
                    {
                        newShape->prev_same_form = current1;

                        break;
                    }

                    current1 = current1->prev_shap;
                }

                tail->next_shape = newShape;
                newShape->prev_shap = tail;
                tail = newShape;
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }

        return 1;
    }
}

int list_shape::insert_shape_left(Color c, ShapeType s)
{
    shape *newShape = new shape;

    newShape->c = c;
    newShape->f = s;
    newShape->next_shape = nullptr;
    newShape->prev_shap = nullptr;
    newShape->next_same_color = nullptr;
    newShape->next_same_form = nullptr;
    if (size == 15)
    {
        std::cout << "impossible d ajouter";
        return 0;
    }
    else
    {
        if (head == nullptr)
        {
            head = newShape;
            tail = newShape;
        }
        else
        {
            shape *current = head;
            while (current != nullptr)
            {
                if (newShape->c == current->c)
                {
                    newShape->next_same_color = current;
                    std::cout << "smae colore next";
                    break;
                }

                current = current->next_shape;
            }
            shape *current1 = head;
            while (current1 != nullptr)
            {

                if (newShape->f == current1->f)
                {
                    newShape->next_same_form = current1;
                    std::cout << "smae form next";
                    break;
                }

                current1 = current1->next_shape;
            }

            head->prev_shap = newShape;
            newShape->next_shape = head;
            head = newShape;
        }

        size++;
        return 1;
    }
}

shape list_shape::delete_shape()
{
    shape deletedShape;

    if (head == nullptr)
    {
        std::cerr << "List is empty. Cannot delete shape." << std::endl;
    }
    else
    {
        deletedShape = *head;
        shape *temp = head;
        head = head->next_shape;
        head->prev_shap = nullptr;
        delete temp;
        size--;
    }

    return deletedShape;
}

void list_shape::delete_three_same_linked_color()
{
    shape *current = head;

    while (current != nullptr)
    {
        if (current->next_shape != nullptr && current->next_shape->next_shape != nullptr)
        {
            if (current->c == current->next_shape->c && current->c == current->next_shape->next_shape->c)
            {
                size -= 3;
                shape *temp1 = current;
                shape *temp2 = current->next_shape;
                shape *temp3 = current->next_shape->next_shape;
                if (current == head)
                {
                    temp3->next_shape->prev_shap = nullptr;
                    head = temp3->next_shape;
                    delete temp1;
                    delete temp2;
                    delete temp3;
                    break;
                }
                else if (temp3 == tail)
                {
                    tail = temp1->prev_shap;
                    tail->next_shape = nullptr;
                    delete temp1;
                    delete temp2;
                    delete temp3;
                    break;
                }
                else
                {
                    temp1->prev_shap->next_shape = temp3->next_shape;

                    delete temp1;
                    delete temp2;
                    delete temp3;

                    break;
                }
            }
        }

        current = current->next_shape;
    }
}

void list_shape::delete_three_same_linked_form()
{
    shape *current = head;
    while (current != nullptr)
    {
        if (current->next_shape != nullptr && current->next_shape->next_shape != nullptr)
        {
            if (current->f == current->next_shape->f && current->f == current->next_shape->next_shape->f)
            {
                size -= 3;
                shape *temp1 = current;
                shape *temp2 = current->next_shape;
                shape *temp3 = current->next_shape->next_shape;
                if (current == head)
                {
                    temp3->next_shape->prev_shap = nullptr;
                    head = temp3->next_shape;
                    delete temp1;
                    delete temp2;
                    delete temp3;
                    break;
                }
                else if (temp3 == tail)
                {
                    tail = temp1->prev_shap;
                    tail->next_shape = nullptr;
                    delete temp1;
                    delete temp2;
                    delete temp3;
                    break;
                }
                else
                {
                    temp1->prev_shap->next_shape = temp3->next_shape;

                    delete temp1;
                    delete temp2;
                    delete temp3;

                    break;
                }
            }
        }

        current = current->next_shape;
    }
}

void list_shape::display_shapes()
{
    shape *current = head;
    std::cout << "|        ";
    while (current != nullptr)
    {
        std::cout << "  " << colorizeShape(shapeToString(current->f), current->c) << "  ";
        current = current->next_shape;
    }

    std::cout << std::endl;
}

list_shape::~list_shape()
{
    while (head != nullptr)
    {
        shape *temp = head;
        head = head->next_shape;
        delete temp;
    }
}

adress *list_shape::address_f_l_color(Color c)
{
    shape *current = head;
    adress *temp = new adress;
    int size = 0;

    while (current != nullptr)
    {
        if (current->c == c)
        {

            size = 1;
            temp->head1 = current;

            while (current != nullptr)
            {

                if (current->next_same_color == nullptr)
                {

                    std::cout << "|" << colorizeShape(shapeToString(current->f), current->c);
                    temp->tail1 = current;
                    temp->size = size;
                    return temp;
                }
                else
                {
                    std::cout << " no ";
                    size++;
                    current = current->next_same_color;
                }
            }
        }
        current = current->next_shape;
    }
}

adress *list_shape::address_f_l_form(ShapeType f)
{
    shape *current = head;
    adress *temp;
    int size = 0;

    while (current != nullptr)
    {
        if (current->f == f)
        {
            size = 1;
            temp->head1 = current;
            while (current != nullptr)
            {

                if (current->next_same_color == nullptr)
                {

                    temp->tail1 = current;
                    temp->size = size;
                    return temp;
                }
                else
                {
                    size++;
                    current = current->next_same_color;
                }
            }
        }
        current = current->next_shape;
    }
}