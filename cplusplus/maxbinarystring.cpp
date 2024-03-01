#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1010";
    int count_1 = 0, count_0 = 0;
    for(auto x : s)
    {
        if(x == '1')
            count_1++;
        else
            count_0++;
    }

    string ans = string(count_1 - 1, '1') + string(count_0, '0') + '1';
    cout << ans << endl;
    return 0;
}