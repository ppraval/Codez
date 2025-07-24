#include<bits/stdc++.h>
using namespace std;


int main()
{
    vector<int> v = {1, 1, 3, 4};
    int n = v.size();
    int k = 3;
    int min_diff = abs(*max_element(v.begin(), v.end()) - *min_element(v.begin(), v.end()));
    while(k--)
    {
        auto min_it = min_element(v.begin(), v.end());
        auto max_it = max_element(v.begin(), v.end());
        *min_it += 1;
        *max_it -= 1;
        min_it = min_element(v.begin(), v.end());
        max_it = max_element(v.begin(), v.end());
        int diff = abs(*max_it - *min_it);
        cout << "diff = " << diff << endl;
        min_diff = min(min_diff, diff);
        for(int i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << "Minimum difference: " << min_diff << endl;
    return 0;
}