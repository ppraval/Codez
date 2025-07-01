#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aaaa";
    // s = "abcd";
    unordered_set<char> s_set(s.begin(), s.end());
    int ans = s.size() - s_set.size() + 1;
    if(ans == 0)
    {
        cout << 1 << endl;
        return 1;
    }
    cout << ans; 
    return ans;
}