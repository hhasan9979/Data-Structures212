// You must add all the code for this file.
#include <cassert>
#include "sequence1.h"
#include <cstdlib>  // Provides size_t

//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT
//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT

// 1. The number of items in the sequence is stored in the member variable "used".
// 2. The member variable, "current_index" is used to return items from the data, insert and attach values in the data.
// 3. The items are stored through data[0] to data[used - 1] and we don't care what is stored in the rest of the data.

//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT
//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT

namespace data_structures_assignment_1
{

    // CONSTRUCTOR for the sequence class:
    sequence::sequence( )
    {
        used = 0;
        current_index = 0;
    }
//     Postcondition: The sequence has been initialized as an empty sequence.
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:
    void sequence::start( )
    {
        current_index = 0;
    }
//     Postcondition: The first item on the sequence becomes the current item
//     (but if the sequence is empty, then there is no current item).
//
    void sequence::advance( )
    {
        assert(is_item());

        ++current_index;
    }

//     Precondition: is_item returns true.
//     Postcondition: If the current item was already the last item in the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
    void sequence::insert(const value_type& entry)
    {
        assert(size( ) < CAPACITY);

       size_type i;

        if(!is_item())
            current_index = 0;

        for (i = used; i > current_index; --i)

            data[i]=data[i-1];

        data[current_index] = entry;

        ++used;



      //  ++used;
      //  size_type i;
      //  for(i = used; i < current_index; i--)
      //  {
      //      data[i] = data[i-1];
      //  }
      //  data[current_index] = entry;
    }
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence
//     before the current item. If there was no current item, then the new entry
//     has been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
    void sequence::attach(const value_type& entry)
    {
        assert(size( ) < CAPACITY);

        size_type i;

        if(!is_item())

            current_index = used - 1 ;

        for (i = used; i > current_index; --i)
            data[i]=data[i-1];

        data[current_index + 1] = entry;
        ++current_index;
        ++used;




    }
//     Precondition: size( ) < CAPACITY.
//     Postcondition: A new copy of entry has been inserted in the sequence after
//     the current item. If there was no current item, then the new entry has
//     been attached to the end of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
    void sequence::remove_current( )
    {
        assert(is_item());

        size_type temp;

        for( temp = current_index + 1; temp < used; temp++ )
        {
            data[temp - 1] = data[temp];
        }

        --used;
    }
//     Precondition: is_item returns true.
//     Postcondition: The current item has been removed from the sequence, and the
//     item after this (if there is one) is now the new current item.
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:

    sequence::size_type sequence::size( ) const
    {
        return used;
    }
//     Postcondition: The return value is the number of items in the sequence.
//
    bool sequence::is_item( ) const
    {
        return used > current_index;

    }
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
    sequence::value_type sequence::current( ) const
    {
        assert(is_item());
        return data[current_index];
    }
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//

}