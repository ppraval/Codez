#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1,9,2,5,7};
    sort(begin(arr), end(arr));
    for(int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
        i++;
    }
    return 0;
}