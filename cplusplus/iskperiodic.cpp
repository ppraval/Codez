#include<bits/stdc++.h>
using namespace std;

int main()
{
    string word = "leetcodeleet";
    int k = 4;
    unordered_map<string, int> frequency;
    int max_frequency = 0;
    for (int i = 0; i < word.length(); i += k) 
    {
        string chunk = word.substr(i, k);
        frequency[chunk]++;
        max_frequency = max(max_frequency, frequency[chunk]);
    }
    cout << (word.length() / k) - max_frequency; 
    return (word.length() / k) - max_frequency;
}