#include<bits/stdc++.h>
using namespace std;

int main()
{
    //this is why i like her
    int n = 5;
    int l = 3;
    // int l = 1;
    int r = 5;
    vector<int> a = {1,6,5,4,1};
    int res = 0;
    bool flag = 0;
    if(a[0] <= r)
        return 0;
    for(int i = 0; i + 1 < n; i++)
    {
        int diff = a[i + 1] - a[i];
        if(diff >= 0)
        {
            if(diff <= r)
            {
                res++;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        else
        {
            if(diff * -1 <= l)
            {
                res++;
            }
            else
            {
                flag = 1;
                break;
            }
        }
    }
    if(flag)
    {
        cout << 2 * res + 2;
    }
    else
    {
        cout << res + 2;
    }   
    return 0;
}