
// this class for decaler les shapes de meme color
class decalage_shape_color
{
private:
    adress *adr;
    Color c;

public:
    decalage_shape_color(Color c1, list_shape *l)
    {

        c = c1;

        adr = l->address_f_l_color(c);
    }
    int decaler_color();
};

int decalage_shape_color::decaler_color()
{
    shape *head, *current, temp;
    shape *tail;
    head = adr->head1;
    tail = adr->tail1;

    temp.f = head->f;
    if (adr->size < 2)
    {

        return 0;
    }
    current = head;

    while (current != nullptr)
    {

        current->f = current->next_same_color->f;
        current = current->next_same_color;
        if (current->next_same_color == nullptr)
        {
            break;
        }
    }
    tail->f = temp.f;
}