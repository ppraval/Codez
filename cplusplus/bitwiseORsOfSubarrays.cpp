#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {1, 1, 2};
    unordered_set<int> res;
    unordered_set<int> cur;

    for (int num : arr) 
    {
        unordered_set<int> next;
        next.insert(num);
        for (int x : cur) 
        {
            next.insert(x | num);
        }
        cur = move(next);
        res.insert(cur.begin(), cur.end());
    }
    cout << "Number of unique bitwise ORs: ";
    cout << res.size() << endl;
    return res.size();
}