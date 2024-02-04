#include<bits/stdc++.h>
using namespace std;

int main()
{
    int area = 4;
    int m = sqrt(area);
    while(area % m != 0)
    {
        m--;
    }
    cout << area / m << " " << m;
    return 0;
}