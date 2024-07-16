#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool isPalindrome(const std::string& s) {
    int i = 0, j = s.length() - 1;
    while (i <= j) {
        if (s[i] != s[j])
            return false;
        i++;
        j--;
    }
    return true;
}

void generateSubsequences(const std::vector<std::string>& v, std::string current, int index, std::vector<std::string>& ans) {
    if (index == v.size()) {
        ans.push_back(current);
        return;
    }
    generateSubsequences(v, current + v[index], index + 1, ans);
    generateSubsequences(v, current, index + 1, ans);
}

int main() {
    std::vector<std::string> v = {"ab", "ba", "xyx", "de"};
    std::vector<std::string> ans;
    generateSubsequences(v, "", 0, ans);

    int maxLen = 0;
    for (const auto& subseq : ans) {
        std::cout << subseq << std::endl;
        if (isPalindrome(subseq)) {
            int len = subseq.length();
            std::cout << "Palindrome: " << subseq << " (Length: " << len << ")" << std::endl;
            maxLen = std::max(maxLen, len);
        }
    }

    std::cout << "Maximum palindrome length: " << maxLen << std::endl;
    return 0;
}
