#include <cassert>
#include "sequence3.h"
#include <cstdlib>  // Provides size_t
// FILE: sequence3.h
// CLASS PROVIDED: sequence (a container class for a sequence of items,
// where each sequence may have a designated item called the current item)
//
// TYPEDEF for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and a copy constructor.
//
// INVARIANT FOR LINKED LISTS
// The items in the sequence are in a linked list
// The head pointer in called the head_ptr pointer
// Number of nodes is in variable: many_nodes

#include "node1.h" // Provides linked list toolkit

namespace data_structures_assignment3
{
    // CONSTRUCTOR for the sequence class:
    sequence::sequence()
    {
        head_ptr = NULL;
        tail_ptr = NULL;
        precursor = NULL;
        cursor = NULL;
        many_nodes = 0;
    }
    //     Postcondition: The sequence has been initialized as an empty sequence.
    //

    sequence::sequence(const sequence& source) //Notation: O(1)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;

        node *temp = source.head_ptr;
        precursor = head_ptr;


        if(source.cursor == NULL && (source.precursor == NULL || source.precursor != NULL))
        {
            cursor = NULL;
            precursor = NULL;
        }
        if(source.cursor != NULL && source.precursor == NULL)
        {
            cursor = head_ptr;
            precursor = NULL;
        }
        if(source.cursor != NULL && source.precursor != NULL)
        {
            while(temp != source.precursor)
            {
                temp = temp->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }

   }

   sequence::~sequence() //Notation: O(1)
    {
        list_clear(head_ptr);
        many_nodes = 0;
    }

    // MODIFICATION MEMBER FUNCTIONS for the sequence class:
      void sequence::start( ) //Notation: O(1)
    {
        if(head_ptr == NULL)
        {
            cursor= NULL;
            precursor= NULL;
        }
        else
        {
            precursor = NULL;
            cursor= head_ptr;
        }

    }
    //     Postcondition: The first item on the sequence becomes the current item
    //     (but if the sequence is empty, then there is no current item).
    //
    void sequence::advance( ) //Notation: O(1)
    {
        assert(is_item());

        if(cursor == tail_ptr)
        {
            cursor = NULL;
            precursor = NULL;
        }
        else
        {
            precursor = cursor;
            cursor = cursor->link();
        }

    }
    //     Precondition: is_item returns true.
    //     Postcondition: If the current item was already the last item on the
    //     sequence, then there is no longer any current item. Otherwise, the new
    //     current item is the item immediately after the original current item.
    //

    void sequence::insert(const value_type& entry) //Notation: O(n)
    {
        if (is_item()) //cursor is valid
        {
            if (precursor == NULL) //cursor points to first node
            {

                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }

            else
            {

                list_insert(precursor, entry);
                cursor = precursor->link();
            }
        }

        else //cursor not pointing to valid node
        {
            if (size() == 0)
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                tail_ptr = head_ptr;
                precursor = NULL;
            }

            else
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                precursor = NULL;
            }
        }

        many_nodes++;
   }
    //     Postcondition: A new copy of entry has been inserted in the sequence before
    //     the current item. If there was no current item, then the new entry has
    //     been inserted at the front of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
    //
    void sequence::attach(const value_type& entry) //Notation: O(n)
    {

        if (is_item())
        {
            if((cursor->link()) == NULL)
            {
                list_insert(cursor, entry);
                precursor = cursor;
                cursor = cursor->link();
                tail_ptr = cursor;
            }

            else
            {
                list_insert(cursor, entry);
                precursor = cursor;
                cursor = cursor->link();
            }
        }

        else
        {
            if(size() == 0)
            {
                list_head_insert(head_ptr, entry);
                cursor = head_ptr;
                tail_ptr = head_ptr;
                precursor = NULL;
            }

            else
            {
                precursor = tail_ptr;
                list_insert(tail_ptr, entry);
                tail_ptr = tail_ptr->link();
                cursor = tail_ptr;
            }
        }
        ++many_nodes;
   }
    //     Postcondition: A new copy of entry has been inserted in the sequence after
    //     the current item. If there was no current item, then the new entry has
    //     been attached to the end of the sequence. In either case, the newly
    //     inserted item is now the current item of the sequence.
    //
    void sequence::remove_current( ) //Notation: O(n)
    {
        assert(is_item());

        if (precursor == NULL) //first node
        {
            list_head_remove(head_ptr);
            cursor = head_ptr;
        }

        else
        {
            cursor = cursor->link();
            list_remove(precursor);
        }
        many_nodes--;
   }
    //     Precondition: is_item returns true.
    //     Postcondition: The current item has been removed from the sequence, and the
    //     item after this (if there is one) is now the new current item.
    //
    // CONSTANT MEMBER FUNCTIONS for the sequence class:
    size_t sequence::size( ) const //Notation: O(1)
    {
        return many_nodes;
    }
    //     Postcondition: The return value is the number of items on the sequence.
    //
    bool sequence::is_item( ) const //Notation: O(1)
    {
        return(cursor!= NULL);

    }
    //     Postcondition: A true return value indicates that there is a valid
    //     "current" item that may be retrieved by activating the current
    //     member function (listed below). A false return value indicates that
    //     there is no valid current item.
    //

    void sequence::operator=(const sequence& source) //Notation: O(n)
    {
        list_copy(source.head_ptr, head_ptr, tail_ptr);
        many_nodes = source.many_nodes;

        node *temp = source.head_ptr;
        precursor = head_ptr;


        if(source.cursor == NULL && (source.precursor == NULL || source.precursor != NULL))
        {
            cursor = NULL;
            precursor = NULL;
        }
        if(source.cursor != NULL && source.precursor == NULL)
        {
            cursor = head_ptr;
            precursor = NULL;
        }
        if(source.cursor != NULL && source.precursor != NULL)
        {
            while(temp != source.precursor)
            {
                temp = temp->link();
                precursor = precursor->link();
            }
            cursor = precursor->link();
        }
    }

    node::value_type sequence::current( ) const //Notation: O(1)
    {
        assert(is_item());
        return cursor->data();
    }

    //     Precondition: is_item( ) returns true.
    //     Postcondition: The item returned is the current item on the sequence.
    //
    // VALUE SEMANTICS for the sequence class:
    //    Assignments and the copy constructor may be used with sequence objects.
    //
    // DYNAMIC MEMORY USAGE by the sequence:
    //   If there is insufficient dynamic memory, then the following functions call
    //   new_handler: The constructors, insert, attach, and the
    //   assignment operator.
}