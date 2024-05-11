#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "fabccddg";
    unordered_map<char, int> freq;
    for(char ch : s)
    {
        freq[ch]++;
    }
    int count = 0, ans = 0;
    for(char ch : s)
    {
        freq[ch]--;
        if(freq[ch] == 0)
        {
            count++;
        }
        if(count == freq.size())
        {
            ans++;
            count = 0;
        }
    }
    cout << ans << endl;
    return 0;
}