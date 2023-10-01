#include <stdio.h>
#include <string.h>
#define MAX 100;

int main()
{
    char input[100];
    char key;
    int count = 0, n = MAX;
    fgets(input, n, stdin);
    scanf("%c", &key);
    for(int i = 0; i < n; i++)
    {
        if (input[i] ==  key || input[i] == key + 32 || input[i] == key - 32)
        {
            count++;
        }
    }
    printf("%d", count);
    return 0;

}   