#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> b = {3,1,1};
    vector<int> r = {2,3,4};
    int c = 2;
    int n = b.size();
    vector<int> ans;
    ans.push_back(0);
    bool on_red = false;
    for(int i = 0; i < n; i++)
    {
        if(i==0 && b[i] + c < r[i])
        {
            ans.push_back((long)b[i] + (long)c);
        } 
        else if(on_red)
        {
            if(b[i] + c < r[i])
            {
                ans.push_back((long)b[i] + (long)c  + ans.back());
                on_red = true;
            }
            else
            {
                ans.push_back(r[i] + ans.back());
            }
        }
        else
        {
            if(b[i] < r[i])
            {
                ans.push_back((long)b[i] + ans.back());
            }
            else
            {
                ans.push_back(r[i] + ans.back());
                on_red = true;
            }
        }
    }
    for(int i : ans)
        cout << i << " ";
    return 0;
}