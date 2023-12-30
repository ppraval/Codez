#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "A man, a plan, a canal: Panama";
    string res = "";
    for(char c : s)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            res.push_back(tolower(c));
        }
    }
    string temp = res;
    reverse(res.begin(), res.end());
    if(temp == res)
    {
        return true;
    }
    return false;
}