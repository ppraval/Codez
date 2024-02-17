#include<bits/stdc++.h>
using namespace std;


int main()
{
    string s = "capiTalIze tHe titLe";
    transform(s.begin(), s.end(), begin(s), :: tolower);
    string ans = "";
    stringstream ss(s);
    string word;
    
    while(ss >> word)
    {
        
        if(word.size() > 2)
        {
            word[0] = toupper(word[0]);
        }
        ans += word;
        ans += ' ';
    }
    ans.pop_back();
    cout << ans << endl;
    return 0;
}