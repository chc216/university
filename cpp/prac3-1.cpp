#include <iostream>

using namespace std;

void f(char a=' ', int line = 1)
{
    for(int j=0; j<line; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            cout << a;
        }
        cout << endl;
    }
}

int main()
{
    f();
    f('%');
    f('@',5);

    return 0;
}