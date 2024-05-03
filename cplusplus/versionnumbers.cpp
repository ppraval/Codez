#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s1 = "1.01", s2 = "1.001";
    int val = 0;
    vector<int> v1, v2;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == '.')
        {
            v1.push_back(val);
            val = 0;
            continue;
        }
        val = val * 10 + s1[i] - '0';
        // if(i = s1.size() -  1)
    }
    v1.push_back(val);
    val = 0;
    for(int i = 0; i < s2.size(); i++)
    {
        if(s2[i] == '.')
        {
            v2.push_back(val);
            val = 0;
            continue;
        }
        val = val * 10 + s2[i] - '0';
        // if(i = s2.size() -  1)
    }
    v2.push_back(val);
    int i = 0, j = 0;
    int m = v1.size() - v2.size();
    int n = min(v1.size(), v2.size());
    cout << m << " " << n << endl;
    while(i < v1.size() - 1 || j < v2.size() - 1)
    {
        cout << v1[i] << " " << v2[j] << endl;
        if(v1[i] < v2[j])
        {
            cout << -1;
            return 0;
        }
        if(v1[i] > v2[j])
        {
            cout << 1;
            return 0;
        }
        if(m > 0 && i >= n - 1)
        {
            cout << "fex" << endl;
            i++;
        }
        else if(m < 0 && j >= n - 1)
        {
            cout << "fesg" << endl;
            j++;
        }
        else
        {
            cout << "Pain" << endl;
            i++, j++;
        }
    }
    
    // for(int i : v1)
    //     cout << i << ". ";
    // cout << endl;
    // for(int i : v2)    
    //     cout << i << ". ";
    cout << 0 << endl;
    return 0;
}

// int main()
// {
//     string version1 = "1.0", version2 = "1.0.0";
//     int m = version1.size(), n = version2.size();
//     for (int i = 0, j = 0; (i < m) || (j < n); i++, j++) 
//     {
//         int value1 = 0, value2 = 0;
//         while ((i < m) && (version1[i] != '.')) 
//             value1 = value1 * 10 + (version1[i++] - '0');
//         while ((j < n) && (version2[j] != '.')) 
//             value2 = value2 * 10 + (version2[j++] - '0');
//         if (value1 < value2) 
//             return -1;
//         if (value1 > value2) 
//             return 1;
//     }
//     return 0;
// }