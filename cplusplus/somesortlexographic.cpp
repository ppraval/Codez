#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {1,2,3,4,5,6,7,8,9,10,11,12,13};
    vector<string> temp;
    for(int i : nums)
    {
        string s = to_string(i);
        temp.push_back(s);
    }
    sort(temp.begin(), temp.end());
    for(auto s : temp)
        cout << s << " ";
    return 0;
}