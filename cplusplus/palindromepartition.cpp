#include<bits/stdc++.h>
using namespace std;

// Make this work somehow
bool isPalindrome(string s)
{
    cout << "All of the strings that are coming in are = " << s << endl;
    string s1 = s;
    reverse(s1.begin(), s1.end());
    return s1 == s;
}

void backtrack(string s, int i, vector<string>& substr, vector<vector<string>>& ans, int n)
{
    if(i == n)
    {
        ans.push_back(substr);
        return;
    }
    for(int j = i + 1; j <= n; j++)
    {
        // if(s.substr(i, j - 1) == "")
        //     continue;
        if(isPalindrome(s.substr(i, j - 1)))
        {
            cout << "The ones that are palindromes = " << s.substr(i, j - 1) << endl;
            cout << "The substrs are = " << s.substr(i, j - i) << endl << endl; 
            substr.push_back(s.substr(i, j - i));
            backtrack(s, j, substr, ans, n);
            substr.pop_back();
        }
    }
}

int main()
{
    string s = "aab";
    vector<string> substr;
    vector<vector<string>> ans;
    backtrack(s, 0, substr, ans, s.length());
    for(int i = 0; i < ans.size(); i++)
    {
        for(int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}