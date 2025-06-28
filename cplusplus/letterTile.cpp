#include<bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if(n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    string s = "AAB";
    string temp = "";
    set<string> permutations;
    for(char c : s)
    {
        temp += c;
        int n = temp.size();
        int fact = factorial(n);
        while(fact--)
        {
            next_permutation(temp.begin(), temp.end());
            permutations.insert(temp);
        }
    }
    cout << permutations.size() << endl;
    for(const string& perm : permutations)
    {
        cout << perm << endl;
    }
    return 0;
}