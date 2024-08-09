#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "malayalam";
    string t = s;
    reverse(t.begin(), t.end());
    int count = 0;
    for(int i = 0; i < s.size(); i++)
    {
        cout << s[i] << " " << t[i] << endl;
        if(s[i] == t[i])
        {
            count++;
        }
    }
    cout << count << endl;
    return 0;
}