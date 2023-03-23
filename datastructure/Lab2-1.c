#include <stdio.h> 


int main()
{
    char charType;
    int integerType;
    float floatType;
    double doubleType; //문자형, 정수형, 실수형, 실수형 double 자료형를 가진 변수를 각각 선언한다.

    printf("\n[----- [최현철] [2022078014] -----]\n"); //소스파일에 성명, 학번이 실행시 출력되도록 소스를 수정한다.

    printf("Size of char: %ld byte\n",sizeof(charType)); //sizeof연산자를 이용하여 문자형 변수의 바이트 크기를 출력한다.
    printf("Size of int: %ld bytes\n",sizeof(integerType)); //sizeof연산자를 이용하여 정수형 변수의 바이트 크기를 출력한다.
    printf("Size of float: %ld bytes\n",sizeof(floatType)); //sizeo연산자를 이용하여 플로트형(실수형) 변수의 바이트 크기를 출력한다.
    printf("Size of double: %ld bytes\n",sizeof(doubleType)); //sizeo연산자를 이용하여 더블형(실수형) 변수의 바이트 크기를 출력한다.
    printf("-----------------------------------------\n");
    printf("Size of char: %ld byte\n",sizeof(char)); //문자형 자료형의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("Size of int: %ld bytes\n",sizeof(int)); //정수형 자료형의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("Size of float: %ld bytes\n",sizeof(float)); //실수형 자료형(float타입)의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("Size of double: %ld bytes\n",sizeof(double)); //실수형 자료형(double타입)의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("-----------------------------------------\n"); 
    printf("Size of char*: %ld byte\n",sizeof(char*)); //문자형 포인터 자료형의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("Size of int*: %ld bytes\n",sizeof(int*)); //정수형 포인터 자료형의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("Size of float*: %ld bytes\n",sizeof(float*)); //실수형 포인터 자료형의 바이트 크기를 sizeof연산자를 이용하여 출력한다.
    printf("Size of double*: %ld bytes\n",sizeof(double*)); //실수형 포인터 자료형의 바이트 크기를 sizeof연산자를 이용하여 출력한다.


return 0; 

}