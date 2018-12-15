#include <iostream>
#include "maze.h"

using std::ostream;
using data_structures_assignment_5::maze;
using data_structures_assignment_5::maze_node;

void triangle(ostream& outs, unsigned int m, unsigned int n)
// Precondition: m <= n
// Postcondition: The function has printed a pattern of 2*(n-m+1) lines
// to the output stream outs. The first line contains m asterisks, the next
// line contains m+1 asterisks, and so on up to a line with n asterisks.
// Then the pattern is repeated backwards, going n back down to m.
/* Example output:
   triangle(cout, 3, 5) will print this to cout:
   ***
   ****
   *****
   *****
   ****
   ***
*/
{
    if (m > n)
    {
        return;
    }

    for (int i = 0; i < m; i++)
    {
        std::cout << "*";
    }

    std::cout << std::endl;

    if(m != n+1)
    {
        triangle(outs, m +1, n);
        for(int i = 0; i < m; i++)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int count_ways_to_step(int number_of_stepping_stones)
// Precondition: number_of_stepping_stones > 0
// Postcondition: The number of ways to reach the final stepping stone using
// either a small step (moving 1 stepping stone) or a large step (moving 2 stepping
// stones) in any combination is returned.
// For 3 stepping stones there are 3 ways. For 4 stepping stones, there are 5 ways.
{

    if(number_of_stepping_stones <= 1 )
    {
        return 1;
    }

    if(number_of_stepping_stones == 1)
    {
        count_ways_to_step(number_of_stepping_stones - 1);
    }

    return count_ways_to_step(number_of_stepping_stones - 1) + count_ways_to_step(number_of_stepping_stones - 2);

}

bool print_path_through_maze(const maze_node* maze_position)
// Postcondition: Prints the path through the maze, with 0s representing right
// turns and 1s representing left turns.
// You may print the path in reverse order (this will be easier).
// Hint: Use the return boolean to signify that the current path is the correct path.
{

    if (maze_position->is_finish())
    {
        //std::cout << "";

       // std::cout << " reach1 ";
        return true;

    }

    if(maze_position->left() == NULL && maze_position->right() == NULL && !maze_position->is_finish())
    {
       // std::cout << " reach2 ";
        return false;
    }


    if (maze_position->left() != NULL )
    {
      //  std::cout << " reach3 ";
        print_path_through_maze(maze_position->left());
        if (maze_position->left() != NULL || maze_position->is_finish())
        std::cout << "0";
    }

    if (maze_position->right() != NULL)
    {
       // std::cout << " reach4 ";
        print_path_through_maze(maze_position->right());
        if (maze_position->right() != NULL || maze_position->is_finish())
        std::cout << "1";
    }

        // return(print_path_through_maze(maze_position->left()) || print_path_through_maze(maze_position->right()));
}


    int main()
    {
        // You can test your code by adding it here.

         maze m1(0);
         print_path_through_maze(m1.get_start());
         std::cout << std::endl;
        triangle(std::cout,3,5);
        std:: cout << count_ways_to_step(6);

        return 0;
    }
