

class decalage_shape_form
{
private:
    adress *adr;
    ShapeType f;

public:
    decalage_shape_form(ShapeType f1, list_shape *l)
    {
        f = f1;
        adr = l->address_f_l_form(f);
    }
    int decaler_form();

    ~decalage_shape_form();
};

decalage_shape_form::~decalage_shape_form()
{
}

int decalage_shape_form::decaler_form()
{
    shape *head, *current, *temp;
    shape *tail;
    head = adr->head;
    tail = adr->tail;

    temp->c = head->c;
    if (adr->size < 2)
    {
        return 0;
    }
    current = head;
    while (current != nullptr)
    {
        current->c = current->next_same_form->c;
        current = current->next_same_color;
    }
    tail->c = temp->c;
}