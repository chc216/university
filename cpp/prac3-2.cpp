#include <iostream>

using namespace std;

int big(int a, int b)
{
    int max;

    if(a>b)
    {
        max = a;
    }
    else
        max = b;

    if(max > 100)
        return 100;
    else
        return max;
}

int big(int a, int b, int limit)
{
    int max;
    max = a;
    if(a<b)
        max = b;
    
    if(max > limit)
        return limit;
    else
        return max;
}

int main()
{
    int x = big(3, 5); 
    int y = big(300, 60);
    int z = big(30,60,50);
    cout << x << ' ' << y << ' ' << z << endl;

    return 0;
}