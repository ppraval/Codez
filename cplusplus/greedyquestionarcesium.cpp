#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = ".x.xx.x.x.x";
    int cred = 6;
    // priority_queue<int> q;
    vector<int> v;
    int count = 0;
    for(int i = 0; i < s.length(); i++)
    {
        // cout << s[i];
        if(s[i] == 'x')
        {
            count++;
        }
        else if(count > 0)
        {
            v.push_back(count + 1);
            count = 0;
        }
        // cout << "~" << count << endl;
    }
    if(count > 0)
        v.push_back(++count);
    int n = v.size();
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i++)
    {
        cred -= v[i];
    }
    if(cred > 0)
        cout << "Yay" << endl;
    else
        cout << "Nay" << endl;
    return 0;
}