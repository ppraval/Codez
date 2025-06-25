#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> r = {9,29,49,50};
    string s = "cbcd";
    int n = s.size();
    int max_diff = r[0];
    char slowest = s[0];
    for(int i = 0; i + 1 < n; i++)
    {
        int diff = r[i + 1] - r[i];
        if(diff >= max_diff)
        {
            max_diff = diff;
            slowest = s[i + 1];
        }
    }
    cout << "Slowest character: " << slowest << endl;
    cout << "Maximum difference: " << max_diff << endl;
    return 0;
}