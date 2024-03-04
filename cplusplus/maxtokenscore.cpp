#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> tokens = {200, 100};
    int power = 150;
    sort(tokens.begin(), tokens.end());
    int s = 0;
    int max_s = 0;
    int l = 0;
    int r = tokens.size() - 1;
    while(l <= r)
    {
        if(power >= tokens[l])
        {
            power -= tokens[l];
            s++;
            l++;
            max_s = max(max_s, s);
        }
        else if(s > 0)
        {
            power += tokens[r];
            s--;
            r--;
        }
        else
        {
            break;
        }
    }
    cout << max_s << endl;
    return max_s;
}