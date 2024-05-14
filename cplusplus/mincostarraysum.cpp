#include<bits/stdc++.h>
using namespace std;

int calculateScore(vector<int> perm, vector<int> nums) 
{
    int score = 0;
    for (size_t i = 0; i < perm.size(); ++i) 
    {
        score += abs(perm[i] - nums[perm[(i + 1) % perm.size()]]);
    }
    return score;
}

int main()
{
    vector<int> nums = {1,0,2};
    vector<int> perm(nums.size());
    iota(perm.begin(), perm.end(), 0); 
    vector<int> min_perm = perm;
    int min_score = INT_MAX;

    do 
    {
        int current_score = calculateScore(perm, nums);
        if (current_score < min_score || (current_score == min_score && perm < min_perm)) 
        {
            min_score = current_score;
            min_perm = perm;
        }
    } 
    while (next_permutation(perm.begin(), perm.end()));

    for(int i : min_perm)
        cout << i << " ";
    return 0;
}