#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    string s;
    cin >> n >> t;
    cin >> s;
    while(t > 0)
    {
        for(int i = 0; i + 1 < n; i++)
        {
            if(s[i] == 'B' && s[i + 1] == 'G')
            {
                s[i] = 'G';
                s[i + 1] = 'B';
                i++;
            }
        }
        t--;
    }
    cout << s << endl;
}