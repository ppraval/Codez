#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> gain = {-4,-3,-2,-1,4,3,2};
    vector<int> alt;
    alt.push_back(0);
    int max_elem = alt[0];
    for(int i = 0; i < gain.size(); i++)
    {
        if(i == 0)
        {
            alt.push_back(gain[i]);
            max_elem = max(max_elem, alt[i + 1]);
        }
        else
        {
            alt.push_back(gain[i] + alt[i]);
            max_elem = max(max_elem, alt[i + 1]);
        }
    }
    cout << max_elem << endl;
    return 0;
}