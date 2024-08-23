#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 5;
    vector<string> ans(n);
    for(int i = 0; i < n; i++)
    {
        string temp = "";
        for(int j = 0; j < n; j++)
        {
            if(i == 0 || i == n - 1)
            {
                // cout << "*";
                temp += "*";
            }
            else
            {
                if(j == 0 || j == n - 1)
                {
                    // cout << "*";
                    temp += "*";
                }
                else
                {
                    // cout << " ";
                    temp += " ";
                }
            }
        }
        ans[i] = temp;
        // ans.push_back(temp);
        // cout << endl;
    }
    for(auto x : ans)
    {
        cout << x << endl;
    }
    return 0;
}