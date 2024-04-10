#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> deck = {17,13,11,2,3,5,7};
    sort(deck.begin(), deck.end());
    int n = deck.size();
    vector<int> res(n);
    deque<int> indices;

    for(int i = 0; i < n; i++)
    {
        indices.push_back(i);
    }

    for(int card : deck)
    {
        int i = indices.front();
        indices.pop_front();
        res[i] = card;
        if(!indices.empty())
        {
            indices.push_back(indices.front());
            indices.pop_front();
        }
    }
    for(int i : res)
        cout << i << " ";
    return 0;
}