#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> s = {"ab","a"};
    vector<int> a (26, 0);
    for(int i = 0; i < s.size(); i++)
    {
        for(int j = 0; j < s[i].size(); j++)
        {
            a[s[i][j] - 'a']++;
        }
    }
    int new_flag = 0, flag = 0;
    for(int i = 0; i < 26; i++)
    {   
        if(a[i] % s.size() != 0)
        {
            cout << "false";
            return false;
        }
    }
    cout << "true";
    return 0;
}