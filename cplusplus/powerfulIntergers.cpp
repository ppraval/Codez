#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 2;
    int y = 3;
    int bound = 10;
    unordered_set<int> res;
    for(int i = 1; i <= bound; i *= x)
    {
        for(int j = 1; i + j <= bound; j *= y)
        {
            res.insert(i + j);
            if(y == 1)
                break;
        }
        if(x == 1)
            break;
    }
    vector<int> ans = vector<int>(res.begin(), res.end());
    for(int i : ans)
    {
        cout << i << " ";
    }
    return 0;
}