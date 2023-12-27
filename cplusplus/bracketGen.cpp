#include <bits/stdc++.h>
using namespace std;


void generateParenthesisHelper(int n, int open, int close, string s, vector<string>& result) {
    if (open == n && close == n) 
    {
        result.push_back(s);
        return;
    }
    if (open < n) 
    {
        generateParenthesisHelper(n, open + 1, close, s + "(", result);
    }
    if (close < open) 
    {
        generateParenthesisHelper(n, open, close + 1, s + ")", result);
    }
}


int main()
{
    int n = 3;
    vector<string> res;
    string s = "";
    generateParenthesisHelper(n, 0, 0, s, res);
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}