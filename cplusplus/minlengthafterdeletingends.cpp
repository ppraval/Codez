#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s = "aaaaaaaaa";
//     int i = 0, j = s.length() - 1;
//     while(i <= j)
//     {
//         if(s[i] != s[j])
//             break;
//         if(s[i + 1] == s[i])
//             i++;
//         if(s[j - 1] == s[j])
//             j--;
//         if(s[i] == s[j] && s[i + 1] != s[i] && s[j - 1] != s[j])
//         {
//             i++, j--;
//             cout << "i = " << i << ", j = " << j << endl;
//         }
//     }
//     if(j - i < 0)
//     {
//         cout << 0 << endl;
//         return 0;
//     }
//     else
//         cout << j - i + 1 << endl;
//     return j - i;
// }

int main()
{
    string s = "ca";
    int l = 0;
    int r = s.size() - 1;
    while (l < r && s[l] == s[r]) 
    {
        char ch = s[l];
        while (l <= r && s[l] == ch) 
        {
            l++;
        }
        while (r >= l && s[r] == ch) 
        {
            r--;
        }
    }
    cout << r - l + 1 << endl;
    return r - l + 1;
}
