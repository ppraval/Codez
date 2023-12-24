#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "10010100";
    int n = s.length();
    string res1 = "";
    string res2 = "";
    char ch1 = '0';
    char ch2 = '1';
    for(int i = 0; i < n; i++)
    {
        if(s[0] == '1')
        {
            ch1 = '1';
            ch2 = '0';
        }
        if(i % 2 == 0)
        {
            res1.push_back(ch1);
            res2.push_back(ch2);
        }
        else
        {
            res1.push_back(ch2);
            res2.push_back(ch1);
        }
    }
    int count1 = 0, count2 = 0;
    for(int i = 0; i < n; i++)
    {
        if(res1[i] != s[i])
            count1++;
        if(res2[i] != s[i])
            count2++;
    }
    return min(count1, count2);
}

// better answer
// int main()
// {
//     string s = "0100";
//     int cost10 = 0;
//     for(int i=0; i < s.length(); i++) 
//     {
//         if(s[i]-'0'==i%2) 
//         {
//             cost10++;
//         }
//     }
//     int cost01 = s.length() - cost10;
//     return min(cost01, cost10);
// }