#include <iostream>

using namespace std;

template <class T>
void reverse(T a[], int size)
{
    T tmp;
    for(int i = 0; i < size/2; i++)
    {
        tmp = a[(size-1) - i];
        a[(size-1) - i] = a[i];
        a[i] = tmp;
    }
}

int main()
{
    int x[] = {1,2,3,4,5};
    reverse(x, 5);
    for(int i = 0; i < 5; i++)
    {
        cout << x[i] << ' ';
    }
    cout << endl;]                
    return 0;
}
