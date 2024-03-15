#include<bits/stdc++.h>
using namespace std;

int isVowel(char ch)
{
    if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' || ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
        return 1;
    return 0;
}


int main()
{
    string s = "lEetcOde";
    vector<int> index;
    vector<char> vowel;
    for(int i = 0; i < s.size(); i++) 
    {
        if(isVowel(s[i])) 
        {
            index.push_back(i);
            vowel.push_back(s[i]);
        }
    }
    sort(vowel.begin(), vowel.end());
    for(int i = 0; i < index.size(); i++) 
    {
        s[index[i]] = vowel[i];
    }
    cout << s << endl;
    return 0;
}