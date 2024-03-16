

class decalage_shape_color
{
private:
    adress *adr;
    Color c;

public:
    decalage_shape_color(Color c1, list_shape l)
    {

        c = c1;
        std::cout << "ok";
        adr = l.address_f_l_color(c);
        std::cout << "ok1hhh";
    }
    int decaler_color();
};

int decalage_shape_color::decaler_color()
{
    shape *head, *current, *temp;
    shape *tail;
    head = adr->head;
    tail = adr->tail;
    std::cout << adr->size;
    temp->f = head->f;
    if (adr->size < 2)
    {

        return 0;
    }
    current = head;
    while (current != nullptr)
    {
        //  std::cout << "|    " << colorizeShape(shapeToString(head->f), head->c);
        current->f = current->next_same_form->f;
        current = current->next_same_color;
    }
    tail->f = temp->f;
}