#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Let's take LeetCode contest";
    string ans = "";
    stringstream ss(s);
    string temp;
    while(ss >> temp)
    {
        reverse(temp.begin(), temp.end());
        ans += temp + " ";
    }
    ans.pop_back();
    cout << ans << endl;
    return 0;
}