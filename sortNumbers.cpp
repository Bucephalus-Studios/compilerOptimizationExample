#include <vector>
#include "stevensFileLib.hpp"
#include <time.h>
#include <algorithm>
#include <iostream>

int main()
{
    //Get a list of one million unsorted numbers
    std::vector<int> numbers = stevensFileLib::loadFileIntoVectorOfInts("1M_unsorted_random_integers.txt");

    //Start the clock
    clock_t tStart = clock();

    //Sort the list of unsorted numbers
    std::sort(numbers.begin(), numbers.end());

    //Print the time that the program took to sort the numbers
    std::cout << "Sorting time: " << (double)(clock() - tStart)/CLOCKS_PER_SEC<< " seconds" << std::endl;

    return 0;
}