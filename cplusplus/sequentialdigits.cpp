#include<bits/stdc++.h>
using namespace std;

int main()
{
    int high = 300, low = 100;
    vector<int> ans;
    for(int i = 1; i <= 9; i++) 
    {
        int num = i;
        int next_digit = i + 1;
        while (num <= high && next_digit <= 9) 
        {
            num = num * 10 + next_digit;
            if (low <= num && num <= high) 
                ans.push_back(num);
            next_digit++;
        }
    }
    sort(ans.begin(), ans.end());
    for(int x : ans)
        cout << x << " ";
    return 0;
}