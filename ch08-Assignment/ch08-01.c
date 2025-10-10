/*
학번: 202511859
이름: 최정현
프로그램명:Assignment01
날짜: 25.09.24
*/

#include <stdio.h>


void assignment01();

int main()
{
    assignment01();
    return 0;
}

void assignment01()
{
    double x[3] = { 1.1, 2.2, 3.3 };


    for (int i = 0; i < 3; i++)
    {
        printf("x[%d]의 주소: %p\n", i, (x + i));
    }
}