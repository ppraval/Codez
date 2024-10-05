#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aeiou";
    int k = 0;
    int i = 0;
    int start = 0;
    int count = 0;
    int res = 0;
    unordered_map<char, int> mp;
    for(int j = 0; j < s.length(); j++)
    {
        if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
        {
            mp[s[j]]++;
        }
        else
        {
            count++;
        }
        cout << j << endl;
        cout << "count 1 = " << count << endl;
        while(i < j && count > k)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
            {
                mp[s[i]]--;
            }
            else
            {
                count--;
            }
            i++;
            start = i;
        }
        cout << "i = " << i << endl;
        cout << "start = " << start << endl;
        cout << "Count 2 = " << count << endl;
        while((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') && mp[s[i]] > 1)
        {
            mp[s[i]]--;
            i++;
        }
        if(count == k)
            cout << "She is so cute" << endl;
        if(mp['a'] && mp['e'] && mp['i'] && mp['o'] && mp['u'] && count == k)
        {
            res++;
            res += i - start;
        }
    }    
    cout << res;
    return 0;
}