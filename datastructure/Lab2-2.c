#include <stdio.h>

int main()
{
    int i;
    int *ptr;
    int **dptr; //정수형 변수와 정수형 포인터 변수 선언.

    i = 1234; //정수형 변수 i에 1234를 저장한다.

    printf("\n\n[----- [최현철] [2022078014] -----]\n\n");

    printf("[checking values before ptr = &i] \n"); //포인터 Ptr에 i의 주소를 넣기 전에 들어있는 값을 점검합니다.
    printf("value of i == %d\n", i);    //i의 값을 출력합니다. 1234를 저장했으므로 1234가 출력됩니다.
    printf("address of i == %p\n", &i); //i가 메모리 상에 저장된 주소 값을 출력합니다.
    printf("value of ptr == %p\n", ptr);//포인터 변수 ptr에 저장된 값을 출력합니다. 아무것도 저장하지 않았으므로 쓰레기 값이 출력된다.


    ptr = &i; /* ptr is now holding the address of i */ //변수 i의 주소를 포인터 변수 ptr에 저장합니다.

    printf("\n[checking values after ptr = &i] \n"); 
    printf("value of i == %d\n", i);        //i의 값을 출력합니다.
    printf("address of i == %p\n", &i);     //메모리 상의 i의 주소를 출력합니다.
    printf("value of ptr == %p\n", ptr);    //ptr이 저장하고 잇는 주소값을 출력합니다. i의 주소값과 동일합니다.
    printf("address of ptr == %p\n", &ptr); //포인터 변수 ptr의 주소값을 출력합니다.
    printf("value of *ptr == %d\n", *ptr);  //참조연산자를 이용하여 i의 값을 역참조합니다. i의 값, 1234가 출력됩니다.

    dptr = &ptr; /*dptr is now holding the address of ptr */ //포인터 변수 ptr의 주소를 이중포인터 변수 dptr에 저장합니다.

    printf("\n[checking values after dptr = &ptr] \n"); 
    printf("value of i == %d\n", i);        //i의 값을 출력합니다.
    printf("address of i == %p\n", &i);     //i의 주소값을 출력합니다.
    printf("value of ptr == %p\n", ptr);    //포인터 변수 ptr의 주소값을 출력합니다.
    printf("address of ptr == %p\n", &ptr); //ptr의 주소값을 출력합니다.
    printf("value of *ptr == %d\n", *ptr);  //ptr이 갖고 있는 주소를 통해 역참조합니다. i의 값인 1234가 출력됩니다.
    printf("value of dptr == %p\n", dptr);  //dptr이 갖고 있는 주소값을 출력합니다. ptr의 주소값이 출력됩니다.
    printf("address of dptr == %p\n", &dptr);   //이중포인터 변수 dptr의 주소값을 출력합니다.
    printf("value of *dptr == %p\n", *dptr);    //이중포인터 변수 dptr이 갖고 있는 주소값을 통해 역참조합니다. ptr이 갖고 있는 변수 i의 주소값이 출력됩니다.
    printf("value of **dptr == %d\n", **dptr);  /*역참조를 두번합니다. dptr이 갖고 있는 주소값을 통해 역참조를 한 후, 
                                                그 역참조한 곳이 가지고 있는 주소값을 통해 한번 더 역참조 합니다.*/

    *ptr = 7777; /* changing the value of *ptr */ //ptr이 가리키고 있는 주소의 값을 7777로 변경합니다.

    printf("\n[after *ptr = 7777] \n");
    printf("value of i == %d\n", i);            //i의 값을 출력합니다. 역참조를 통해 7777로 변경했으므로 7777이 출력됩니다.
    printf("value of *ptr == %d\n", *ptr);      //포인터 변수 ptr이 갖고 있는 주소값을 통해 역참조합니다. i가 갖고 있는 값인 7777이 출력됩니다.
    printf("value of **dptr == %d\n", **dptr);  //이중포인터 변수 dptr이 갖고 있는 주소값을 통해 역참조를 두번 합니다. dptr->ptr->i이므로 i의 값이 출력됩니다.

    return 0;

}