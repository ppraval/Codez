#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> p = {{2,2},{-1,-2},{-4,4},{-3,1},{3,-3}};
    string s = "abdca";
    int points = 0;
    unordered_set<char> set;
    int max_len = 0;
    for(int i = 0; i < p.size(); i++)
    {
        max_len = max(max_len, max(abs(p[i][0]), abs(p[i][0])));
    }
    for(int i = 0; i < p.size(); i++)
    {
        set.clear();
        int x = p[i][0], y = p[i][1];
        int curr_max = 0;
        char ch = s[i];
        for(int len = 0; len <= max_len; len++)
        {
            bool is_square = true;
            set.insert(ch);
            for(int j = 0; j < p.size(); j++)
            {
                if(i != j)
                {
                    int x1 = p[j][0], y1 = p[j][1];
                    char ch1 = s[j];
                    cout << "len = " << len << " | x, y =  " << x << ", " << y << " | x1, y1 = " << x1 << ", " << y1 << endl;
                    if(x1 >= -1 * len && x1 <= len && y1 >= -1 * len && y1 <= len)
                    {
                        if(set.find(ch1) != set.end())
                        {
                            is_square = false;
                            break;
                        }
                        else
                        {
                            set.insert(ch1);
                        }
                    }
                }
            }
            if(is_square)
            {
                curr_max = set.size();
            }
            cout << curr_max << endl;
        }
        points = max(points, curr_max);
    }
    cout << points << endl;
    return points;
}