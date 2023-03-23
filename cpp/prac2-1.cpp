#include <iostream>

using namespace std;
int main()
{
    int M[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int (*ptr)[3];
    int *p;
    int **pt;
    
    ptr = M;
    cout << ptr << " : ptr 값" << endl;
    cout << ptr + 1 << M+1 << ": M[2] 주소" << endl;
    cout << *(ptr + 1) << ptr[1] << *(M+1) << M[1] << ": M[1] 주소" << endl;
    cout << **(ptr + 1) << **(M+1) << *M[1] << M[1][0] << ": M[1][0] 원소 참조" << endl;

    p = M[0];
    cout << p << M[0] << *M << ": M[0]주소 참조" << endl;
    cout << p+1 << M[0] + 1 << *M+1 << ": 배열포인터를 이용하여 M[1] 주소 접근" << endl;
    cout << *(p+1) << *(M[0]+1) << *(*M+1) << endl;

    pt = &p;
    cout << *pt << p << endl;
    cout << **pt << *p;

}