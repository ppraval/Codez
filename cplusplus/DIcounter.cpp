#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "III";
    int n = s.length();
    vector<int> arr;
    int i = 0, d = n;
    for(int j = 0; j <= n; j++)
    {
        if(s[j] == 'I')
            arr.push_back(i++);
        else
            arr.push_back(d--);
    }
    for(int i : arr)
        cout << i << " ";
    return 0;
}