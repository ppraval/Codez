#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "My name is Haley";
    string s2 = "My Haley";
    deque<string> q1, q2;
    for(int i = 0; i < s1.length(); i++)
    {
        int j = i;
        string temp = "";
        while(j < s1.length() && s1[j] != ' ')
        {
            temp += s1[j++];
        }
        i = j;
        q1.push_back(temp);
    }
    for(int i = 0; i < s2.length(); i++)
    {
        int j = i;
        string temp = "";
        while(j < s2.length() && s2[j] != ' ')
        {
            temp += s2[j++];
        }
        i = j;
        q2.push_back(temp);
    }
    while(!q1.empty() && !q2.empty())
    {
        if(q1.front() != q2.front())
        {
            break;
        }
        q1.pop_front();
        q2.pop_front();
    }

    while(!q1.empty() && !q2.empty())
    {
        if(q1.back() != q2.back())
        {
            break;
        }
        q1.pop_back();
        q2.pop_back();
    }
    if(q1.empty() || q2.empty())
    {
        cout << true;
        return true;
    }
    cout << false;
    return 0;
}