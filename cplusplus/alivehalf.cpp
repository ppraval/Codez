#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "textbook";
    int n = s.length();
    unordered_map<char, int> ump1;
    unordered_map<char, int> ump2;
    for(int i = 0; i < n / 2; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            ump1[s[i]]++;
    }
    for(int i = n / 2; i < n; i++)
    {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            ump2[s[i]]++;
    }
    int count1 = 0, count2 = 0;
    for(auto i : ump1)
    {
        count1 += i.second;
    }
    for(auto i : ump2)
    {
        count2 += i.second;
    }
    if(count1 != count2)
    {
        cout << false;
        return false;
    }
    cout << true;
    return true;
}