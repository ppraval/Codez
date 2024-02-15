#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    priority_queue<int> q;
    for(int i : nums)
    {
        q.push(i);
    }
    for(int i = 0; i < k - 1; i++)
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl << "The " << k << "th largest element is = ";
    cout << q.top() << endl;
    return 0;
}