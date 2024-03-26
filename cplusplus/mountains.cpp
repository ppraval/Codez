#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {0, 1, 0};
    int mid = 0;
    int first = 0;
    int last = arr.size() - 1;
    while (first <= last) 
    {
        mid = first + (last - first) / 2;
        if (mid == 0 || mid == arr.size() - 1) 
        {
            cout << mid << endl;
            return mid;
        }

        if (arr[mid] < arr[mid + 1]) 
        {
            first = mid;
        }
        else if (arr[mid - 1] > arr[mid]) 
        {
            last = mid;
        }
        else 
        {
            cout << mid << endl;
            return mid;
        }
    }
    return -1;
}