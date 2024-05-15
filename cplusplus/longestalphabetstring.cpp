#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abacaba";
    int ans = INT_MIN;
    int count = 1;
    for(int i = 0; i < s.length(); i++)
    {
        if((s[i + 1] - s[i]) == 1)
        {
            count++;
        }
        else
        {
            ans = max(ans, count);
            count = 1;
        }
    }
    cout << ans << endl;
    return ans;
}