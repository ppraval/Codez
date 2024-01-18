#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> pushed = {1,2,3,4,5};
    vector<int> popped = {4,5,3,2,1};
    int i = 0; 
    int j = 0; 
    for(auto val : pushed)
    {
        pushed[i++] = val;
        while(i > 0 && pushed[i - 1] == popped[j])
        { 
            i--; 
            j++;
        }
    }
    if(i == 0)
        cout << "true";
    else
        cout << "false";
    return i == 0;
}