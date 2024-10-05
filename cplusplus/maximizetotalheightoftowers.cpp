#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> mh = {2,3,4,3};
    sort(begin(mh), end(mh));
    int sum = 0;
    int last = INT_MAX;
    for(int i = mh.size() - 1; i >= 0; i--)
    {
        if(mh[i] < last)
        {
            last = mh[i];
        }
        else if(last == 0)
        {
            return -1;
        }
        sum += last;
        last--;
    }
    // cout << sum;
    return sum;
}