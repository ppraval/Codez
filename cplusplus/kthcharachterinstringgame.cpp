#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k = 10;
    string s = "a";
    int val = 0;
    int i = 0;
    int count = 0;
    while(s.length() < k)
    {
        i = 0;
        string temp = "";
        while(i < s.length())
        {
            val = s[i] - 'a';
            if(val == 25)
                val = 0;
            else
                val++;
            temp += val + 'a';
            cout << "t = " << temp << endl;
            i++;
        }
        s += temp;
        cout << "s = " <<  s << endl;
        // count++;
        // if(count == 5)
        //     break;
    }
    cout << s << endl;
    cout << s[k - 1] << endl;
    return 0;
}