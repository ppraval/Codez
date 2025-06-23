#include<bits/stdc++.h>
using namespace std;

class Solution {
public: 
    bool canThreePartsEqualSum(vector<int>& arr) 
    {
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if (sum % 3 != 0) 
            return false;
        
        int target = sum / 3;
        int currentSum = 0, count = 0;

        for (int num : arr) 
        {
            currentSum += num;
            if (currentSum == target) 
            {
                count++;
                currentSum = 0; 
            }
        }

        return count >= 3; 
    }
};
// Example usage
int main() {            
    Solution sol;
    vector<int> arr = {0, 2, 1, -6, 6, -7, 9, 1, 2, 0, 1};
    bool result = sol.canThreePartsEqualSum(arr);
    cout << (result ? "True" : "False") << endl; // Output: True
    return 0;
}