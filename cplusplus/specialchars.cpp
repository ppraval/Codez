#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aaAbcBC";
    set<char> s1;
    set<char> s2;
    int count = 0;
    for(char ch : s)
    {
        if(ch <= 'z' && ch >= 'a')
        {
            s1.insert(ch);
        }
        else if(ch <= 'Z' && ch >= 'A')
        {
            s2.insert(ch);
        }
    }
    for(char ch : s1)
        cout << ch << " ";
    cout << endl;
    for(char ch : s2)
        cout << ch << " ";
    cout << endl;
    for(char ch : s1)
    {
        cout << ch << " ";
        cout << s2.find(ch);
        if(s2.find(ch) != s2.end())
        {
            cout << "Pain" << endl;
            count++;
        }
    }
    cout << count << endl;
    return count;

}