#include<bits/stdc++.h> 
using namespace std;

int main()
{
    string num = "1432219";
    int k = 3;
    string ans;
    vector<char> s;
    for(int i = 0; i < num.size(); i++)
    {
        while(!s.empty() && s.back() > num[i] && k > 0)
        {   
            s.pop_back();
            k--;
        }    
        s.push_back(num[i]);
    }
    while(!s.empty() && k-- > 0)
    {
        s.pop_back();
    }
    for(char c : s)
    {
        if(c == '0' && ans.empty())
        {
            continue;
        }
        ans += c;
    }
    cout << ans << endl;
    return 0;
}