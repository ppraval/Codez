#include<bits/stdc++.h>
using namespace std;

// int main()
// {
//     string s = "weallloveyou";
//     int k = 7;
//     int true_count = 0;
//     for(int i = 0; i + k < s.size(); i++)
//     {
//         int count = 0;
//         cout << "i : " << i << ", k : " << i + k << "\n";
//         for(int j = i; j < i + k; j++)
//         {
//             cout << "j : " << j << " ";
//             if(s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
//             {
//                 count++;
//                 cout << "\nThe count is " << count << "\n";
//             }
//             true_count = max(true_count, count);
//             cout << "The true count is " << true_count << "\n";
//         }
//     }
//     cout << "The max count is: " << true_count; 
//     return 0;
// }

//better code

bool isVowel(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u') return true;
    return false;
}

int main() 
{
    string s = "weallloveyou"; int k = 7;
    int ans = INT_MIN; int count = 0;
    int n = s.length();
    for(int i=0;i<k;i++) 
        if(isVowel(s[i]))
            count++;

    ans = max(ans, count);
    for(int i = 1; i < n - k + 1; i++){
        if(isVowel(s[i-1])) 
            count--;
        if(isVowel(s[i+k-1]))  
            count++;
        ans = max(ans, count);
    }
    cout << "The ans is " << ans;
    return ans;
}