#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> p = {{16,32},{27,3},{23,-14},{-32,-16},{-3,26},{-14,33}};
    string s = "aaabfc";
    int points = 0;
    unordered_set<char> set;
    int max_len = 0;
    for(int i = 0; i < p.size(); i++)
    {
        max_len = max(max_len, max(abs(p[i][0]), abs(p[i][0])));
    }
    cout << max_len << endl;
    int count = 0, max_count = 0;
    for(int len = 0; len <= max_len; len++)
    {
        cout << endl << endl << len << endl;
        for(int i = 0; i < p.size(); i++)
        {
            int x = p[i][0], y = p[i][1];
            cout << x << ":" << y << endl;
            if(x >= -1 * len && x <= len && y >= -1 * len && y <= len)
            {
                cout << "if the satisfy " << s[i] << endl;
                if(set.find(s[i]) != set.end())
                {
                    cout << s[i] << endl;
                    count = 0;
                    break;
                }
                else
                {
                    set.insert(s[i]);
                    count++;
                }
            }
        }
        max_count = max(max_count, count);
    }
    cout << max_count;
    return 0;
}