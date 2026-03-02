#include<bits/stdc++.h>
using namespace std;

struct foo
{
    int* p;
    char* q;
};

int main()
{
    int a = 4;
    struct foo* f = (struct foo*)malloc(sizeof(struct foo));
    f->p = &a;
    f->q = (char*)malloc(20 * sizeof(char));
    strcpy(f->q, "hello");
    cout << *(f->p) << endl;
    cout << f->q << endl;
    return 0;
}