/*
�й�: 202511859
�̸�: ������
���α׷���:Assignment01 (�� ���� ���ڿ��� �Է¹޾Ƽ� ���� ������ ������ ���� ���α׷� �ۼ�)
��¥: 25.09.24
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
	printf("���ڿ�? ");
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
	printf("���� ������ ����: %d\n", n);
	return;
}