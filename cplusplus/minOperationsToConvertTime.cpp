#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "02:30";
    string t = "04:35";
    int curr = stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
    int target = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
    int diff = target - curr;
    
    vector<int> operations = {60, 15, 5, 1};
    int ans = 0;
    for (int op : operations) {
        if (diff <= 0) break;
        ans += diff / op;
        diff %= op;
    }
    cout << ans << endl;
    return ans;
}