#include<bits/stdc++.h>
using namespace std;

//using recursion

int fibonacci(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);

}

int main()
{
    int n = 10;
    cout << "The recursive fibonacci is: \n";
    for(int i = 0; i < n; i++)
        cout << fibonacci(i) << " ";

    //using dynamic programming
    vector<int> F = {0, 1};
    
    for(int i = 2; i < n; i++)
        F.push_back(F[i - 1] + F[i - 2]);

    cout << "\nThe Dynamic programming Fibonacci is: \n";

    for(int i = 0; i < n; i++)
        cout << F[i] << " ";
    return 0;
}