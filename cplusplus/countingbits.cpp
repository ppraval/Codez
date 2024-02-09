#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2;
    vector<int> ans;
    for(int i = 0; i <= n; i++)
    {
        int sum = 0;
        int num = i;
        while(num != 0)
        {
            sum += num % 2;
            num = num / 2;
        }
        ans.push_back(sum);
    }
    for(int x : ans)
        cout << x << " ";
    return 0;
}