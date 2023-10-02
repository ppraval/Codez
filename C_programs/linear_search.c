#include <stdio.h>

int main()
{
    int arr[10] = {3, 4, 5, 6, 7, 1, 78, 29, 73};
    int key = 0;
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == key)
        {
            printf("found ya");
        }
    }
    return 1;
}