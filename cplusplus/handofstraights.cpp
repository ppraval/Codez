#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> hand = {1,2,3,6,2,3,4,7,8};
    int k = 3;
    unordered_map<int, int> mp;
    for(int i : hand)
        mp[i]++;
    vector<int> sorted_arr;
    for(auto x : mp)
        sorted_arr.push_back(x.first);
    sort(sorted_arr.begin(), sorted_arr.end());
    for(int i : sorted_arr)
        cout << i << " ";
    cout << endl;
    for(int i : sorted_arr)
    {
        if(mp[i] > 0)
        {
            int count = mp[i];
            for(int j = i; j < i + k; j++)
            {
                if(mp[j] < count)
                {
                    cout << false;
                    return false;
                }
                mp[j] -= count;
            }
        }
    }
    cout << true;
    return true;
}