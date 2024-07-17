#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 4;
    vector<string> v = {"mtv", "ztv", "etv", "ftv"};
    vector<int> in = {3,3};
    int j = 0;
    for(int i : in)
    {
        cout << i << endl;
        if(i == 1)
        {
            j++;
        }
        if(i == 2)
        {
            j--;
        }
        if(i == 3)
        {
            swap(v[j], v[j + 1]);
            j = j + 1;
        }
        if(i == 4)
        {
            swap(v[j], v[j - 1]);
            j = j - 1;
        }
    }
    for(auto x : v)
        cout << x << " ";
    cout << endl;
    return 0;
}