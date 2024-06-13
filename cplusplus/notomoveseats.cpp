#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> seats = {3,1,5};
    vector<int> stu = {2,7,4};
    int sum = 0;
    sort(seats.begin(), seats.end());
    sort(stu.begin(), stu.end());
    for(int i = 0; i < stu.size(); i++)
    {
        sum += abs(seats[i] - stu[i]);
    }
    cout << sum << endl;
    return sum;
}