#include<bits/stdc++.h>
using namespace std;

int main()
{
    int days = 10;
    vector<vector<int>> m = {{5,7}, {1,3}, {9,10}};
    int count = 0;
    vector<int> day(days + 2, 0);
    for(int i = 0; i < m.size(); i++)
    {
        day[m[i][0]]++;
        day[m[i][1] + 1]--;
    }
    int curr = 0;
    for(int i = 1; i <= days; i++)
    {
        curr += day[i];
        if(curr == 0)
            count++;
    }
    cout << count << endl;
    return count;  
}