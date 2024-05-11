#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "214010";
    vector<int> ch = {6,7,9,7,4,0,3,4,4,7};
    int i = 0;
    for(i; i < s.length(); i++)
    {
        if(ch[s[i] - '0'] > s[i] - '0')
        {
            break;
        }
    }
    for(; i < s.length(); i++)
    {
        cout << ch[s[i] - '0'] << " : " << s[i] - '0' << endl;
        if(ch[s[i] - '0'] >= s[i] - '0')
        {
            s[i] = ch[s[i] - '0'] + '0';
        }
        else
        {
            cout << " pain " << endl;
            break;
        }
        cout << s << endl;
    }
    cout << s << endl;
    return 0;
}