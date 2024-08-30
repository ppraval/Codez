#include<bits/stdc++.h>
using namespace std;

void assign(int *p)
{
    p = (int*)malloc(sizeof(int));
    *p = 10;
    cout << *p << endl;
}

int main()
{
    int p;
    assign(&p);

    int *q;
    q = new int(10);
    cout << *q << endl;
    // cout << p;
    return 0;
}