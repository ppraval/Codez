#include<bits/stdc++.h>
using namespace std;

int main()
{
    string word = "abcdefd";
    char ch = 'd';
    int i = 0;
    for(; i < word.size(); i++)
    {
        if(word[i] ==  ch)
        {
            break;
        }
    }
    reverse(word.begin(), word.begin() + i + 1);
    cout << word << endl;
    return 0;
}