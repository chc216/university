#include <iostream>
using namespace std;

double getmax(double x[])
{
    double max = x[0];
    for(int i = 0; i<5; i++)
    {
        if(max <= x[i])
        {
            max = x[i];
        }
    }
    return max;
}

int main()
{
    double x[5];
    cout << "5개의 실수를 입력하라 >>";
    for(int i = 0; i<5; i++)
    {
        cin >> x[i] ;
    }

    cout << "제일 큰 수 = " << getmax(x);
}