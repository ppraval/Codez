#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    int startingPosition = -1, endingPosition = -1;
    int n = nums.size();
    for(int i=0; i<n; i++){
        if(nums[i] == target){
            startingPosition = i;
            break;
        }
    }
    for(int i=n-1; i>=0; i--){
        if(nums[i] == target){
            endingPosition = i;
            break;
        }
    }
    cout << startingPosition << " " << endingPosition << endl;
    return 0;

}