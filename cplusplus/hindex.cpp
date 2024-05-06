#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {3,0,6,1,5};
    sort(v.begin(), v.end());
    int n = v.size();
    int m = n;
    for(int i = 0; i < m; i++)
    {
        if(v[i] >= n)
        {
            cout << n << endl;
            return n;
        }
        else 
        {
            if(v[i] != 0 && n == 1)
            {
                cout << 1 << endl;
                return 1;
            }
            n--;
        }
    }
    cout << n << endl;
    return n;
}