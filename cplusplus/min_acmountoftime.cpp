#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> s = {1,5,2,4};
    vector<int> ma = {5,1,4,2};
    int n = s.size();
    int m = ma.size();
    vector<int> sum (n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        sum[i + 1] = sum[i] + s[i];
    }
    // for(int i : sum)
    //     cout << i << " ";
    // cout << endl;
    int start_time = 0;
    for(int i = 1; i < m; i++)
    {
        int temp_time = 0;
        for(int j = 0; j < n; j++)
        {
            int end_time = start_time + sum[j + 1] * ma[i - 1];
            // cout << "end = " << end_time << endl;
            temp_time = max(temp_time, end_time - sum[j] * ma[i]);
            // cout << "temp = " << temp_time << endl;
            cout << endl;
        }
        cout << endl;
        start_time = temp_time;
    }
    // cout << sum[n] * ma[m - 1];
    cout << "final answer = " <<  start_time + sum[n] * ma[m - 1];
    return 0;
}