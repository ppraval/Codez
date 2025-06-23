#include<bits/stdc++.h>
using namespace std;

int main() 
{
    vector<string> result;
    bool inBlock = false;
    string newline;

    for (const string& line : source) 
    {
        int i = 0;
        if (!inBlock) newline.clear();

        while (i < line.size()) 
        {
            if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '/') {
                break; 
            } else if (!inBlock && i + 1 < line.size() && line[i] == '/' && line[i + 1] == '*') {
                inBlock = true;
                i += 2;
            } else if (inBlock && i + 1 < line.size() && line[i] == '*' && line[i + 1] == '/') {
                inBlock = false;
                i += 2;
            } else if (!inBlock) {
                newline += line[i++];
            } else {
                ++i; 
            }
        }

        if (!inBlock && !newline.empty()) {
            result.push_back(newline);
        }
    }
    return result;
}