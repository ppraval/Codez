#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, -10};
    int k = 15;
    for(int i = 0; i < arr.size(); i++)
    {
        cout << "i=" << i << endl;
        for(int j = i; j < arr.size(); j++)
        {
            cout << "j=" << j << endl;   
            int sum = 0;
            for(int l = i; l <= j; l++)
            {
                cout << "i = " << i << endl;
                cout << "j = " << j << endl;
                cout << "l = " << l << endl;
                sum += arr[l];
                cout << "arr[l] = " << arr[l] << endl;
            }
            if (sum == k)
            {
                int length;
                length = max(length, j - i + 1);
                cout << "i = " << i << endl;
                cout << "j = " << j << endl;
                cout << "length = " << length << endl;
                return length;
            }
        }
    }
    return 0;
}