#include <iostream>
using namespace std;

int sum(int a, int b);

int main()
{
    int n = 0;

    cout << "끝수를 입력하세요>>";
    cin >> n;
    cout << "1부터" << n <<"까지의 합은 " << sum(1,n) <<"입니다";

    return 0;
}

int sum(int a, int b)
{
    int res = 0;
    for(int i = a; i<=b; i++)
    {
        res += i;
    }
    return res;
}