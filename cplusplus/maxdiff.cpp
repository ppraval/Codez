#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     int num = 9;
//     int count = 1;
//     while(num /= 10) {
//         count++;
//     }
//     num = 8;
//     for(int i = 0; i < count - 1; i++)
//     {
//         num *= 10;
//         num += 8;
//     }
//     cout << num << endl;
//     return 0;
// }

int main()
{
    int num = 12345;
    string s = to_string(num);
    string a = s, b = s;
    for (char c : s) 
    {
        if (c != '9') 
        {
            replace(a.begin(), a.end(), c, '9');
            break;
        }
    }
    cout << a << endl;
    if (s[0] != '1') 
    {
        replace(b.begin(), b.end(), s[0], '1');
        cout << b << endl;
    } 
    else 
    {
        for (int i = 1; i < s.size(); i++) 
        {
            if (s[i] != '0' && s[i] != '1') 
            {
                replace(b.begin(), b.end(), s[i], '0');
                break;
            }
        }
        cout << b << endl;
    }
    return stoi(a) - stoi(b);
}