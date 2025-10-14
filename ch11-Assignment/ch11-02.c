/*
학번: 202511859
이름 : 최정현
프로그램명: assignment02
날짜: 25.10.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void assignment02();
int sum_of_digits(int n);
void print_array(int n);

int main()
{
	assignment02();

	return 0;
}

void assignment02()
{

	int n = 0;

	while (1)
	{
		printf("정수? ");
		scanf("%d", &n);

		int result = sum_of_digits(n);
		print_array(result);

	}

	return;
}

int sum_of_digits(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if(n < 10)
	{
		return n;
	}
	else
	{
		return n%10 + sum_of_digits(n / 10);
	}

	return 0;
}

void print_array(int n)
{
	printf("sum of digits: %d\n", n);

	return;
}
