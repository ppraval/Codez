#include <stdio.h>

int main()
{
    int arr[10] = {1, 2, 342, 5, 31, 324, 3 ,2435, 46};
    int n = 10, min, pos;
    for (int i = 0; i < n - 1; i++)
    {
        min = arr[i];
        pos = i;
        for (int j = i + 1; j < n; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                pos = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}