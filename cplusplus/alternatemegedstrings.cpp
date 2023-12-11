#include<bits/stdc++.h>
using namespace std;

int main()
{
    string word1 = "abc", word2 = "pqrst";
    int i = 0, j = 0, k = 0;
    string merged_word;
    
    // for(int h = 0; h < word1.length(); h++)
    //     cout << word1[h];
    // cout << "\n";
    // for(int h = 0; h < word2.length(); h++)
    //     cout << word2[h];    
    // cout << "\nWord2 has lenght " << word2.length() << "\n";

    //cout << "The values of i, j, k are " << i << " " << j << " " << k << "\n";
    while (i < word1.length() || j < word2.length())
    {
        cout << "The values of i and j are " << i << " " << j << "\n";
        // cout << "The string merged till now is " << merged_word << endl;
        if(i < word1.length())
        {
            merged_word[k++] = word1[i++];
            // cout << "Merged letter is " << merged_word[k - 1] << "\n";
        }
        if(j < word2.length())
        {
            merged_word[k++] = word2[j++];
            // cout << "Merged letter is " << merged_word[k - 1] << "\n";
        }
    }
    cout << "The merged string length is " << merged_word.size() << "\n";
    for(int l = 0; l < k; l++)
    {
        cout << merged_word[l];
    }
    return 0;
}