#include<bits/stdc++.h>
using namespace std;

int main()
{
    int left = 5;
    int right = 7;
    int count = 0;
    while (left != right) 
    {
        left >>= 1;
        cout << "Left = " << left << endl;
        right >>= 1;
        cout << "right = " << right << endl;
        count++;
    }
    cout << (left << count) << endl;
    return 0;
}