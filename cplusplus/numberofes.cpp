#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "geethameenakshi";
    char a = 'e';
    int count = 0;
    for(auto x : s)
    {
        if(x == a)

            count++;
    }
    cout << count << endl;
    return 0;
}