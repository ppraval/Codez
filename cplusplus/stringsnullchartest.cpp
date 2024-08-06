#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    sort(strs.begin(), strs.end());
    for(auto x : strs)
        cout << x << " ";
        cout << endl;
    char com;
    string sol = "";
    for (int  i = 0; i <= 200; i++)
    {   com = strs[0][i];
        for(int j = 1; j < strs.size(); j++)
         {
            if(strs[j][i] == '\0')
            {
                cout << sol;
                return 1;
            }
            if(com != strs[j][i])
            {
                cout << sol;
                return 1;
            }
        }
        sol += com;   
    }
    cout << "Go kys" << endl;
    return 0;
}