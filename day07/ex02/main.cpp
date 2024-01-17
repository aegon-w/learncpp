#include <iostream>
#include <cstdlib>
#include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//         std::cout << numbers[MAX_VAL] << std::endl;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

template < typename T >
std::ostream& operator<<( std::ostream& out, const Array<T>& arr ) {
    for ( unsigned int i( 0 ); i < arr.size(); i++ )
        out << arr[i] << " ";
    return out;
}

int main()
{
    Array<int> array(5);
    for (unsigned int i = 0; i < array.size(); i++)
        array[i] = i;
    std::cout << array << std::endl;
    Array<int> array2(array);
    std::cout << array2 << std::endl;
    try
    {
        std::cout << array[5] << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}