#include <iostream>

int main()
{
    int sum=0, i;
    for(i = 1; i<=10; i++)
    {
        sum+=i;
    }
    std::cout << "1부터 10까지 더한 결과는" << sum << "입니다";
    return 0;
}