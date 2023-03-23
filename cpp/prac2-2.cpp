#include <iostream>

using namespace std;

bool average(int a[], int size, int& avg)
{

    if(size >= 0) //인자로 넘겨받은 배열의 크기는 구할 수 없다 왜 ? (동적 메모리 할당이기 때문)
    {
        int sum = 0;
        for(int i = 0; i < size; i++)
        {
            sum += a[i];
        }
        avg = sum / size;
        return true;
    }    
    else
        return false;
}

int main()
{
    int x[] = {0,1,2,3,4,5};
    int avg;
    if(average(x, 6, avg))
        cout << "평균은 " << avg << endl;
    else
        cout << " 매개 변수 오류 " << endl;

    if(average(x,-1,avg))
        cout << "평균은 " << avg << endl;
    else
        cout << "매개변수 오류 " << endl;
}