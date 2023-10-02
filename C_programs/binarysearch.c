#include <stdio.h>

int main()
{
    int arr[6] = {2, 4, 6, 7, 8, 12};
    int x, mid, high, low, key = 6;
    high = 5;
    low = 0;
    while(low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == key)
        {
           printf("found ya ");
           break;
        }
        else if (arr[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}