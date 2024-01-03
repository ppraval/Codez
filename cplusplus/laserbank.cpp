#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> bank = {"000","111","000"};
    int previous_count = 0;
    int res = 0;
    for(int i = 0; i < bank.size(); i++)
    {   
        int current_count = 0;
        for(int j = 0; j < bank[i].length(); j++)
        {
            if(bank[i][j] == '1')
                current_count++;
        }
        res += previous_count * current_count;
        if(current_count !=  0)
            previous_count = current_count;
    }
    cout << res;
    return 0;
}