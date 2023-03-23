#include <iostream>
#include <string>
using namespace std;

int main()
{
    string newkey1, newkey2;

    cout << "새 암호를 입력하세요 >> ";
    getline(cin, newkey1);
    
    cout << "새 암호를 다시 한 번 입력하세요 >> ";
    getline(cin, newkey2);

    if(newkey1 == newkey2)
    {
        cout << "같습니다.";;
    }
    else
    {
        cout << "같지 않습니다.";
    }
    
}