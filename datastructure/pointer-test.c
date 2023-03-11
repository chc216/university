#include <stdio.h>

int main()
{
    int i, *p; //정수형 변수와 정수형 포인터를 선언한다.

    i = 10; //정수형 변수 i에 10을 대입한다.

    printf("value of i = %d\n", i); //i의 값을 printf함수로 출력한다. (i=10이므로 10이 출력된다.)
    printf("address of i = %p\n ", &i); //변수 i의 메모리 주소를 출력한다. 
    printf("value of p = %p\n", p); //포인터 p가 갖고 있는 값(자료형은 포인터)을 출력한다. (쓰레기값이 들어있다.)
    printf("address of p = %p\n", &p); //포인터 p의 메모리 주소를 출력한다.


    p = &i; //변수 i의 주소를 포인터 p에 대입한다.

    printf("\n\n----- after p = &i ------------\n\n"); 
    printf("value of p = %p\n", p); //p=&i로 인해 i가 저장되어 있는 메모리 주소가 출력된다.
    printf("address of p = %p\n", &p); //포인터 p의 주소가 출력된다. (위에서 출력한 것과 동일하게 출력된다.)
    printf("dereferencing *p = %d\n", *p); 
    //p가 갖고 있는 주소를 통해 참조한다. 즉, 변수 i의 주소를 참조하므로 i가 갖고 있는 값, 10이 출력된다.

    return 0; 
    
}asd