#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {19,19,19,19,19,19,19,19,19,19,19,19,19};
    unordered_map<int, int> umap;
    int count = 0;
    for(auto i : nums)
    {
        umap[i]++;
    }
    for(auto i : umap)
        cout << i.first << " " << i.second << endl;
    for(auto i : umap)
    {
        int n = i.second;
        if(n == 1)
        {
            cout << -1;
            return 0;
        }
        while(n != 0)
        {
            if(n % 3 == 0)
            {
                count++;
                cout << "The count is = " << count << endl;
                n -= 3;
                cout << "The value of n is = " << n << endl;
            }
            else if(n % 2 == 0)
            {
                count++;
                cout << "The count is = " << count << endl;
                n -= 2;
                cout << "The value of n is = " << n << endl;
            }
        }
    }
    cout << count << endl;
    return 0;
}

// Completely correct code
// unordered_map<int,int> mp;
// for(auto i: nums)
// {
//     mp[i]++;
// }

// int count = 0;
// for(auto i: mp)
// {
//     int n = i.second;
//     if(n == 1)
//         return -1;
//     count += n / 3;
//     if(n % 3)
//         count++;
// }
// return count;
