#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> dic = {"a","b","c"};
    string s = "aadsfasf absbs bbab cadsfafs";
    vector<string> temp;
    stringstream ss(s);
    string word;
    while(ss >> word)
    {
        bool flag = 0;
        for(auto s1 : dic)
        {
            if(word.find(s1) != string::npos)
            {
                temp.push_back(s1);
                flag = 1;
                break;
            }
        }
        if(flag)
            continue;
        else
        {
            temp.push_back(word);
        }
    }
    string ans = "";
    for(int i = 0; i < temp.size(); i++)
    {
        ans += temp[i];
        if(i != temp.size() - 1)
            ans += " ";
    }
    cout << ans;
    return 0;
}