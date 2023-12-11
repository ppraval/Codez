#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v_in = {9, 0, 2, 3, 4, 7, 1, 5, 8};
    vector<int> v_odd;
    vector<int> v_even;
    for(int i = 0; i < v_in.size(); i++)
    {
        if(v_in[i] % 2 == 0)
        {
            v_even.push_back(v_in[i]);
        }
        else
        {
            v_odd.push_back(v_in[i]);
        }
    }
    sort(v_even.begin(), v_even.end());
    sort(v_odd.begin(), v_odd.end());

    cout << "The even elements in sorted order are\n";
    for(int i = 0; i < v_even.size(); i++)
        cout << v_even[i] << " ";
    cout << "\n" << "The odd elements in sorted order are\n";
    for(int i = 0; i < v_odd.size(); i++)
        cout << v_odd[i] << " ";
    return 0;
}