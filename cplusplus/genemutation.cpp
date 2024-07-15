#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "AACCTTGG";
    string e = "AATTCCGG";
    vector<string> b = {"AATTCCGG","AACCTGGG","AACCCCGG","AACCTACC"};
    queue<pair<string, int>> q;
    unordered_set<string> set;
    for(auto x : b)
    {
        set.insert(x);
    }
    q.push({s, 0});
    vector<char> v = {'A', 'T', 'G', 'C'};
    while(!q.empty())
    {
        string top = q.front().first;
        int count = q.front().second;
        q.pop();
        if(top == e)
        {
            cout << count;
            return 0;
        }
        for(int i = 0; i < top.size(); i++)
        {
            string temp = top;
            for(char ch : v)
            {
                top[i] = ch;
                if(set.find(top) != set.end());
                {
                    cout << "String hit = " << top << " and its count is " << count << endl;
                    q.push({top, count + 1});
                    set.erase(top);
                }
            } 
            top = temp;
        }
    }
    return 0;
}