/*
학번: 202511859
이름: 최정현
프로그램명:Assignment07
날짜: 25.09.24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void assignment07();
int fill_array(int arr[], int size, int value);

int main()
{
    assignment07();
    return 0;
}


int fill_array(int arr[], int size, int value)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = value;
    }
}


void assignment07()
{
    int num[20];

    fill_array(num, 20, 5);

    printf("배열 내용: ");
    for (int i = 0; i < 20; i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return;
}