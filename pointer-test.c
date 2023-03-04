#include <stdio.h>

int main()
{
    int i, *p; //정수형 변수와 정수형 포인터를 선언한다.

    i = 10; //정수형 변수 i에 10을 대입한다.

    printf("value of i = %d\n", i); //i의 값을 printf함수로 출력한다.
    printf("address of i = %p\n ", &i); //변수 i의 메모리 주소를 출력한다.
    printf("value of p = %p\n", p); //포인터 p가 갖고 있는 
    printf("address of p = %p\n", &p);


    p = &i;

    printf("\n\n----- after p = &i ------------\n\n");
    printf("value of p = %p\n", p);
    printf("address of p = %p\n", &p);
    printf("dereferencing *p = %d\n", *p);

    return 0; 
    
}