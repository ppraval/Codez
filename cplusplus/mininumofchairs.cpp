#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "EEEEEEE";
    int max_chairs = 0, curr_chairs = 0;
    for(char c : s)
    {
        if(c == 'E')
        {
            curr_chairs++;
            max_chairs = max(curr_chairs, max_chairs);
        }
        else if(c == 'L')
        {
            curr_chairs--;                
        }
    }
    cout << max_chairs<< endl;
    return max_chairs;   
}