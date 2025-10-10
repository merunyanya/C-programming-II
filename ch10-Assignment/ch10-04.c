/*
학번: 202511859
이름 : 최정현
프로그램명: assignment1004
날짜: 25.10.11
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct
{
	int year[48];
	int mon[48];
	int da[48];

}DATE;

void assignment1004();
void array_date(DATE date);
int print_date();

int main()
{
	assignment1004();
	
	return 0;
}

void assignment1004()
{
	DATE date_chack = { 0 };

	for (int i = 0; i < 48; i++)
	{

	}
	return;
}

int print_date(DATE date)
{
	printf("\n연?");
	scanf("%d", date.year);

	printf("\n월?");
	scanf("%d", date.mon);

	printf("\n일?");
	scanf("%d", date.da);


}