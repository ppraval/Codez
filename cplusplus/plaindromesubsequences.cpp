#include<bits/stdc++.h>
using namespace std;

bool palin(string s)
{
    int i = 0, j = s.length() - 1;
    while(i <= j)
    {
        if(s[i] != s[j])
        {
            return 0;
        }
        i++;
        j--;
    }
    return 1;
}

void printSubsequence(string input, string output, vector<string> &v) 
{
    if(input.empty()) 
    {
        v.push_back(output);
        return;
    }
    printSubsequence(input.substr(1), output + input[0], v);
    printSubsequence(input.substr(1), output, v);
}

int main()
{
    string s = "0100110";
    string temp = "";
    vector<string> v, vec;
    int count = 0;
    printSubsequence(s, temp, v);
    for(auto x : v)
    {
        if(x.size() == 5)
            vec.push_back(x);
    }
    for(auto x : vec)
    {
        if(palin(x))
        {
            count++;
        }
    }
    cout << count;
    return 0;
}