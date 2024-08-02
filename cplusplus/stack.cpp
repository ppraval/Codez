#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> s;
    vector<int> arr = {1,2,3,4,5};
    for(int i : arr)
    {
        s.push(i);
        cout << s.top() << endl;
        s.pop()
    }
    return 0;
}