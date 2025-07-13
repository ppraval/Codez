#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        unordered_set<string> ban(forbidden.begin(), forbidden.end());
        int maxLen = 0;
        int j = word.size();

        for (int i = word.size() - 1; i >= 0; i--) 
        {
            for (int k = i; k < min(i + 10, j); k++) 
            {
                string sub = word.substr(i, k - i + 1);
                if (ban.count(sub)) 
                {
                    j = k;
                    break;
                }
            }
            maxLen = max(maxLen, j - i);
        }

        return maxLen;
    }
};

int main() {
    Solution sol;

    string word1 = "cbaaaabc";
    vector<string> forbidden1 = {"aaa", "cb"};
    cout << sol.longestValidSubstring(word1, forbidden1) << endl; // Output: 4

    string word2 = "leetcode";
    vector<string> forbidden2 = {"de", "le", "e"};
    cout << sol.longestValidSubstring(word2, forbidden2) << endl; // Output: 4

    return 0;
}