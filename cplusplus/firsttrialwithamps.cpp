#include<bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<int, string> ump;
    ump[89] = "Maa";
    ump[21] = "anayya";
    ump[14523] = "thope";
    for(auto x : ump)
        cout << x.first << " " << x.second << endl;
    return 0;
}