#include<bits/stdc++.h>
using namespace std;

class karthik
{
    public:
        string s;
        void pain() {cout << "Kathik is thope" << endl;}
};

int main()
{
    karthik* k = new karthik();
    karthik vivek;
    vivek.pain();
    k->s = "She left me";
    cout << k->s << endl;
    k->pain();
    return 0;
}