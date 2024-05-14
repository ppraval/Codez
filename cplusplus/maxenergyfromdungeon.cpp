#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> energy = {5,2,-10,-5,1};
    int k = 3;
    int n = energy.size();
    vector<int> dp(n, 0);
    int max_energy = INT_MIN;
    for (int i = n - 1; i >= n - k; i--) 
    {
        dp[i] = energy[i];
        max_energy = max(max_energy, dp[i]);
    }
    cout << max_energy << endl;
    for (int i = n - k - 1; i >= 0; i--) 
    {
        dp[i] = energy[i] + dp[i + k];
        max_energy = max(max_energy, dp[i]);
    }
    cout << max_energy;
    return max_energy;;
}