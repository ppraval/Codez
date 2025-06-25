#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "abcde";
    string goal = "abced";
    int n = s.size();
    if (n != goal.size()) {
        cout << "false" << endl;
        return 0;
    }
    string doubled = s + s;
    if (doubled.find(goal) != string::npos) 
    {
        cout << "true" << endl;
    } 
    else 
    {
        cout << "false" << endl;
    }
    return 0;
}