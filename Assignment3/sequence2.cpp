// You must add all the code for this file.
#include <cassert>
#include "sequence2.h"
#include <cstdlib>  // Provides size_t
#include <algorithm>

//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT
//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT

//
//1. The number of items in the bag is in the member variable used.
//2. The items of the array are in a dynamic array, pointed to by the member variable data.
//3. The total size of the dynamic array is in the member variable capacity.

//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT
//INVARIANT INVARIANT INVARIANT INVARIANT INVARIANT

namespace data_structures_assignment_3
{

    const sequence::size_type sequence::DEFAULT_CAPACITY;
    // TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const size_type DEFAULT_CAPACITY = _____
//     sequence::DEFAULT_CAPACITY is the initial capacity of a sequence that is
//     created by the default constructor.
//
//
// CONSTRUCTOR for the sequence class:

   sequence::sequence(size_type initial_capacity)
    {
       data = new value_type[initial_capacity];
       capacity = initial_capacity;
       used = 0;
       current_index = 0;
    }
//     Postcondition: The sequence has been initialized as an empty sequence.
//     The insert/attach functions will work efficiently (without allocating
//     new memory) until this capacity is reached.
//
     sequence::sequence(const sequence& source)
    {
       data = new value_type[source.capacity];
       capacity = source.capacity;
       used = source.used;
       std::copy(source.data, source.data + used, data);
       current_index = source.current_index;

    }

//    - write these preconditions and postconditions yourself!

//      Postcondition: This is the sequence copy constructor. Create a copy of the original data
//      by taking the data, capacity and used attributes from the source. The final product
//      is a dynamic array with new capacity and used.

    sequence::~sequence()
    {
       delete [] data;
    }
//
// MODIFICATION MEMBER FUNCTIONS for the sequence class:

   void sequence::resize(size_type new_capacity)
   {
       value_type *larger_array;

       if (new_capacity == capacity)
       {
           return;
       }

       if (new_capacity < used)
           new_capacity = used;

       larger_array = new value_type[new_capacity];

       std::copy(data, data + used, larger_array);

       delete [ ] data;
       data = larger_array;
       capacity = new_capacity;
   }

//     Postcondition: The sequence's current capacity is changed to the
//     new_capacity (but not less that the number of items already on the
//     sequence). The insert/attach functions will work efficiently (without
//     allocating new memory) until this new capacity is reached.
//
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
//     Postcondition: If the current item was already the last item on the
//     sequence, then there is no longer any current item. Otherwise, the new
//     current item is the item immediately after the original current item.
//
    void sequence::insert(const value_type& entry)
    {
        if (used == capacity)
        {
            resize(used + (used/10));
        }

        size_type i;

        if(!is_item())
            current_index = 0;

        for (i = used; i > current_index; --i)

            data[i]=data[i-1];

        data[current_index] = entry;

        ++used;
    }

//     Postcondition: A new copy of entry has been inserted in the sequence before
//     the current item. If there was no current item, then the new entry has
//     been inserted at the front of the sequence. In either case, the newly
//     inserted item is now the current item of the sequence.
//
    void sequence::attach(const value_type& entry)
    {
        if (used == capacity)
        {
            resize(used + (used/10));
        }

        size_type i;

        if(!is_item())

            current_index = used - 1 ;

        for (i = used; i > current_index; --i)
            data[i]=data[i-1];

        data[current_index + 1] = entry;
        ++current_index;
        ++used;
    }
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
//     Postcondition: The return value is the number of items on the sequence.
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
//     Postcondition: The item returned is the current item on the sequence.
//
    void sequence::operator=(const sequence &source)
    {
        value_type *larger_array;

        if(this == &source)
            return;

        if(capacity != source.capacity)
        {
            larger_array = new value_type[source.capacity];
            delete [] data;
            data = larger_array;
            capacity = source.capacity;
        }

        used = source.used;
        current_index = source.current_index;

	    std::copy(source.data, source.data + used, data);
    }



// VALUE SEMANTICS for the sequence class:
//   Assignments and the copy constructor may be used with sequence objects.
//
// DYNAMIC MEMORY USAGE by the sequence
//   If there is insufficient dynamic memory, then the following functions
//   call new_handler: The constructors, insert, attach.
}