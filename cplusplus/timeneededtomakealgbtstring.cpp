#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abaac";
    vector<int> neededTime = {1,2,3,4,5};
    int count = 0;
    for(int i = 0; i + 1 < s.length(); i++)
    {
        if(s[i] == s[i + 1])
            count += min(neededTime[i + 1], neededTime[i]);
    }
    cout << count;
    return 0;
}