#include<bits/stdc++.h>
using namespace std;

int main()
{
    int days = 10;
    vector<vector<int>> m = {{5,7}, {1,3}, {9,10}};
    int count = 0;
    vector<int> day(days, 0);
    cout << "pain" << endl;
    for(int i = 0; i < m.size(); i++)
    {
        int l = m[i][0];
        int r = m[i][1];
        while(l <= r)
        {
            day[l - 1]++;
            l++;
        }
    }
    for(int i : day)
    {
        if(i == 0)
            count++;
    }
    cout << count << endl;
    return count;  
}