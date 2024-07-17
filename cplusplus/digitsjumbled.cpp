#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "owoftnuoer";
    vector<int> arr(10);
    for (int i = 0; i < s.length(); i++) 
    {
        if (s[i] == 'z')
            arr[0]++;
        if (s[i] == 'w')
            arr[2]++;
        if (s[i] == 'g')
            arr[8]++;
        if (s[i] == 'x')
            arr[6]++;
        if (s[i] == 'v')
            arr[5]++;
        if (s[i] == 'o')
            arr[1]++;
        if (s[i] == 's')
            arr[7]++;
        if (s[i] == 'f')
            arr[4]++;
        if (s[i] == 'h')
            arr[3]++;
        if (s[i] == 'i')
            arr[9]++;
    }
    arr[7] -= arr[6];
    arr[5] -= arr[7];
    arr[4] -= arr[5];
    arr[3] -= arr[8];
    arr[1] -= (arr[2] + arr[4] + arr[0]);
    arr[9] -= (arr[5] + arr[6] + arr[8]);
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == 1)
            sum += i;
    }
    cout << sum << endl;
    return 0;
}