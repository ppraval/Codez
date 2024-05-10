#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 3, 2, 5, 4};
    set<int> s;
    for(int i : arr)
    {
        s.insert(i);
    }
    for(auto i : s)
    {
        cout << i << " ";
    }
    return 0;
}