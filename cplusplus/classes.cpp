#include<bits/stdc++.h>
using namespace std;

class pain
{
    public:
        string s;
        pain() : s("I LOVE THIS GUN") {cout << "I hate this life" << endl;}
        pain(string t) : s(t) {cout << "I hate this life x2" << endl;}
};

int main()
{
    pain pain1 = new pain();
    // pain1.s = "I am in so much pain";
    cout << pain1.s;
    return 0;
}