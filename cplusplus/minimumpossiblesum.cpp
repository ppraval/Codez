#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 2;
    int target = 3;
    long long sum = 0;
    set<int> s;
    int i = 1;
    int count = 0;
    while(count != n)
    {
        if(s.count(target - i))
        {
            i++;
            continue;
        }
        sum += i;
        s.insert(i);
        i++;
        count++;
    }
    cout << sum << endl;
    return 0;
}