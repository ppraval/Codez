#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1,2,3};
    next_permutation(begin(v), end(v));
    for(int i : v)
        cout << i << " ";
    return 0;
}