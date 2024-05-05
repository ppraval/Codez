#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Ya$";
    int flag = 0, another_flag = 0, char_flag = 0;
    unordered_map<char, int> mp;
    if(s.length() < 3)
        return false;
    for(auto x : s)
    {
        if(!isdigit(x) && !isalpha(x))
        {
            char_flag = 1;
        }
        else if((x > 'a' && x < 'z' || x < 'Z' && x > 'A') && (x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u') && (x != 'A' && x != 'E' && x != 'I' && x != 'O' && x != 'U'))
        {
            another_flag = 1;
        }
        else if((x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') || (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U'))
        {
            flag = 1;
        }
    }
    if(flag && another_flag && char_flag != 1)
    cout << true;
    else
    cout << false;
        return true;
    return false;
}

