#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> candies = {12, 1, 10};
    int extra_candies = 10;
    vector<bool> greatest_candies = {};
    int max_candies = *max_element(candies.begin(), candies.end());
    for (int i = 0; i < candies.size(); i++)
    {
        if(candies[i] + extra_candies > max_candies)
        {
            greatest_candies.push_back(true);
        }
        else
        {
            greatest_candies.push_back(false);
        }
    }
    for(int i = 0; i < greatest_candies.size(); i++)
    {
        cout << greatest_candies[i] << " ";
    }
    return 0;

}