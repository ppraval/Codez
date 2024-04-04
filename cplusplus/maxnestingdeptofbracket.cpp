#include<bits/stdc++.h>
using namespace std;

int main()
{   
    string s = "(1+(2*3)+((8)/4))+1";
    int count = 0;
    int max_num = 0;
    for (char c : s) 
    {
        if (c == '(') 
        {
            count++;
            if(max_num < count)
                max_num = count;
        } 
        else if (c == ')') 
        {
            count--;
        }
    }
    cout << max_num << endl;
    return max_num;
}