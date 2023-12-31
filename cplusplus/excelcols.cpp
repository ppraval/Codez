#include<bits/stdc++.h>
using namespace std;

int main()
{
    // LESGOOOO I READ THE QUESTION WRONG THIS IS EPIC MORE MARKS ARE GONE AHAHAHAHHAHAHAH
    // NVM THIS WAS USED IN ANOTHER QUESTION I AM NOT SCHIZO
    // string s = "ZY";
    // int val = 0;
    // for(int i = 0; i < s.length(); i++)
    // {
    //     val = (val * 26) + (s[i] - 'A' + 1); 
    // }
    // cout << val << endl;
    // return 0;
    int x = 701;
    string res = "";
    while(x > 0)
    {
        x--;
        int val = x % 26;
        x /= 26;
        res.push_back(val + 'A');
    }
    reverse(res.begin(), res.end());
    cout << res;
    return 0;
}