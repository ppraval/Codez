#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "IIIDIDDD";
    stack<int> st;
    string res = "";
    int n = s.size();
    for(int i = 0; i <= n; i++)
    {
        st.push(i + 1);
        if(i == n || s[i] == 'I')
        {
            while(!st.empty())
            {
                res += to_string(st.top());
                st.pop();
            }
        }
    }
    cout << res << endl;
    return 0;
}