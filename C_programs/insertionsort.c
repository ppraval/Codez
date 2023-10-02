 #include <stdio.h>

 int main()
 {
    int arr[10] = {4, 0, 5, 2, 3, 1, 9, 11, 10, 7};
    int key, n = 10;
    for (int j = 1; j < n; j++)
    {  
        key = arr[j];
        int i = j - 1;
        while (i >= 0 && arr[i] >= key)
        {
            arr[i + 1] = arr[i];
            i = i - 1; 
        }
        arr[i + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
 }