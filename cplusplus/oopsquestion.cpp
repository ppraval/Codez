#include<bits/stdc++.h>
using namespace std;

class pain
{
    public:
        void f(int i) {cout << i << endl;}
};

class mypain : public pain
{
    public:
        void f(int i) {cout << 2 * i << endl;}
};

int main()
{
    pain *x = new mypain();
    
    return 0;
}