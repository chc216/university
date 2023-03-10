#include <iostream>

int main()
{

    for(int j = 1; j<=4; j++)
    {
        for(int i = 1; i<=j; i++)
        {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}