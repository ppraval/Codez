#include<bits/stdc++.h>
using namespace std;

class pain
{
    public:
        string s;
        pain() : s("I LOVE THIS GUN\n") {cout << "pain" << endl;}
        pain(string t) : s(t) {cout << "pain x2" << endl;}

        void morePain(int p)
        {
            cout << "I have a " << p << " long rod shoved up my" << endl;
        }
};

int main()
{
    pain pain1;
    // pain1.s = "I am in so much pain";
    cout << pain1.s;
    pain1.morePain(10);
    return 0;
}