#include<bits/stdc++.h>
using namespace std;

class myPain
{
    public :
        void sub(int a, int b)
        {
            cout << a - b << endl;
        }

        void sub(double a, double b)
        {
            cout << double(a - b) << endl;
        }
};

class opPain
{
    private:
        int real, img;
    public:
        opPain(int r = 0, int i = 0)
        {
            real = r;
            img = i;
        }

        opPain operator+(opPain const& obj)
        {
            opPain res;
            res.real = real + obj.real;
            res.img = img + obj.img;
            return res;
        }

        void print()
        {
            cout << real << " + i" << img << endl;
        }
};

int main()
{
    myPain p1;
    p1.sub(1, 2);
    p1.sub(1.3, 0.29);
    cout << "-----------" << endl;
    
    opPain p2(10, 5), p3(2,4);
    
    opPain p4 = p2 + p3;
    p4.print();
    return 0;
}