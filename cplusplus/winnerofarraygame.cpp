#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;
    unordered_map<int, int> mp;
    for(int i : arr)
    {
        mp[i] = 0;
    }
    queue<int> q;
    for(int i = 1; i < arr.size(); i++)
        q.push(arr[i]);
    int top = arr[0];
    while(1)
    {
        if(top == 7)
            break;
        // cout << top << " " << q.front() << endl;
        if(top <= q.front())
        {
            // int temp = top;
            top = q.front();
            q.push(top);
            mp[top]++;
            q.pop();
        }
        else
        {
            int temp = q.front();
            mp[top]++;
            q.pop();
            q.push(temp);
        }
        if(mp[top] == k)
        {
            // cout << top << endl;
            return top;
        }
    }
    return 0;
}