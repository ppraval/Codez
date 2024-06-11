#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> temp, arr;
    unordered_map<int, int> mp;
    for(int i = 0; i < arr2.size(); i++)
        mp[arr2[i]] = i;
    for(int i = 0; i < arr1.size(); i++)
    {
        if(mp.find(arr1[i]) == mp.end())
        {
            temp.push_back(arr1[i]);
        }
        else
        {
            arr.push_back(arr1[i]);
        }
    }
    arr1 = arr;
    for(int j = 1; j < arr1.size(); j++)
    {
        int key = arr1[j];
        int i = j - 1;
        while(i >= 0 && mp[arr1[i]] > mp[key])
        {
            arr1[i + 1] = arr1[i];
            i = i - 1;
        }
        arr1[i + 1] = key;
    }
    sort(temp.begin(), temp.end());
    for(int i : temp)
        arr1.push_back(i);
    for(int i : arr1)
        cout << i << " ";
    return 0;
}