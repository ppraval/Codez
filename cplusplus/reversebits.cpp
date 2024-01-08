#include<bits/stdc++.h>
using namespace std;

int main()
{
    uint32_t n = 1234567890;
    string s = to_string(n);
    reverse(s.begin(), s.end());
    cout << s << endl;
    uint32_t u = static_cast<uint32_t>(std::stoul(s));
    cout << "the int is = " << u << endl;
    return 0;
}