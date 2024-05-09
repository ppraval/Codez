#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> h = {1,2,3};
    int k = 2;
    int sum = 0;
    sort(h.begin(), h.end(), greater<int>());
    for(int i = 0; i < k; i++)
    {
        sum += max(h[i] - i, 0);
    }
    cout << sum << endl;
    return sum;
}