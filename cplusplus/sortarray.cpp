#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> heights = {180,165,170};
    vector<string> names = {"Mary","John","Emma"};
    unordered_map<int, string> mp;
    int n = heights.size();
    for(int i = 0; i < n; i++)
    {
        mp[heights[i]] = names[i];
    }
    sort(heights.begin(), heights.end(), greater<int>());
    for(int i = 0; i < n; i++)
    {
        names[i] = mp[heights[i]];
    }
    for(int i = 0; i < n; i++)
    {
        cout << names[i] << " ";
    }
    return 0;
}