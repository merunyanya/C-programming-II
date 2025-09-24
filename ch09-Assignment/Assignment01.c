/*
학번: 202511859
이름: 최정현
프로그램명:Assignment01 (한 줄의 문자열을 입력받아서 공백 문자의 개수를 세는 프로그램 작성)
날짜: 25.09.24
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void assignment01();

int main()
{
	assignment01();

	return 0;
}

void assignment01()
{
	char str[64] = { 0 };
	printf("문자열? ");
	scanf(" %[^\n]", str);

	int n = 0;

	for (int i = 0; str[i] != '\0'; i++)
	{
		switch (str[i])
		{
		case ' ':
		case '\t':
		case '\f':
		case '\r':
		case '\v':
			n++;
			break;
		default:
			break;
		}
	}
	printf("공백 문자의 개수: %d\n", n);
	return;
}