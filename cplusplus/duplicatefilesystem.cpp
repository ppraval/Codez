#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<string> v = {"root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"};
    // for(auto x : v)
    //     cout << x << endl;
    string directory;
    for(auto x : v)
    {
        stringstream ss(x);
        while(ss >> directory)
        {
            string file;
            ss >> file;
            size_t pos = file.find('(');
            if (pos != string::npos) {
                string content = file.substr(pos + 1, file.size() - pos - 2);
                cout << "Directory: " << directory << ", File: " << file.substr(0, pos) << ", Content: " << content << endl;
            }
        }
    }
    return 0;
}