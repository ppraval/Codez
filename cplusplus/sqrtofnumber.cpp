#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 2147395599;
    int low = 0;
    int high = x;
    int mid;
    while(low <= high)
    {
        mid = (low + high) / 2;
        if(mid * mid == x)
        {
            cout << mid << endl;
            return mid;
        }
        else if(mid * mid < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << high << endl;
    return 0;
}