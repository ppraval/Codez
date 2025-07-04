#include<bits/stdc++.h>
using namespace std;

int n;
set<string> st;
int dp[2001];
int mod = 1e9+7;
void rec(int i, string temp, string &s)
{
    if(i == n){
        if(temp.size())
            st.insert(temp);
        return;
    }

    rec(i+1, temp+s[i], s);
    rec(i+1, temp, s);
}

int main()
{
    string s = "abc";
    n = s.size();
    rec(0, "", s);
    for(auto it: st)
        cout << it << endl;
    return st.size();
}