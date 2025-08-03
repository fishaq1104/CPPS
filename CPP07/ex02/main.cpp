#include "Array.hpp"

int main() 
{
    try 
    {
        Array<int> a(5);

        for (unsigned int i = 0; i < a.size(); i++)
            a[i] = i * 10;

        for (unsigned int i = 0; i < a.size(); i++)
            std::cout << "a[" << i << "] = " << a[i] << std::endl;

        a[2] = 4;
        Array<int> b = a;
        Array<int> c;
        c = b;

        std::cout << "\nCopied array c:" << std::endl;
        for (unsigned int i = 0; i < c.size(); i++)
            std::cout << "c[" << i << "] = " << c[i] << std::endl;

        std::cout << a[-1] << std::endl;
    } 
    catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

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
