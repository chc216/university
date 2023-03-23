#include <iostream>
using namespace std;

bool bigger(int a, int b, int& big)
{
    if(a > b)
    {
        big = a;
    }
    else
    {
        big = b;
    }

    if(a == b)
        return true;
    else
        return big;

}

int main()
{
    int a, b, big;
    cin >> a >> b;
    bigger(a,b, big);

    cout << big << endl;
    return 0;
}