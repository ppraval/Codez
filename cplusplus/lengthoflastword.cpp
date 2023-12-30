#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "day";
    int j = s.length() - 1;
    int count = 0, i;
    if(j == 0)
       return 1;
    for( ; j > 0; j--)
    {
         if( s[j] != ' ')
         {
              i = j;
              while(i != 0 && s[i - 1] != ' ')
              {
                  count++;
                  i--;
              }
              break;
              
         }
    }
    cout << count + 1;
    return count + 1;
}