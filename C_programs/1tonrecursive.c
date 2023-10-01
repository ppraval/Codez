#include<stdio.h>

int printn(int n, int m)
{
    
    if (n == m)
    {   
        printf("%d", m);
        return 1;
    }
    else 
    {
        printf("%d ", n);
    }
    return printn(n + 1, m);
}


int main()
{
    int n;
    scanf("%d",  &n);
    printn(1, n);
    return 0;
}