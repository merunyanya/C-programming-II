/*
학번: 202511859
이름: 최정현
프로그램명:Assignment03 
*/


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>  

void assignment0903()
{
    char str[100];


    printf("문자열? ");
    fgets(str, sizeof(str), stdin);


    str[strcspn(str, "\n")] = '\0';


    printf("변환 후: ");
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (islower(str[i]))
        {

            printf("%c", toupper(str[i]));
        }
        else if (isupper(str[i]))
        {

            printf("%c", tolower(str[i]));
        }
        else
        {

            printf("%c", str[i]);
        }
    }
    printf("\n");
}

int main()
{
    assignment0903();
    return 0;
}