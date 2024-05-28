#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcd";
    string t = "bcdf";
    int max_cost = 3;
    int max_len = 0;
    int n = s.length();
    int i = 0;
    int curr_cost = 0;
    for(int j = 0; j < n; j++)
    {
        curr_cost += abs(s[j] - t[j]);
        while(curr_cost > max_cost)
        {
            curr_cost -= abs(s[i] - t[i]);
            i++;
        }
        max_len = max(max_len, j - i + 1);
    }
    cout << max_len << endl;
    return max_len;
}