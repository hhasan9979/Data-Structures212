#include <iostream>
#include "sequence1.h"

int main()
{
    // You can run the test code from here by importing the `sequence_test.cpp` and `sequence_exam.cpp` files
    // and using their functions.
    //std::cout << "Hello, World!" << std::endl;
    data_structures_assignment_1::sequence s1;




    s1.attach(5);
    s1.attach(6);
    s1.attach(7);




    std::cout << s1.size() << std::endl;
    std::cout << s1.is_item() << std::endl;
    std::cout << s1.current() << std::endl;
    std::cout << s1.current() << std::endl;






    return EXIT_SUCCESS;
}