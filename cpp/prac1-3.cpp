#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char string[100];
    cout << "문자들을 입력하시오(100개 미만)" << endl;

    cin.getline(string, 100, '\n');

    int i = 0;
    int count = 0;
    while(string[i] != '\0')
    {
        if(string[i] == 'x')
        {
            count ++;
        }
        i++;
    }

    cout <<"X의 개수는 " << count;

    return 0;
}