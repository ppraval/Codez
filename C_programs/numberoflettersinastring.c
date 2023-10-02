#include <stdio.h>
#include <string.h>
#define MAX 100;

int main()
{
    char input[MAX];
    char key;
    int count = 0;
    fgets(input, MAX, stdin);
    scanf("%c", &key);
    for(int i = 0; i < MAX; i++)
    {
        if (input[i] ==  key || input[i] == key + 32 || input == key - 32)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;

}   