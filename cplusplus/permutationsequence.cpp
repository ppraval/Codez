#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 3;
    int k = 3;
    vector<int> arr;
    for(int i = 1; i <= n; i++)
        arr.push_back(i);
    while(k--)
    {
        next_permutation(arr.begin(), arr.end());
    }
    string s = "";
    for(int i : arr)
    {
        s += i + '0';
    }
    cout << s;
    return 0;
}