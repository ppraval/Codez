#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Let's take LeetCode contest";
    string ans = "";
    stringstream ss(s);
    string temp;
    cout << "the string is: "<< s << endl;
    // int abhi;
    // cin >> abhi;
    int i = 0;
    while(ss >> temp)
    {
        cout << i++ << endl;
        cout << temp << endl;
        reverse(temp.begin(), temp.end());
        ans += temp + " ";
    }
    ans.pop_back();
    cout << "Answer: " << endl;
    cout << ans << endl;
    return 0;
}