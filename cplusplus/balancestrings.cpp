#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     vector<string> s = {"abc","aabc","bc"};
//     vector<int> a (26, 0);
//     for(int i = 0; i < s.size(); i++)
//     {
//         for(int j = 0; j < s[i].size(); j++)
//         {
//             a[s[i][j] - 'a']++;
//         }
//     }
//     for(int i = 0; i < 26; i++)
//     {   
//         if(a[i] % s.size() != 0)
//         {
//             cout << "false";
//             return false;
//         }
//     }
//     cout << "true";
//     return 0;
// }

// better code

int main()
{
    vector<string> s = {"abc","aabc","bc"};
    string sum = "";
    vector<int> a (26, 0);
    int n = s.size();
    for(int i = 0; i < n; i++)
    {
        sum += s[i];
    }
    for(int i = 0; i < sum.size(); i++)
    {
        a[sum[i] - 'a']++;
    }
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