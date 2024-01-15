#include<stdio.h>

int main()
{
    char *arr;
    char *time;
    scanf("%[^\n]\n", arr);
    printf(".");
    scanf("%[^\n]", time);
    printf("The arr has = ");
    puts(arr);
    printf("The time is = ");
    puts(time);
    return 0;
}