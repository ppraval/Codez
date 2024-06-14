#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3,2,3};
    int val = a[0];
    int count = 0;
    for(int i = 0; i < a.size(); i++)
    {
        cout << count << endl;  
        cout << i << " " << val << endl;
        if(count == 0)
        {
            val = a[i];
        }
        if(val == a[i])
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    cout << val;
    return val;
}