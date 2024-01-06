#include<bits/stdc++.h>
using namespace std;

// My answer which is the standard answer but
int main()
{
    string s = "ab-cd";
    stack<char> stack;
    int n = s.length();
    for(int i = 0; i < n; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            stack.push(s[i]);
        }
    }
    for(int i = 0; i < n; i++)
    {
        if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            s[i] = stack.top();
            stack.pop();
        }
    }
    cout << s << endl;
    return 0;
}

// There is a two pointer approach?????????
// int main()
// {
//     string s = "ab-cd";
//     int i=0;
//     int j=s.length()-1;
//     while(i<=j)
//     {
//         if(isalpha(s[i])&&isalpha(s[j]))
//         {
//             swap(s[i],s[j]);
//             i++;
//             j--;
//         }
//         else if(!isalpha(s[i]))
//         {
//             i++;
//         }
//         else
//         {
//             j--;
//         }
//     }
//     cout << s << endl;
//     return 0;
// }