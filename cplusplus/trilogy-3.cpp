#include<bits/stdc++.h>
using namespace std;

vector<int> addHI(vector<int>& a, vector<int>& b) 
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> res;
    int carry = 0, i = 0;
    
    while(i < a.size() || i < b.size() || carry) 
    {
        int sum = carry;
        if (i < a.size()) 
            sum += a[i];
        if (i < b.size()) 
            sum += b[i];
        // cout << sum << endl;
        res.push_back(sum % 10000);
        carry = sum / 10000;
        i++;
    }

    while(res.size() > 1 && res.back() == 0) 
    {
        res.pop_back();
    }

    reverse(res.begin(), res.end());
    return res;
}

int main() 
{
    vector<int> a = {9876, 5432, 1999};
    vector<int> b = {1, 8001};
    vector<int> result = addHI(a, b);
    for (int num : result) 
    {
        cout << num << " ";
    }
    return 0;
}
