#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s = "anagram";
//     string t = "nagaram";
//     std:: sort(s.begin(), s.end());
//     std:: sort(t.begin(), t.end());
//     if(s == t)
//     {
//         cout << "True";
//         return 0;
//     }
//     else
//     {
//         cout << "False";
//         return 0;
//     }
//     return 0;
// }

// another methord

int main()
{
    string s = "anagram";
    string t = "nagaram";

    int arr1[26] = {0};
    if(s.size() != t.size())
    {
        return false;
    }       
    for(int i = 0; i < s.size(); i++)
    {
        arr1[s[i] - 'a']++;
        arr1[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(arr1[i] == 0)
        {
            cout << "false";
            return false;
        }
    }
    cout << "true";
    return 0;
}