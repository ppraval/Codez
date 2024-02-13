#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> words = {"abc","car","ada","racecar","cool"};
    for(int i = 0; i < words.size(); i++)
    {
        string s = words[i];
        reverse(s.begin(), s.end());
        if(s == words[i])
        {
            cout << s << endl;
            return 0;
        }
    }
    cout << "" << endl;
    return 0;
}