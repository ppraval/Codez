#include<bits/stdc++.h>
using namespace std;

int main()
{
    // vector<vector<int>> v = {{1,2},{2,3},{3,4}};
    vector<vector<int>> v = {{1,2},{1,2},{3,3},{1,5},{1,5}};
    int n = v.size();
    sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0]; 
    });

    int max_day = v[n - 1][1];

    priority_queue<int, vector<int>, greater<int>> pq;
    int ans = 0;
    for(int i = 0, j = 0; i <= max_day; i++)
    {
        cout << "i = " << i << endl;
        while(j < n && v[j][0] <= i)
        {
            cout << v[j][0] << " <= " << i << endl;
            pq.push(v[j][1]);
            cout << "Pushing" << pq.top() << endl;
            j++;
        }
        while(!pq.empty() && pq.top() < i)
        {
            cout << pq.top() << " is less than " << i << endl;
            pq.pop(); 
        }
        if(!pq.empty())
        {
            cout << "we are incrementing ans" << endl;
            pq.pop(); 
            ans++; 
        }
        cout << endl;
    }
    cout << "ans = " << ans << endl;
    return ans;
}