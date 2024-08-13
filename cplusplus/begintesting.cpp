#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr(1);
    arr[0] = 1;
    cout << *(arr.begin()) << endl;
    cout << *(begin(arr)) << endl;
    return 0;
}