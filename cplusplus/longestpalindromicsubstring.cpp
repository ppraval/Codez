#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "ccc";
    int n = s.size();
    string max_str;
    for(int i = 0; i < n; i++)
    {
        string curr_str_odd;
        string curr_str_even;
        int l = i, r = i;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            curr_str_odd = s.substr(l, r - l + 1);
            l--;
            r++;
        }
        l = i, r = i + 1;
        while(l >= 0 && r < n && s[l] == s[r])
        {
            curr_str_even = s.substr(l, r - l + 1);
            l--;
            r++;
        }
        if(curr_str_even.length() >= max_str.length())
        {
            max_str = curr_str_even;
        }
        if(curr_str_odd.length() >= max_str.length())
        {
            max_str = curr_str_odd;
        }
    }
    cout << max_str << endl;
    return 0;
}