#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {4,5,7,1,3,2,9,10};
    int k = 3;
    sort(begin(v), begin(v) + k);
    sort(begin(v) + k, end(v), greater<int>{});
    for(int i : v)
        cout << i << " ";
    return 0;
}