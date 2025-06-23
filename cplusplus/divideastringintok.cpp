#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s = "abcdefghi";
//     // string s = "abcdefghij";
//     int n = s.size();
//     int k = 3;
//     char fill = 'x';
//     vector<string> res;
//     for(int i = 0; i < n; i++)
//     {
//         string temp = "";
//         for(int j = 0; j < k; j++)
//         {
//             if(i + j >= n)
//                 temp += fill;
//             else
//                 temp += s[i + j];    
//             // cout << temp << endl;   
//         }
//         res.push_back(temp);
//         i += k - 1;
//     }

//     for(auto x : res)
//     {
//         cout << x << endl;
//     }
//     return 0;
// }

int main()
{
    string s = "abcdefghij";
    int k = 3;
    char fill = 'x';
    string temp = "";
    vector<string> res;
    int count = 1;
    for(int i = 0; i < s.length(); i++)
    {
        temp += s[i];
        if(temp.length() == k)
        {
            count++;
            res.push_back(temp);
            temp = "";
        }
    }
    if(s.length() % k)
    {
        if(temp.length() < k)
        {
            int n = temp.length() % k;
            for(int i = 0; i < k - n; i++)
            {
                temp += fill;
            }
        }
        res.push_back(temp);
    }
    for(auto x : res)
    {
        cout << x << endl;
    }
    return 0;   
}