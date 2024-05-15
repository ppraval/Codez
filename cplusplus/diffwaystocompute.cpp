#include<bits/stdc++.h>
using namespace std;

int calc(int a, int b, char ch)
{
    if(ch == '+')
        return a + b;
    if(ch == '-')
        return a - b;
    if(ch == '*')
        return a * b;
    return 0;
}

vector<int> diffWaysToCompute(string s)
{
    bool no_calc = true;
    vector<int> ans;
    for(int i = 0; i < s.length(); i++)
    {
        if(!isdigit(s[i]))
        {
            no_calc = false;
            vector<int> left = diffWaysToCompute(s.substr(0, i));
            vector<int> right = diffWaysToCompute(s.substr(i + 1));
            for(int x : left)
            {
                for(int y : right)
                {
                    int val = calc(x, y, s[i]);
                    ans.push_back(val);
                }
            }
        }
    }
    if(no_calc == true)
        ans.push_back(stoi(s));
    return ans;
}

int main()
{
    string s = "2-1-1";
    vector<int> ans = diffWaysToCompute(s);
    for(int i : ans)
        cout << i << " ";
    return 0;
}