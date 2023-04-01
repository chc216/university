#include <iostream>

using namespace std;

template <class T>
T add(T a[], int size)
{
    T sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += a[i];
    }
    return sum;
}

int main()
{
    int x[] = {1,2,3,4,5};
    double b[] = {1.0,2.0,3.0,4.0,5.0};

    cout << "sum of x[] = " << add(x, 5) << endl;
    cout << "sum of b[] = " << add(b, 5) << endl;

    return 0;
    
}