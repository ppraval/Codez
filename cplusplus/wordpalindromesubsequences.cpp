#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while(i <= j)
    {
        if(s[i] != s[j])
            return false;
        i++; j--;
    }
    return 1;
}

void sub(vector<string> v, string s, int i, int n, vector<string> &ans)
{
    if(i == n)
    {
        ans.push_back(s);
        return;
    }
    sub(v, s + v[i], i + 1, n, ans);
    sub(v, s, i + 1, n, ans);
}

int main()
{
    vector<string> v = {"ab", "ba", "xyx", "de"};
    vector<string> ans;
    string s = "";
    int n = v.size();
    sub(v,s,0,n,ans);
    int max_len = INT_MIN;
    for(auto x : ans)
    {
        cout << x << endl;
        if(isPalindrome(x))
        {
            cout << endl;
            int len = x.length();
            cout << x << "-" << len << endl;
            max_len = max(max_len, len);
        }
    }
    cout << max_len;
    return 0;
}