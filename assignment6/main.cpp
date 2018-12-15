#include <iostream>
#include "bstbag.h"
#include "bintree.h"
#include <cstdlib>
#include "bstbag.cpp"
#include "bintree.cpp"

int main()
{
    std::cout << "Hello, World!" << std::endl;
    return 0;
}



/*
template<class Item>
bag <Item> bag<Item>::operator-(const bag <Item>& b1, const bag <Item>& b2)
{
    binary_tree_node<Item> *cursor2;
    cursor2 = b2.root_ptr;
    while(cursor2 != nullptr)
    {
        binary_tree_node<Item> *cursor;

        cursor = b1.root_ptr;


        while (cursor != NULL)
        {
            if (cursor->data() >= cursor2->data())
            {
                if (cursor->data() == cursor2->data())

                    bst_remove(b1.root_ptr, cursor->data());

                cursor = cursor->left();
            }
            else
                {
                cursor = cursor->right();
            }
        }
    }
}

template<class Item>
bag <Item> operator-=(const bag <Item>& b1, const bag <Item>& b2)
{

}
\*


