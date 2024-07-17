#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
mt19937 rnd(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::system_clock::now().time_since_epoch()).count());
int randint(int L, int R) {
    uniform_int_distribution<int> dist(L, R);
    return dist(rnd);
}
typedef long long ll;
vector<string>ans;
void solve(int i,string &s)
{
    if(i==5)
    {
        bool now=true;
        for(int i=0;i<2;i++)
        {
            if(s[i] != s[5-i-1])
            {
                now=false;
                break;
            }
        }
        if(now)
        {
            ans.push_back(s);
        }
        return;
    }
    s.push_back('0');
    solve(i+1,(s));
    s.pop_back();
    s.push_back('1');
    solve(i+1,s);
    s.pop_back();
}
int main()
{
    //1.dont get stuck on one approach
    //2.think and code
    fastio;
    string s;cin>>s;
    string now="";
    solve(0,now);
    ll fans=0;
    int mod=1000000007;
    int n=s.length();
    for(auto j:ans){
        vector<vector<ll>>dp(n,vector<ll>(6,0));
    if(s[0]==j[0])
    {
        dp[0][0]=2;
        dp[0][1]=1;
    }
    else
        dp[0][0]=1;
    for(int i=1;i<n;i++)
    {
        for(int k=0;k<5;k++)
        {
            if(j[k]==s[i])
            {
                dp[i][k+1]=(dp[i][k+1]+dp[i-1][k])%mod;
                dp[i][k]=(dp[i][k]+dp[i-1][k])%mod;
            }
            else
            {
                dp[i][k]=(dp[i][k]+dp[i-1][k])%mod;
            }
        }
    }
    fans=(fans+dp[n-1][5])%mod;
    }
    cout<<fans<<endl;
    return 0;
}