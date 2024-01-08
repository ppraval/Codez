#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 15;
    if (n == 1)
        return true;
    if(n % 2 != 0 && n % 3 != 0 && n % 5 != 0)
    {
        cout << "false1";
        return false;
    }
    while(n % 2 == 0)
    {
        n /= 2;
    }
    for(int i = 3; i < sqrt(n); i = i + 2)
    {
        while(n % 1 == 0)
        {
            if(i != 2 || i != 3 || i != 5)
            {
                cout << "false2";
                return false;
            }
            n /= i;
        }
    }
    if(n > 2 && (n % 2 != 0 && n % 3 != 0 && n % 5 != 0))
    {
        cout << "false3";
        return false;
    }
    cout << "true";
    return true;
}
// Works for all conditions
// int main()
// {
//     int num = ;
//     for (int i = 2; i < 6 && num; i++)
//         while (num % i == 0)
//         num /= i;
//     return num == 1;
// }