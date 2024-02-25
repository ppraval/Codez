#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "Hello, my name is John";
    int n = s.length();
    int ans = 0;
    bool flag = 0;

    for(int i = 0; i < n; i++) 
    {
        if(s[i] != ' ' && flag == 1 && i != n - 1) 
            continue;
        if(s[i] == ' ' && flag == 0) 
            continue;
        if(s[i] != ' ' && flag == 0) 
        {
            flag = 1;
        }
        else if(s[i] == ' ' && flag == 1) 
        {
            flag = 0;
            ans++;
        }
        if(i == n - 1 && flag == 1) 
            ans++;
    }
    cout << ans << endl;
    return 0;
}