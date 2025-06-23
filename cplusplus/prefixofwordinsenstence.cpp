#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s = "i love eating burger"; 
    string word = "burg";
    stringstream ss(s);
    string temp;
    int count = 1;  
    while(ss >> temp) 
    { 
        if(temp.find(word) == 0) 
        {
            // cout << "The word '" << word << "' is a prefix of the word '" << temp << "' in the sentence." << endl;
            return count;
        }
        count++;
    }   
    return 0;
}