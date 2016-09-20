#ifndef ITEM_H
#define ITEM_H


class Item
{
    public:
        int id;
        char* nombre;
        Item* siguiente;
        Item(int id, char* nombre);
        virtual ~Item();

    protected:

    private:
};

#endif // ITEM_H
