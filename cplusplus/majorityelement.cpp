#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {3, 2, 3};
    int element = a[0];
    int count = 0;
    for(int i = 0; i < a.size(); i++)
    {   
        if(count == 0)
        {
            element = a[i];
        }
        if(element == a[i])
            count++;
        else
            count--;
    }
    cout << element;
    return 0;
}