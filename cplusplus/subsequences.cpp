#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(string input, string output) {
    // Base Case: If the input is empty, print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    // Include the first character of the input string
    printSubsequence(input.substr(1), output + input[0]);
    // Exclude the first character of the input string
    printSubsequence(input.substr(1), output);
}

int main() {
    string output = "";
    string input = "abcd";
    cout << "I love this gun = " << input.substr(1) << endl;
    printSubsequence(input, output);
    return 0;
}
