/*
학번: 202511859
이름: 최정현
프로그램명: assignment05
날짜: 25.10.11
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

void assignment05();
void input_array(int* first, int* cd);
void arith_seq(const int* first, const int* cd, int* arr);
void print_array(int* arr);

int main()
{
	assignment05();

	return 0;
}

void assignment05()
{
	int arr[MAX] = { 0 };
	int first = 0, cd = 0;

	input_array(&first, &cd);

	arith_seq(&first, &cd, arr);

	print_array(arr);

	return;
}

void input_array(int* first, int* cd)
{

	printf("?¹ ¹ø?° ?×? ");
	scanf("%d", first);
	printf("°ø?÷? ");
	scanf("%d", cd);

	return;
}

void arith_seq(const int* first, const int* cd, int* arr)
{
	arr[0] = *first;
	for (int i = 1; i < MAX; i++)
	{
		arr[i] = arr[i - 1] + *cd;
	}

	return;
}

void print_array(int* arr)
{
	printf("???÷¼?¿­: ");
	for (int i = 0; i < MAX; i++)
	{
		printf("%d ", arr[i]);
	}

	return;
}