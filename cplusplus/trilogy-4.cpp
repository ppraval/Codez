#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) 
{
    return b == 0 ? a : gcd(b, a % b);
}

void reduceFrac(int &numera, int &denomi) 
{
    int gcd_num = gcd(numera, denomi);
    numera /= gcd_num;
    denomi /= gcd_num;
}

string addFrac(string frac) 
{
    int X, Y, U, V;
    char temp;
    stringstream ss(frac);
    ss >> X >> temp >> Y >> temp >> U >> temp >> V;

    int denomi = Y * V;
    int numera = X * V + U * Y;

    reduceFrac(numera, denomi);
    return to_string(numera) + "/" + to_string(denomi);
}

int main() 
{
    vector<string> fractions = {"2/6+2/6", "7/10+13/10"};
    vector<string> res;
    for(auto x : fractions)
    {
        res.push_back(addFrac(x));
    }
    for (string x : res) 
    {
        cout << x << " ";
    }
    return 0;
}
