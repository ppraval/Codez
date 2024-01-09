#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> letters = {'c', 'f', 'j'};
    char target = 'c';
    for(auto c : letters)
    {
        if(c > target)
        {
            cout << c << endl;
            return 0;
        }
    }
    return 0;
}