#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "LVIII";
    char k;
    int res = 0;
    for(int i = 0; i < s.size(); i++)
    {
        k = s[i];
        switch(k)
        {
            case 'I':
            {
                if(s[i + 1] == 'V')
                {
                    res += 4;
                    i++;
                    continue;
                }
                else if(s[i + 1] == 'X')
                {
                    res += 9;
                    i++;
                    continue;
                }
                else
                {
                    res += 1;
                    continue;
                }
            }
            case 'V':
            {
                res += 5;
                continue;
            }
            case 'X':
                if(s[i + 1] == 'L')
                {
                    res += 40;
                    i++;
                    continue;
                }
                else if(s[i + 1] == 'C')
                {
                    res += 90;
                    i++;
                    continue;
                }
                else
                {
                    res += 10;
                    continue;
                }
            case 'L':
            {    
                res += 50;
                continue;
            }
            case 'C':
                if(s[i + 1] == 'D')
                {
                    res += 400;
                    i++;
                    continue;
                }
                else if(s[i + 1] == 'M')
                {
                    res += 900;
                    i++;
                    continue;
                }
                else
                {
                    res += 100;
                    continue;
                }
            case 'D':
            {
                res += 500;
                continue;
            }
            case 'M':
            {
                res += 1000;
                continue;
            }
        }   
    }
    cout << res;
    return 0;
}