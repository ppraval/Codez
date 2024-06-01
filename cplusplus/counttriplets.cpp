#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {2,3,1,6,7};
    int n = arr.size();
    int count = 0;
    vector<int> prefix(n + 1, 0);
    for(int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(prefix[i] == prefix[j + 1])
            {
                count += j - i;
            }
        }
    }
    cout << count << endl;
    return count;
}