/*
학번: 202511859
이름 : 최정현
프로그램명: assignment01
날짜: 25.10.15
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void assignment01();
int print_array(int n);
int count_digits(int num);


int main()
{
	assignment01();

	return 0;
}

void assignment01()
{

	int num = 0;
	
	while (1)
	{
		printf("정수? ");
		scanf("%d", &num);

		int result = count_digits(num);

		print_array(result);

	}


	return;
}

int count_digits(int num)
{
	if (num == 0)
	{
		return 1;
	}
	else if (num < 10)
	{
		return 1;
	}
	else
	{
		return 1 + count_digits(num / 10);
	}

	return 0;
}

int print_array(int n)
{
	printf("count of digits: %d\n", n);

	return 0;
}

