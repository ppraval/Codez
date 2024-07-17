#include<bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int a = 3;
    int b = 1;
    int c = 0;
    int n = a + b + c;
    string s = "";
    vector<string> ans;
    while(a--)
        s += 'a';
    while(b--)
        s += 'b';
    while(c--)
        s += 'c';
    n = fact(n);
    while(n--)
    {
        next_permutation(s.begin(), s.end());
        int max_count = 1;
        int count = 1;
        for(int i = 0; i + 1 < s.size(); i++)
        {
            if(s[i] == s[i + 1])
            {
                count++;
            }
            else
            {
                count = 1;
            }
            max_count = max(max_count, count);
        }
        if(max_count < 3)
        {
            ans.push_back(s);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
    return 0;
}