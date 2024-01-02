#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> n = {1,2,3};
    int val = 0;
    for(int i = 0; i < n.size(); i++)
    {
        val = val * 10 + n[i];
    }
    val++;
    cout << val << endl;
    vector<int> res;
    string s = to_string(val);
    for(int i = 0; i < s.length(); i++)
    {
        res.push_back(s[i] - '0');
    }
    for(int i = 0; i < res.size(); i++)
        cout << res[i] << " ";
    return 0;
}


// better solution might be as i dont like to admit
// class Solution {
// public:
//     vector<int> plusOne(vector<int>& v) {
//         int n = v.size();
//         for(int i = n-1; i >= 0; i--){
//             if(i == n-1)
//                 v[i]++;
//             if(v[i] == 10){
//                 v[i] = 0;
//                 if(i != 0){
//                     v[i-1]++;
//                 }
//                 else{
//                     v.push_back(0);
//                     v[i] = 1;
//                 }
//             }
//         }
//         return v;
//     }
// };