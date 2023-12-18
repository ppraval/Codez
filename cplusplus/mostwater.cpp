#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int>height = {1,8,6,2,5,4,8,3,7};
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) 
    {
        int current_area = min(height[left], height[right]) * (right - left);
        max_area = max(max_area, current_area);

        if (height[left] < height[right]) 
        {
            left++;
        } 
        else 
        {
            right--;
        }
    }
    cout << "The max area is: " << max_area;
    return 0;
}