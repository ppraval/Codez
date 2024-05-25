#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> queries = {{1,4}, {2, 5}, {1,3}, {3, 4}};
    int limit = 4;
    unordered_map<int, int> ballColors; 
    unordered_map<int, int> colorCount; 
    vector<int> result;

    for (const auto& query : queries) 
    {
        int ball = query[0];
        int color = query[1];

        if (ballColors.find(ball) != ballColors.end()) 
        {
            colorCount[ballColors[ball]]--;
            if (colorCount[ballColors[ball]] == 0) 
            {
                colorCount.erase(ballColors[ball]);
            }
        }

        ballColors[ball] = color;
        colorCount[color]++;
        result.push_back(colorCount.size());
    }
    for(int i : result)
    cout << i << " ";
    return 0;
}